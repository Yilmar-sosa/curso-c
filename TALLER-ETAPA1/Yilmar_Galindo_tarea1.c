#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){
    
    //verifica si recibe la cantidad de argumentos que necesitamos.
    if(argc != 4){
      printf("Tus comandos para %s <archivo.bin> <edadMinima> <edadMaxima>", argv[0]);
      return 1;
    }

    //lee el documento con el que trabajaremos
    FILE *f = fopen("sample_data.bin", "rb");
    if(f == NULL){
        printf("No se pudo abrir\n");
         return 1;}


    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    fread(&magic,        sizeof(magic),        1, f);
    fread(&studentCount, sizeof(studentCount), 1, f);
    fread(&courseCount,  sizeof(courseCount),  1, f);
    fread(&enrollCount,  sizeof(enrollCount),  1, f);

    printf("Magic: %u\n", magic);
    printf("Estudiantes: %u\n", studentCount);
    printf("Cursos: %u\n", courseCount);
    printf("Matriculas: %u\n", enrollCount);

    unsigned int edadMinima = atoi(argv[2]);
    unsigned int edadMaxima = atoi(argv[3]);


    uint32_t id, edad;
    unsigned char flags;
    char nombre[23];

    
    for(int i = 0; i < studentCount; i++){
        fread(&id, sizeof(id), 1, f);
        fread(&flags, sizeof(flags), 1, f);
        fread(nombre, sizeof(nombre), 1, f);
        nombre[23] = '\0';
        fread(&edad, sizeof(edad), 1, f);
        
        if(edad >= edadMinima && edad <= edadMaxima){

            char *genero;
             if(flags& 0X80){// "Si (el contenido de la variable flags) haciendo Y-bit-a-bit con (el         
             //número 0x80) da un valor distinto de cero, entonces

                genero = "Female";
             }
             else{
                genero = "Male";
             }
            

            printf("%-23s Age: %-3u Gender: %s\n", nombre, edad, genero);
        }
    }

    fclose(f);
    return 0;
}
/*Tarea:
Implementa un programa en C que lea el archivo binario e imprima los nombres, 
edades y géneros de todos los estudiantes dentro de un rango de edades.
 El rango de edades y el nombre del archivo binario se proporcionarán como argumentos de línea de comandos. 
 El filtro de edades debe incluir los argumentos de límite superior e inferior.*/
