#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla

int main() { //funcion madre de los programas
    int num; //crea una variable de tipo entero para guardar el numero que digita el usuario

    printf("Digite un numero: "); //imprime el mensaje pidiendo el numero
    scanf("%d", &num); //recibe un dato de tipo entero y guardalo en la direccion de memoria num

    if (num == 0) { //si el numero es igual a 0 entonces
        printf("El numero es cero\n"); //imprime que el numero es cero
        return 0; //termina el programa bien
    }

    if (num % 2 == 0) { //si el residuo de num dividido en 2 es igual a 0 entonces
        printf("Paridad: Par\n"); //imprime que es par
    } else { //si no
        printf("Paridad: Impar\n"); //imprime que es impar
    }

    if (num > 0) { //si num es mayor a 0 entonces
        printf("Signo: Positivo\n"); //imprime que el signo es positivo
    } else { //si no
        printf("Signo: Negativo\n"); //imprime que el signo es negativo
    }

    return 0; //el programa termina bien
}
