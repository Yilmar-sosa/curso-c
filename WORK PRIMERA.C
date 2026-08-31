#include <stdio.h>
#include <stdlib.h>
//FUNCION DE INTERCAMBIO DE VALOR
void swap (int* a, int *b){/*crea una funcion que no retonorne nada llamada intercambio que reciba
como parametros dos variables de enteros que sean de tipo punteros(que guardan la ubicacion y entregan
el dato que contiene la variable real)*/
    int tem = *a;//crea una variable de tipo entero llamada temporal que reciba el puntero de la variable a
    *a = *b; //copea el valor que contiene la *b asignaselo a *a
    *b = tem;//copea el valor que contien la variable temporal en el *b
}
//FUNCION QUE REVERSA ARREGLOS 
void reverseArray(int arreglo[], int tamano){
    for(int i = 0; i < tamano / 2; i++){
    int tem = arreglo [i];
    arreglo [i] = arreglo[tamano-1-i];
    arreglo [tamano-1-i] = tem;
    }
}
//FUNCION QUE IMPRIME ARREGLOS 
void printArray(int arreglo [], int tamano){
    for(int i = 0; i < tamano; i++){
       printf("%d ", arreglo[i]);
}
    }
    
int main() {
    int *arreglo = NULL;  // Puntero que representará el arreglo dinámico
    int tamano = 5;       // Tamaño inicial del arreglo
    /* Muy importatnte entender las primeras dos linea antes de seguir
        malloc reserva memoria dinámica para 5 enteros.
        El resultado se guarda en el puntero arreglo.
    */
    arreglo = (int *)malloc(tamano * sizeof(int));
    // Verifica si malloc pudo asignar memoria correctamente
    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    // Inicialización de los primeros 5 elementos del arreglo


    arreglo[0] = 10;
    arreglo[1] = 20;
    arreglo[2] = 30;
    arreglo[3] = 40;
    arreglo[4] = 50;
    // Imprime el arreglo original
    printf("Arreglo Original: ");
    printArray(arreglo, tamano);
    // Cambiamos el tamaño lógico del arreglo de 5 a 7
    tamano = 7;
    /*
        realloc intenta cambiar el tamaño del bloque de memoria.
        Se usa un puntero temporal para no perder la referencia original
        si realloc falla.
    */
    int *temp = (int *)realloc(arreglo, tamano * sizeof(int));
    // Verifica si realloc pudo redimensionar el arreglo correctamente
    if (temp == NULL) {
        printf("Error al cambiar el tamaño del arreglo.\n");
        free(arreglo);  // Libera la memoria original antes de terminar
        return 1;
    }
    // Si realloc fue exitoso, actualizamos el puntero principal
    arreglo = temp;
    // Inicializamos los nuevos elementos agregados al arreglo
    arreglo[5] = 60;
    arreglo[6] = 70;
    // Imprime el arreglo después de cambiar el tamaño
    printf("Arreglo después de cambiar el tamaño: ");
    printArray(arreglo, tamano);
    // Invierte el arreglo completo
    reverseArray(arreglo, tamano);
    // Imprime el arreglo invertido
    printf("Arreglo Invertido: ");
    printArray(arreglo, tamano);
    /*
        Intercambia los elementos en índice 1 e índice 3.
        Después de invertir:
        índice 1 = 60
        índice 3 = 40
        Luego del intercambio:
        índice 1 = 40
        índice 3 = 60
    */
    swap(&arreglo[1], &arreglo[3]);
    // Imprime el arreglo después del intercambio
    printf("Arreglo después del intercambio: ");
    printArray(arreglo, tamano);
    // Libera la memoria dinámica usada por el arreglo
    free(arreglo);
    // Evita que el puntero quede apuntando a memoria liberada
    arreglo = NULL;
    return 0;
}

