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

struct Estudiante{
    char nombre[40];
    int edad;
    float promedio;
};
// void mostrarEstudiantes(struct Estudiante *est, int tam);
// FUNCION PARA MOSTRAR ESTUDIANTES CON PUNTEROS
void mostrarEstudiantes(struct Estudiante *est, int tam){//no retorna mostrarEstudiantes recibe como parametros(un arreglo del structs en este caso del molde Estudiante, segundo parametro una variable de tipo int)
    for (int i = 0; i < tam; i++){//i inica en 0, se repitara en bucle las instrucciones mientras i < tam, pero el iniciador aumentar su valor a +1 con cada vuelta finalizada
        printf("Estudiante %d: %s %d años. Tiene un promedio de %.2f\n", i + 1, (est + i)->nombre, (est + i )->edad, (est + i)->promedio);//imprime texto con los valos de tipos de datos segun su orden
        //recibido de una suma, puntero a est + la posicion del valor de i que apunta al miembro(ejemplo nombre en el primer caso)
    }
}
    int main()
{

    struct Estudiante Estudiantes[3];//LLamamos al molde de structura Estudiante y creamos un arreglo de estructuras llamado Estudiantes que almacenara 3 struct
    int tam = sizeof(Estudiantes) / sizeof(Estudiantes[0]);//creacion de variable tipo int que guarda como valor la operacion matematica en bytes (Cuantos bytes mide el arreglo de struct) dividido en el espacion en bytes de un indice en este caso que ocupa una struct completa individualmente 
    for (int i = 0; i < tam; i++)
    {
        printf("Eres el estudiante %d\n", i + 1);

        printf("¿Cómo te llamas?\n");
        scanf(" %[^\n]", Estudiantes[i].nombre);//escanea un tipo de dato que recibe un char y lo guarda sin \n que aparce por lo general al scanear un dato, y lo almacena la direccion de la struct Estudiantes.nombre en el indice que representa el valor de i 
        // scanf(Estudiantes[i].nombre, 40, stdin);
        // Estudiantes[i].nombre[strcspn(Estudiantes[i].nombre, "\n")] = '\0';

        printf("¿Cuantos años tienes?\n");
        scanf("%d", &Estudiantes[i].edad);
        // while(getchar() != '\n'); //while de consumo

        printf("¿Cual fue tu promedio?\n");
        scanf("%f", &Estudiantes[i].promedio);
        // while(getchar() != '\n');
    }
    mostrarEstudiantes(Estudiantes, tam); //llamos la funicon pasamos como parametros la direccion de Estudiantes(en este cado un arreglo de struct, segundo parameto le pasamos la variable tam(que en este caso cumple con la condicion de ser una variable de tipo entero ))
    return 0;
}
