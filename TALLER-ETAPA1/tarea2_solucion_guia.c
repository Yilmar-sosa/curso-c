/* ============ TAREA 2 (SOLUCION GUIA) ============
   COMPLETA Y COMENTADA para que la estudies y luego la
   escribas tu de memoria en tu propio archivo.
   ------------------------------------------------------------------
   QUE PIDE: calcular e imprimir la EDAD PROMEDIO de los estudiantes
   que asisten a un CURSO ESPECIFICO.
   ------------------------------------------------------------------
   SUPUESTO de entrada (a validar con el profe):
   se corre:  ./tarea2 sample_data.bin 15
   -> argv[1] = nombre del archivo
   -> argv[2] = ID del curso a buscar   (igual que la Tarea 1 usa argv)
   ------------------------------------------------------------------
   ESTRATEGIA (la "libreta"):
   1. Leo y GUARDO todos los estudiantes (id + edad) en un arreglo.
   2. Leo y GUARDO todos los cursos (id + nombre) en un arreglo.
   3. Recorro las matriculas: cada matricula dice (studentID, courseID).
      Si el courseID == curso pedido -> ese estudiante tomo el curso.
      Busco la edad de ese studentID en el arreglo de estudiantes.
   4. Sumo edades (acumulador) y cuento (contador). Promedio = suma/cantidad.
   ------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Un "molde" de estudiante: agrupa sus campos en un solo objeto.
   Esto nos permite guardar MUCHOS estudiantes en un arreglo. */
struct Estudiante{
    uint32_t id;            /* identificador unico del estudiante */
    unsigned char flags;    /* byte de banderas (genero, posgrado) */
    char nombre[24];        /* nombre (23 bytes + '\0') */
    uint32_t edad;          /* edad del estudiante */
};

/* Un "molde" de curso: agrupa los campos de un curso. */
struct Curso{
    uint32_t id;            /* identificador unico del curso */
    char nombre[32];        /* nombre del curso (32 bytes) - OJO: sin '\0' extra, uso 32 */
    uint32_t creditHours;   /* horas de credito */
};

