/*🏋️ Ejercicio: refactorizar notas.c                                             
                                                                                    
     Tu notas.c tiene toda la lógica en main. Ahora extráela en funciones:          
                                                                                    
     1. void mostrarNotas(int notas[], int tamano) — imprime cada nota              
     2. float calcularPromedio(int notas[], int tamano) — retorna el promedio       
     3. int encontrarMaximo(int notas[], int tamano) — retorna el máximo            
     4. int encontrarMinimo(int notas[], int tamano) — retorna el mínimo            
                                                                                    
     En main solo quedan: declarar el arreglo, llenarlo con scanf, y llamar las     
     funciones.                                                                     
                                            */

#include <stdio.h>
void mostrarNotas(int notas[], int tamano);
float calcularPromedio(int notas[], int tamano);
int encontrarMaximo(int notas[], int tamano);
int encontrarMinimo(int notas[], int tamano);
int main(){
    int notas[5];
    int tamano = sizeof(notas)/ sizeof(notas[1]);
    
    printf("Escribe tus notas para que podamos sacar tu promedio\n");
    for(int i = 0; i < tamano; i++){
     scanf("%d", &notas[i]);
    }
    mostrarNotas(notas, tamano);
    calcularPromedio(notas, tamano);
    encontrarMaximo(notas, tamano);
    encontrarMinimo(notas, tamano);
   
    return 0;
}
// FUNCION PARA MOSTRAR NOTAS
void mostrarNotas(int notas[], int tamano){
    int numerador = 1;
    for(int i = 0; i < tamano; i++){
    printf("Nota %d: %d\n", numerador, notas[i]);
    numerador++;
}
}
 

//FUNCION DE PROMEDIO
float calcularPromedio(int notas[], int tamano){
    int suma = 0;
    float promedio = 0;

    for(int i = 0; i < tamano; i++){
        suma = suma + notas[i];
    }
    promedio = (float)suma / tamano;
    printf("Promedio: %.2f\n", promedio);
   return promedio; 
}
//FUNCION PARA ENCONTRAR NUMERO MAXIMO
int encontrarMaximo(int notas[], int tamano){
    int max = notas[0];
    for(int e = 1; e < tamano; e++){
        if(notas[e] > max){
            max = notas[e];
        }
    }
    printf("La nota mayor es: %d\n", max);
    return max;
}
//FUNCION PARA ENCONTRAR MINIMO
int encontrarMinimo(int notas[], int tamano){
    int min = notas[0];
        for(int e = 1; e < tamano; e++){
            if(notas[e] < min){
                min = notas[e];
            }
    }
    printf("La nota menor es: %d\n", min);
    return min;
}
