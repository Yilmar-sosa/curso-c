#include <stdio.h> //incluye libreria
int main(){ //funcion madre de los programas
char nombre[20]; //arreglo tipo char con 20 indices
int edad; //define variable tipo entero
float estatura;//define variable tipo flotante
printf("Como te llamas?\n");//imprime lo siguiente
scanf("%s", nombre);//recibe un str y guardalo en la direccion de memoria de nombre
printf("Cuantos anhos tienes?\n");//imprime el texto
scanf("%d", &edad);//recibe un tipo de dato entero y almacenalo en la varible edad mediante su direccion
printf("Cual es tu estatura?\n");//imprime el texto
scanf("%f", &estatura);//recibe por pantalla un dato de tipo flotante y almacenalo en la direccion de memoria estatura

printf("Nombre: %s\nAnhos: %d\nEstatura: %.2f", nombre, edad, estatura);//imprime el texto junto con los datos entregados de las siguientes variables en su orden corespondiente
return 0;
//todo termino bien
}