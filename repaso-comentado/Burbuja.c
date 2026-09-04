#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
void ordenar(int numeros[], int tam); //prototipo: ordena los numeros, retorna void, recibe un arreglo y su tamanio
void mostrar(int numeros[], int tam); //prototipo: muestra los numeros, retorna void, recibe un arreglo y su tamanio

int main(){ //funcion madre de los programas
    int numeros[5]; //crea un arreglo de 5 enteros para guardar los numeros
    int tam = sizeof(numeros)/sizeof(numeros[0]); //tam guarda cuantos elementos tiene el arreglo (5 = bytes totales entre bytes de uno)

    printf("Escribe los numeros que quieres ordenar\n"); //imprime el mensaje pidiendo los numeros
    for(int i = 0; i < tam; i++){ //el contador i inicia en 0, se repite mientras i sea menor a tam, y aumenta 1 por vuelta
        scanf("%d", &numeros[i]); //recibe un dato entero y guardalo en la posicion i del arreglo
    }
    printf("Tus numeros son:\n\n"); //imprime el encabezado
    mostrar(numeros, tam); //llama a la funcion mostrar con los numeros y su tamanio
    ordenar(numeros, tam); //llama a la funcion ordenar (bubble sort)
    printf("Tus numeros ordenados de menor a mayor quedan asi:\n\n"); //imprime el encabezado
    mostrar(numeros, tam); //llama a la funcion mostrar con los numeros ya ordenados

}
//FUNCION BUBBLE SORT
void ordenar(int numeros[], int tam){ //definicion: ordena el arreglo, no retorna, recibe el arreglo y su tamanio
    for (int p = 0; p < tam -1; p++){ //pasadas: repite mientras p sea menor a tam-1
        for(int i = 0; i < tam -1; i++){ //comparaciones: recorre el arreglo comparando de a pares
            if(numeros[i] > numeros[i+1]){ //si el de la izquierda es mayor que el de la derecha entonces
                int temp = numeros[i]; //guardalo en una variable temporal
                numeros [i] = numeros[i+1]; //el de la izquierda ahora vale el de la derecha
                numeros[i+1] = temp; //el de la derecha ahora vale el temporal (se intercambiaron)
            }
        }
    }
}
//FUNCION PARA MOSTRAR ARREGLOS
void mostrar(int numeros[], int tam){ //definicion: muestra el arreglo, no retorna, recibe el arreglo y su tamanio
    for(int i = 0; i < tam; i++){ //el contador i inicia en 0, se repite mientras i sea menor a tam, y aumenta 1 por vuelta
        printf("%d ", numeros[i]); //imprime cada numero seguido de un espacio
    }
    printf("\n\n"); //salta dos lineas al terminar
}
