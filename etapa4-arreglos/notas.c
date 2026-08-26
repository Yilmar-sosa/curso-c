/* 1. Pedir 5 notas al usuario (un for con scanf)                                 
     2. Calcular el promedio                                                        
     3. Mostrar cada nota y su posición                                             
                                                                                     
     Salida esperada:                                                               
                                                                                     
     Nota 1: 85                                                                     
     Nota 2: 90                                                                     
     Nota 3: 78                                                                     
     Nota 4: 92                                                                     
     Nota 5: 88                                                                     
     Promedio: 86.60                                                                
                     */
#include <stdio.h>
int main(){
    int notas[5];
    int suma = 0;
    float promedio = 0;
    int i;
    printf("Escribe tus notas para que podamos sacar tu promedio\n");
    for(i = 0; i < 5; i++){
        scanf("%d", &notas[i]);
        suma = suma + notas[i];
    }
    printf("Nota 1: %d\n", notas[0]);
    printf("Nota 2: %d\n", notas[1]);
    printf("Nota 3: %d\n", notas[2]);
    printf("Nota 4: %d\n", notas[3]);
    printf("Nota 5: %d\n", notas[4]);
    promedio = (float)suma / i;
    printf("Promedio: %.2f\n", promedio);

    int max = notas[0];
    for(int e = 1; e < 5; e++){
        if(notas[e] > max){
            max = notas[e];
        }
    }
    printf("La nota mayor es: %d\n", max);

    int min = notas[0];
    for(int e = 1; e < 5; e++){
        if(notas[e] < min){
            min = notas[e];
        }
    }
    printf("La nota menor es: %d\n", min);

    return 0;
}
