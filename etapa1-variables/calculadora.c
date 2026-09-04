#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main (){//Iniciamos el programa en c con la funcion madre.
    int num1, num2; //crea dos variables de tipo entero a las que no se les asignara nada por ahora
printf("Digita tu primer numero\n"); //imprime el texto entre comillas y has un salto de linea
scanf("%d", &num1);//scanea un dato de tipo entero que se encuentra en la direccion de memoria num1
printf("Digita tu segundo numero\n");//imprime el texto entre comillas y finaliza con un salto de linea
scanf("%d", &num2);//recibe una entrada de un dato tipo entero de la variable de direccion num2
int sum = num1 + num2; //crea una variable llamada sum de tipo entero que guarda la suma de dos variables
int rest = num1 - num2;//crea una variable de tipo entero llamada rest y asignale la resta de dos variables
int Mult = num1 * num2;//crea una variable de tipo entero llamada mult que recibe como valor el resultado de una multiplicacion
float Div = (float)num1 / num2;//crea una variable de tipo flotante que almacenara la divicion de una variable int convertida a float y divida en una variable int
int resto = num1 % num2;//creo una variable de tipo entero que guardara una operacion de modulo


printf("Suma: %d\nResta: %d\nMultiplicacion: %d\nDivision: %.2f\nModulo: %d",sum, rest, Mult, Div, resto);
//imprime el texto entre comillas y recibe los datos segun su tipo y orden de las variables
return 0;
//El programa termina bien
}