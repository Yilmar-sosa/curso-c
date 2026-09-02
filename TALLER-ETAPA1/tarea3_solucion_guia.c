/* ============ TAREA 3 (SOLUCION GUIA) ============
   COMPLETA Y COMENTADA linea por linea.
   ------------------------------------------------------------------
   QUE PIDE: imprimir una TABLA con el numero de estudiantes DISTINTOS
   matriculados en >=1 clase por semestre, divididos por:
   genero (H/M) y tipo (pregrado/posgrado).
   Columnas: Año | Semestre | H-pregrado | M-pregrado | H-posgrado | M-posgrado
   ------------------------------------------------------------------
   Records reales del archivo (verificado):
   - Estudiante: id(4) + flags(1, F=0x80 mujer, G=0x40 posgrado) + nombre(23) + edad(4)
   - Curso:      id(4) + nombre(32) + creditHours(4)   -> 40 bytes
   - Matricula:  studentID(4) + courseID(4) + year(4) + semester(4)
   ------------------------------------------------------------------
   EL RETO CLAVE: "estudiantes DISTINTOS".
   El enunciado (Consejos) dice: si un estudiante toma VARIAS clases en
   el MISMO semestre, se cuenta UNA sola vez.
   ------------------------------------------------------------------
   ESTRATEGIA para lo "distinto" (la parte importante):
   Recorro las matriculas UNA POR UNA (i).
   - Antes de contar la matricula i, pregunto: "¿esta matricula (mismo
     estudiante sid, mismo year, mismo sem) ya aparecio ANTES en las
     matriculas 0..i-1?"
     * Si YA aparecio  -> la SALTO (continue). No la cuento.
     * Si es la PRIMERA vez -> la cuento en su categoria.
   De esta manera el estudiante se cuenta solo en su primera aparicion
   dentro de (year, sem). Las demas clases iguales no suman.
   ------------------------------------------------------------------ */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Estructura de un estudiante guardado. */
typedef struct {
    uint32_t id;            /* identificador del estudiante */
    unsigned char flags;    /* byte: F=genero(0x80), G=posgrado(0x40) */
    char nombre[24];        /* nombre (no usado en la tabla) */
    uint32_t edad;          /* edad (no usada) */
} Estudiante;

/* Estructura de una matricula guardada. */
typedef struct {
    uint32_t sid;   /* studentID -> quien se matriculo */
    uint32_t year;  /* en que anio */
    uint32_t sem;   /* en que semestre */
} Matricula;

