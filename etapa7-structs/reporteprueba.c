/*
Objetivo del programa:

     1. Definir struct Estudiante (nombre, edad, promedio)
     2. Crear un arreglo de3 estudiantes
     3. Pedir los datos de cada uno
     4. Crear una función void mostrarEstudiantes(struct Estudiante *est, int tam)
         que recorra el arreglo usando punteros (est + i) y muestre cada
        estudiante
     5. Crear una función struct Estudiante* buscarMejor(struct Estudiante *est,
        int tam) que retorne un puntero al estudiante con mayor promedio

     Lo nuevo aquí:

     - est + i = puntero aritmético (avanzar positiones en el arreglo)
     - *(est + i) = acceder al struct en esa posición
     - Retornar un puntero desde una función

     Salida esperada:

     Estudiante 1: Yilmar, 25, 86.60
     Estudiante 2: Ana, 22, 91.30
     Estudiante 3: Pedro, 28, 78.50

     Mejor promedio: Ana (91.30)           */
#include <stdio.h>
#include <string.h>

struct Estudiante
{
    char nombre[40];
    int edad;
    float promedio;
};
// void mostrarEstudiantes(struct Estudiante *est, int tam);
// FUNCION PARA MOSTRAR ESTUDIANTES CON PUNTEROS
void mostrarEstudiantes(struct Estudiante *est, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Estudiante %d: %s %d años. Tiene un promedio de %.2f\n", i + 1, (est + i)->nombre, (est + i)->edad, (est + i)->promedio);
    }
}
    int main()
{

    struct Estudiante Estudiantes[3];
    int tam = sizeof(Estudiantes) / sizeof(Estudiantes[0]);
    for (int i = 0; i < tam; i++)
    {
        printf("Eres el estudiante %d\n", i + 1);

        printf("¿Cómo te llamas?\n");
        scanf(" %[^\n]", Estudiantes[i].nombre);
        // scanf(Estudiantes[i].nombre, 40, stdin);
        // Estudiantes[i].nombre[strcspn(Estudiantes[i].nombre, "\n")] = '\0';

        printf("¿Cuantos años tienes?\n");
        scanf("%d", &Estudiantes[i].edad);
        // while(getchar() != '\n'); //while de consumo

        printf("¿Cual fue tu promedio?\n");
        scanf("%f", &Estudiantes[i].promedio);
        // while(getchar() != '\n');
    }
    mostrarEstudiantes(Estudiantes, tam);
    return 0;
}
