#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint32_t id;
    unsigned char flags;
    char nombre[24];
    uint32_t edad;
}Estudiante;

typedef struct{
    uint32_t IdCurso;
    char NombreCurso[32];
    uint32_t HorasCredito;

}Curso;

int main(int argc, char *argv[]){
    
    //verifica si recibe la cantidad de argumentos que necesitamos.
    if(argc != 3){
      printf("Tus comandos para %s <archivo.bin> <edadMinima> <edadMaxima>", argv[0]);
      return 1;
    }
    uint32_t cursoBuscado = atoi(argv[2]);

    //lee el documento con el que trabajaremos
    FILE *f = fopen(argv[1], "rb");
    if(f == NULL){
        printf("No se pudo abrir\n");
         return 1;
        }


    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    fread(&magic,        sizeof(magic),        1, f);
    fread(&studentCount, sizeof(studentCount), 1, f);
    fread(&courseCount,  sizeof(courseCount),  1, f);
    fread(&enrollCount,  sizeof(enrollCount),  1, f);

    //creacion de arreglo de Estudiante
    Estudiante Estudiantes[studentCount];

    //ciclo que guarda los estudiantes con su structura en un arreglo
    for(uint32_t i = 0; i < studentCount; i++){
        fread(&Estudiantes[i].id, sizeof(uint32_t), 1, f);
        fread(&Estudiantes[i].flags, sizeof(char), 1, f);
        fread(&Estudiantes[i].nombre, 23, 1, f);
        Estudiantes[i].nombre[23] = '\0';
        fread(&Estudiantes[i].edad, sizeof(uint32_t), 1, f);
    }

    //creacion de arreglo de cursos
    Curso cursos[courseCount];
    for(uint32_t i = 0; i < courseCount; i++){
        fread(&cursos[i].IdCurso, sizeof(uint32_t), 1, f);
        fread(&cursos[i].NombreCurso, 32, 1, f);    
        fread(&cursos[i].HorasCredito, sizeof(uint32_t), 1, f);
    }

    uint64_t sumaEdades = 0;
    uint32_t cantidad = 0;

    //variables seccion de matriculas
    uint32_t IdEstudiante, IdCurso, Año, Semestre;

    for(uint32_t i = 0; i < enrollCount; i++){
        fread(&IdEstudiante, sizeof(IdEstudiante), 1, f);        
        fread(&IdCurso, sizeof(IdCurso), 1, f);
        fread(&Año, sizeof(Año), 1, f);
        fread(&Semestre, sizeof(Semestre), 1, f);
        
        //si el id curso es diferente al curso buscado saltarlo
        if(IdCurso != cursoBuscado){
            continue;
        }
    

        for(uint32_t j = 0; j < studentCount; j++){                                              
             if(Estudiantes[j].id == IdEstudiante){                                  
                 sumaEdades += Estudiantes[j].edad;                                 
                 cantidad++;                                                    
           break;   
             }
    }
}
    if(cantidad == 0){                                                                                    
      printf("Ningun estudiante encontrado para el curso %u\n", cursoBuscado);                          
  } else {                                                                                              
      double promedio = (double)sumaEdades / cantidad;                    
      printf("Curso %u | Promedio de edad: %.2f | Estudiantes: %u\n",                                   
             cursoBuscado, promedio, cantidad);                                                         
  }                                                                                                     
                                                                                                        
                                                        
  fclose(f);                                                                                            
                                                                                                        
  return 0;
}




