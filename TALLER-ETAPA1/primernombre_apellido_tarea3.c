#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Estructura de un estudiante guardado. 
typedef struct {
    uint32_t id;            
    unsigned char flags;   
    char nombre[24];        
    uint32_t edad;          
} Estudiante;

// Estructura de una matricula guardada.
typedef struct {
    uint32_t EstudianteId;  
    uint32_t anio;  
    uint32_t Semestre;   
} Matricula;

int main(int argc, char *argv[]){


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

    //Leer encabezado
    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    fread(&magic,        sizeof(magic),        1, f);
    fread(&studentCount, sizeof(studentCount), 1, f);
    fread(&courseCount,  sizeof(courseCount),  1, f);
    fread(&enrollCount,  sizeof(enrollCount),  1, f);

    // Guardar TODOS los estudiantes (id + flags) 
    //  Luego necesito el genero y tipo de cada studentID.
    Estudiante estudiantes[studentCount];

    for(uint32_t i = 0; i < studentCount; i++){
        fread(&estudiantes[i].id,    sizeof(uint32_t),     1, f);
        fread(&estudiantes[i].flags, sizeof(unsigned char),1, f);
        fread(estudiantes[i].nombre, 23, 1, f);
        estudiantes[i].nombre[23] = '\0';
        fread(&estudiantes[i].edad,  sizeof(uint32_t),     1, f);
    }

    // Brinco todo el bloque con fseek:
       
    fseek(f, (long)courseCount * 40, SEEK_CUR);

    /*e crea un arreglo de la struct Matricula la llamamos mat y su capacidad
    sera enrollCount*/
    Matricula mat[enrollCount];

    for(uint32_t i = 0; i < enrollCount; i++){
        uint32_t cid;   /* courseID: leo para avanzar pero no lo uso */
        fread(&mat[i].EstudianteId,  sizeof(mat[i].EstudianteId),  1, f);
        fread(&cid,         sizeof(cid),         1, f);
        fread(&mat[i].anio, sizeof(mat[i].anio), 1, f);
        fread(&mat[i].Semestre,  sizeof(mat[i].Semestre),  1, f);
    }

    //Arreglos de contadores 
    uint32_t hPre[10][5] = {{0}}; 
    uint32_t mPre[10][5] = {{0}}; 
    uint32_t hPos[10][5] = {{0}}; 
    uint32_t mPos[10][5] = {{0}}; 

    //recorrer matricula por matricula 
    for(uint32_t i = 0; i < enrollCount; i++){

        int esPrimera = 1;           /* supongo que es la primera */
        for(uint32_t k = 0; k < i; k++){
            if(mat[k].EstudianteId == mat[i].EstudianteId &&
               mat[k].anio == mat[i].anio &&
               mat[k].Semestre  == mat[i].Semestre){
                esPrimera = 0;     
                break;
            }
        }

        if(esPrimera == 0){
            continue;             
        }
        unsigned char gf = 0;
        for(uint32_t j = 0; j < studentCount; j++){
            if(estudiantes[j].id == mat[i].EstudianteId){
                gf = estudiantes[j].flags;
                break;
            }
        }

        //Sumarlo a su categoria. 
        int yi = (int)(mat[i].anio - 2020);   
        int si = (int)mat[i].Semestre;              

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

    /*Recorro los 10 anios y los 4 semestres; imprimo solo las filas
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


    fclose(f);
    return 0;
}