int main(int argc, char *argv[]){

    /* ---- 1) Verificar argumentos ----
       Solo necesitamos argv[0]=programa y argv[1]=archivo. => argc==2 */
    if(argc != 2){
        printf("Uso: %s <archivo.bin>\n", argv[0]);
        return 1;
    }

    /* ---- 2) Abrir archivo binario ---- */
    FILE *f = fopen(argv[1], "rb");
    if(f == NULL){
        printf("No se pudo abrir %s\n", argv[1]);
        return 1;
    }

    /* ---- 3) Leer ENCABEZADO (igual en las 3 tareas) ---- */
    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    fread(&magic,        sizeof(magic),        1, f);
    fread(&studentCount, sizeof(studentCount), 1, f);
    fread(&courseCount,  sizeof(courseCount),  1, f);
    fread(&enrollCount,  sizeof(enrollCount),  1, f);

    /* ---- 4) Guardar TODOS los estudiantes (id + flags) ----
       Luego necesito el genero y tipo de cada studentID. */
    Estudiante estudiantes[studentCount];

    for(uint32_t i = 0; i < studentCount; i++){
        fread(&estudiantes[i].id,    sizeof(uint32_t),     1, f);
        fread(&estudiantes[i].flags, sizeof(unsigned char),1, f);
        fread(estudiantes[i].nombre, 23, 1, f);
        estudiantes[i].nombre[23] = '\0';
        fread(&estudiantes[i].edad,  sizeof(uint32_t),     1, f);
    }

    /* ---- 5) Saltar los CURSOS ----
       A la Tarea 3 no le interesan los cursos. Cada curso son 40 bytes
       (id 4 + nombre 32 + creditos 4). Brinco todo el bloque con fseek:
       fseek(f, desplazamiento_bytes, SEEK_CUR). */
    fseek(f, (long)courseCount * 40, SEEK_CUR);

    /* ---- 6) Guardar TODAS las matriculas (sid, year, sem) ----
       Las guardo en un arreglo para recorrerlas mas de una vez
       (necesito mirar las anteriores para detectar duplicados). */
    Matricula mat[enrollCount];

    for(uint32_t i = 0; i < enrollCount; i++){
        uint32_t cid;   /* courseID: leo para avanzar pero no lo uso */
        fread(&mat[i].sid,  sizeof(mat[i].sid),  1, f);
        fread(&cid,         sizeof(cid),         1, f);
        fread(&mat[i].year, sizeof(mat[i].year), 1, f);
        fread(&mat[i].sem,  sizeof(mat[i].sem),  1, f);
    }

    /* ---- 7) Arreglos de contadores ----
       indexados por [year-2020][sem]. year va 2020..2029 (10 valores),
       sem va 1..4 (5 celdas, uso [5] para sem 1..4 sin salir). */
    uint32_t hPre[10][5] = {{0}};  /* hombre  pregrado */
    uint32_t mPre[10][5] = {{0}};  /* mujer   pregrado */
    uint32_t hPos[10][5] = {{0}};  /* hombre  posgrado */
    uint32_t mPos[10][5] = {{0}};  /* mujer   posgrado */

    /* ---- 8) Recorrer matricula por matricula ----
       PASO A) Detectar si ES LA PRIMERA aparicion de (sid, year, sem):
                miro las matriculas anteriores (k < i). */
    for(uint32_t i = 0; i < enrollCount; i++){

        int esPrimera = 1;           /* supongo que es la primera */
        for(uint32_t k = 0; k < i; k++){
            if(mat[k].sid  == mat[i].sid &&
               mat[k].year == mat[i].year &&
               mat[k].sem  == mat[i].sem){
                esPrimera = 0;       /* ya habia salido antes => NO es primera */
                break;
            }
        }

        if(esPrimera == 0){
            continue;                /* no es la primera vez -> no cuento */
        }

        /* PASO B) Es la primera aparicion de este estudiante en este
                (year, sem). Busco sus flags (genero y tipo). */
        unsigned char gf = 0;
        for(uint32_t j = 0; j < studentCount; j++){
            if(estudiantes[j].id == mat[i].sid){
                gf = estudiantes[j].flags;
                break;
            }
        }

        /* PASO C) Sumarlo a su categoria. */
        int yi = (int)(mat[i].year - 2020);   /* indice de anio 0..9 */
        int si = (int)mat[i].sem;              /* indice de semestre 1..4 */

        int mujer = (gf & 0x80) ? 1 : 0;   /* F: 1 = femenino */
        int posgr = (gf & 0x40) ? 1 : 0;   /* G: 1 = posgrado */

        if(mujer && posgr){
            mPos[yi][si]++;
        } else if(mujer && !posgr){
            mPre[yi][si]++;
        } else if(!mujer && posgr){
            hPos[yi][si]++;
        } else {
            hPre[yi][si]++;
        }
    }

    /* ---- 9) IMPRIMIR la tabla ----
       Recorro los 10 anios y los 4 semestres; imprimo solo las filas
       que tienen al menos un estudiante. */
    printf("Anio  Sem  H-Preg M-Preg H-Posg M-Posg\n");
    for(int a = 0; a < 10; a++){
        for(int s = 1; s <= 4; s++){
            if(hPre[a][s] || mPre[a][s] || hPos[a][s] || mPos[a][s]){
                printf("%u     %u     %-5u  %-5u  %-5u  %-5u\n",
                    2020 + a, s, hPre[a][s], mPre[a][s], hPos[a][s], mPos[a][s]);
            }
        }
    }

    /* ---- 10) Cerrar ----
    Todo archivo abierto se cierra. */
    fclose(f);
    return 0;
}
/* ============ FIN TAREA 3 GUIA ============ */
