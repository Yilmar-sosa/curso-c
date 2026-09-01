#include <stdio.h>
#include <stdint.h>

int main(){
    FILE *f = fopen("sample_data.bin", "rb");
    if(f == NULL){printf("No se pudo abrir\n"); return 1;}

    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    fread(&magic,        sizeof(magic),        1, f);
    fread(&studentCount, sizeof(studentCount), 1, f);
    fread(&courseCount,  sizeof(courseCount),  1, f);
    fread(&enrollCount,  sizeof(enrollCount),  1, f);

    magic = (magic >> 8) | (magic << 8);   // invierte los 2 bytes del magic
    printf("Magic: 0x%04X\n", magic);
    printf("Estudiantes: %u\n", studentCount);
    printf("Cursos: %u\n", courseCount);
    printf("Matriculas: %u\n", enrollCount);

    uint32_t id, edad;
    unsigned char flags;
    char nombre[24];
    for()
    



    fclose(f);
    return 0;
}
/*Tarea:
Implementa un programa en C que lea el archivo binario e imprima los nombres, 
edades y géneros de todos los estudiantes dentro de un rango de edades.
 El rango de edades y el nombre del archivo binario se proporcionarán como argumentos de línea de comandos. 
 El filtro de edades debe incluir los argumentos de límite superior e inferior.*/
