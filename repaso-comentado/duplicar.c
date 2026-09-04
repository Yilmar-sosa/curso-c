#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla

void duplicar(int x); //prototipo: avisale al compilador que existe la funcion duplicar, no retorna y recibe un int

int main() { //funcion madre de los programas
    int n = 5; //crea la variable n de tipo entero con valor 5
    duplicar(n); //llama a la funcion duplicar y le pasa el valor 5 (una fotocopia de n)
    printf("Fuera de la funcion n vale: %d\n", n); //imprime el valor de n (sigue siendo 5 porque el cambio fue en la copia)
    return 0; //el programa termina bien
}

void duplicar(int x) { //definicion de la funcion: no retorna y recibe un int (la copia x)
    x = x * 2; //a la copia x asignale el doble de su valor
    printf("Dentro de la funcion x vale: %d\n", x); //imprime el valor de la copia x (10)
}
