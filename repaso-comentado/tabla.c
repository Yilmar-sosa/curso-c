#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main(){ //funcion madre de los programas
    int num; //crea la variable que guardara el numero del cual se hara la tabla
    printf("Escribe el numero de la tabla de multiplicar que deseas\n"); //imprime el mensaje pidiendo el numero
    scanf("%d", &num); //recibe un dato de tipo entero y guardalo en la direccion de memoria num

    for(int i = 1; i < 11; i++){ //el contador i inicia en 1, se repite mientras i sea menor a 11 (del 1 al 10), y aumenta 1 por vuelta
    int multiplicacion = num * i; //multiplicacion guarda el resultado de num por i
    printf("%d x %d = %d\n", num, i, multiplicacion); //imprime la multiplicacion con su resultado
    }
    return 0; //el programa termina bien
}
