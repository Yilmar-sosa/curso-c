#include <stdio.h>
int main(){
char nombre[20];
int edad;
float estatura;
printf("Como te llamas?\n");
scanf("%s", nombre);
printf("Cuantos anhos tienes?\n");
scanf("%d", &edad);
printf("Cual es tu estatura?\n");
scanf("%f", &estatura);

printf("Nombre: %s\nAnhos: %d\nEstatura: %.2f", nombre, edad, estatura);
return 0;
}