#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main(){ //funcion madre de los programas
    int num1, num2, num3; //crea tres variables de tipo entero para guardar los tres numeros del usuario
    printf("Digita un numero: \n"); //imprime el mensaje pidiendo el primer numero
    scanf("%d", &num1); //recibe un dato de tipo entero y guardalo en la direccion de memoria num1
    printf("Digita un segundo numero: \n"); //imprime el mensaje pidiendo el segundo numero
    scanf("%d", &num2); //recibe un dato de tipo entero y guardalo en la direccion de memoria num2
    printf("Digita un tercer numero: \n"); //imprime el mensaje pidiendo el tercer numero
    scanf("%d", &num3); //recibe un dato de tipo entero y guardalo en la direccion de memoria num3

    if(num1 > num2 && num1 > num3){ //si num1 es mayor a num2 Y a la vez num1 es mayor a num3 entonces
        printf("El numero %d es el numero mayor", num1); //imprime que num1 es el mayor
    }
    else if(num2 > num1 && num2 > num3){ //si la anterior no se cumple y num2 es mayor a num1 Y a la vez num2 es mayor a num3 entonces
        printf("El numero %d es el numero mayor", num2); //imprime que num2 es el mayor

        }
    else if(num1 == num2 && num2 >= num3){ //si num1 es igual a num2 y num2 es mayor o igual a num3 entonces
        printf("El numero %d es el numero mayor", num1); //imprime que num1 es el mayor
    }
    else{ //si ninguna condicion se cumple entonces
            printf("El numero %d es el numero mayor", num3); //imprime que num3 es el mayor
        }
    return 0; //el programa termina bien
    }
