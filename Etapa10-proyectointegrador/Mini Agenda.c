/*Objetivo: una mini agenda de alumnos que:                                 
                                                                               
     1. Agregar alumno — pide nombre, edad, promedio y lo guarda en un         
        arreglo de structs                                                     
     2. Listar alumnos — muestra todos                                         
     3. Guardar en archivo — escribe todos los alumnos en alumnos.txt          
     4. Cargar desde archivo — lee los alumnos que estaban guardados           
     5. Mostrar el promedio general del grupo                                  
                                                                               
     Requisitos técnicos:                                                      
                                                                               
     - struct Alumno { char nombre[50]; int edad; float promedio; };           
     - Un arreglo de alumnos (digamos hasta 10)                                
     - Funciones: agregar, listar, guardarArchivo, cargarArchivo,              
       promedioGrupo                                                           
     - Uso de punteros donde corresponda                                       
                                            *//**/

#include <stdio.h>
#include <stdlib.h>

struct Alumno{
    char nombre[50];
    int edad;
    int **notas;
}
void promedioIndividual(int **notas, int tam);
void agregar (struct Alumno *Alu, int tam);
void listar(struct Alumno *Alu, int tam);
void guardarArchivo(struct Alumno *Alu, int tam);
void cargarArchivo(struct Alumno *Alu, int tam);
void promedioGrupo(struct Alumno *Alu, int tam);

int main(){
    int cantidad;
    int longitudN;
    
    printf("     Agenda de alumnos\n\n");
    
    printf("¿Cuantos alumnos desea agregar?\n");
    scanf("%d", &cantidad);
    

    int *Alumnos = (int*) malloc(cantidad * sizeof(int));
    if(int Alumnos == NULL){
        printf("No tienes tanta memoria\n");
        return 0;  
    
    int **notas = (int**) malloc(longitudN * sizeof(int));
    if(int notas == NULL);
        printf("Memoria insuficiente");
        return 0;
    }
    promedioIndividual(notas, longitudN);
    return 0;
}
//Funcion para calcular promedio de un array alojado dentro de una extructurar
int promedioIndividual(int **notas, int tam){
    int suma;
    int resultado;
    for(int i = 0; i < tam; i++){
        suma = notas[i] + notas [i++];
    }
    resultado = suma / tam;
    printf("%d", resultado);
    return resultado;
    }
//Funcio para agregar struct a un array
int agregar(struct **Alumnos, int tam){
    Alumnos [tam];
    for(int i = 0; i < tam; i++){
        scanf("%d", Alumnos[i]);
    }
    return Alumnos;
}



