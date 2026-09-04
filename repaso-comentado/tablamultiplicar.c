#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
void numero(void); //prototipo: avisale al compilador que existe la funcion numero, no retorna y no recibe parametros

int main(){ //funcion madre de los programas
    numero(); //llama a la funcion numero (imprime la tabla)
    numero(); //llama de nuevo la funcion (imprime otra tabla)
    numero(); //llama una tercera vez (imprime otra tabla)
    return 0; //el programa termina bien

}
void numero(void){ //definicion de la funcion: no retorna y no recibe parametros
    int num; //crea la variable que guardara el numero del cual se hara la tabla
    printf("cual es su numero\n\n"); //imprime el mensaje pidiendo el numero
    scanf("%d", &num); //recibe un dato de tipo entero y guardalo en la direccion de memoria num
    for (int i = 1; i < 11; i++){ //el contador i inicia en 1, se repite mientras i sea menor a 11 (del 1 al 10), y aumenta 1 por vuelta
         int resultado = num * i; //resultado guarda la multiplicacion de num por i
    printf("%d x %d = %d\n", num, i, resultado); //imprime la multiplicacion con su resultado
    }

}