int main(int argc, char *argv[]){

    /* ---- 0) VERIFICAR argumentos ----
       Necesitamos: el nombre del programa  = argv[0]
                     el archivo binario      = argv[1]
                     el ID del curso          = argv[2]
       -> en total 3 argumentos (argc == 3... pero ojo:
       argc incluye a argv[0], asi que argc==3 significa 3 elementos:
       [programa, archivo, id_curso]). Usamos argc != 3 para exigir 3. */
    if(argc != 3){
        printf("Uso: %s <archivo.bin> <id_curso>\n", argv[0]);
        return 1;   /* termino con error porque faltan datos */
    }

    /* ---- 1) LEER el ID del curso que se pasa por consola ----
       argv[2] es TEXTO (ej: "15"). atoi() lo convierte a numero (15). */
    uint32_t cursoBuscado = atoi(argv[2]);

    /* ---- 2) ABRIR el archivo en modo binario de lectura ----
       'rb' = read (leer) + binary (binario).
       El archivo se llama como diga argv[1]. */
    FILE *f = fopen(argv[1], "rb");

    if(f == NULL){              /* Si fopen falla devuelve NULL... */
        printf("No se pudo abrir %s\n", argv[1]);
        return 1;               /* ...termino con error */
    }

    /* ---- 3) LEER el ENCABEZADO (reutilizado de la Tarea 1) ----
       Formato: magic(2) + studentCount(4) + courseCount(4) + enrollCount(4) */
    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    fread(&magic,        sizeof(magic),        1, f);   /* leo el magic (2 bytes) */
    fread(&studentCount, sizeof(studentCount), 1, f);   /* cuantos estudiantes hay */
    fread(&courseCount,  sizeof(courseCount),  1, f);   /* cuantos cursos hay      */
    fread(&enrollCount,  sizeof(enrollCount),  1, f);   /* cuantas matriculas hay  */

    /* ---- 4) ARREGLO de estudiantes para GUARDARLOS, no descartarlos ----
       Creo espacio para guardar studentCount estudiantes a la vez.
       Cada posicion [i] guarda un struct Estudiante completo. */
    struct Estudiante estudiantes[studentCount];

    /* ---- 5) Leer los ESTUDIANTES y guardarlos en el arreglo ----
       Recorro studentCount veces. Cada vuelta llena un estudiante del arreglo.
       OJO: el nombre real esta en 23 bytes; el struct declara char nombre[24],
       asi que leo 23 bytes a mano y pongo el '\0' yo. */
    for(uint32_t i = 0; i < studentCount; i++){
        fread(&estudiantes[i].id,     sizeof(uint32_t),    1, f); /* id     (4B) */
        fread(&estudiantes[i].flags,  sizeof(unsigned char),1, f); /* flags  (1B) */
        fread(estudiantes[i].nombre,  23,                   1, f); /* nombre (23B) */
        estudiantes[i].nombre[23] = '\0';       /* pongo fin de cadena */
        fread(&estudiantes[i].edad,   sizeof(uint32_t),    1, f); /* edad   (4B) */
    }

    /* ---- 6) ARREGLO de cursos para guardarlos ----
       El archivo, despues de los estudiantes, tiene los cursos.
       Los guardo para poder buscar el nombre del curso pedido. */
    struct Curso cursos[courseCount];

    for(uint32_t i = 0; i < courseCount; i++){
        fread(&cursos[i].id,    sizeof(uint32_t), 1, f); /* id    (4B) */
        fread(cursos[i].nombre, 32,                1, f); /* nombre(32B) */
        fread(&cursos[i].creditHours, sizeof(uint32_t), 1, f); /* creditos (4B) */
    }

    /* ---- 7) ACUMULADOR y CONTADOR para el promedio ----
       sumaEdades = acumulo todas las edades de los que toman el curso.
       cantidad   = cuantos estudiantes toman el curso. */
    uint64_t sumaEdades = 0;   /* uso uint64_t para no desbordar con muchas sumas */
    uint32_t cantidad   = 0;

    /* ---- 8) Recorrer las MATRICULAS ----
       Cada matricula: studentID(4) + courseID(4) + year(4) + semester(4).
       Leo esas 4 cajas por matricula. */
    uint32_t sID, cID, year, sem;

    for(uint32_t i = 0; i < enrollCount; i++){
        /* leo los 4 campos de la matricula actual */
        fread(&sID,   sizeof(sID),   1, f);   /* studentID */
        fread(&cID,   sizeof(cID),   1, f);   /* courseID  */
        fread(&year,  sizeof(year),  1, f);   /* anio      */
        fread(&sem,   sizeof(sem),   1, f);   /* semestre  */

        /* ---- 9) FILTRO: solo me importa el curso pedido ----
           Si esta matricula NO es del curso buscado, la salto. */
        if(cID != cursoBuscado){
            continue;   /* 'continue' salta al siguiente i del for */
        }

        /* ---- 10) Encontre un estudiante que tomo el curso.
              Necesito su EDAD. Busco su id en el arreglo de estudiantes. */
        for(uint32_t j = 0; j < studentCount; j++){
            if(estudiantes[j].id == sID){      /* coincide el id buscado */
                sumaEdades += estudiantes[j].edad;   /* acumulo la edad */
                cantidad++;                          /* sumo uno al contador */
                break;   /* ya lo encontre, no sigo buscando en el arreglo */
            }
        }
    }

    /* ---- 11) CALCULAR y IMPRIMIR el promedio ----
       Promedio = suma / cantidad.
       CUIDADO con Division por cero: si nadie tomo el curso, cantidad es 0. */
    if(cantidad == 0){
        printf("Ningun estudiante encontrado para el curso %u\n", cursoBuscado);
    } else {
        double promedio = (double)sumaEdades / cantidad;  /* promedio decimal */
        printf("Curso %u | Promedio de edad: %.2f | Estudiantes: %u\n",
               cursoBuscado, promedio, cantidad);
    }

    /* ---- 12) CERRAR el archivo ----
       Siempre hay que cerrar lo que abrimos. */
    fclose(f);

    return 0;   /* todo salio bien */
}
/* ============ FIN TAREA 2 GUIA ============ */
