#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main(){ //funcion madre de los programas
    int notas[5]; //crea un arreglo de 5 enteros para guardar las notas
    int suma = 0; //crea un acumulador de suma con valor inicial 0
    float promedio = 0; //crea una variable flotante para el promedio
    int i; //declara la variable i para el for
    printf("Escribe tus notas para que podamos sacar tu promedio\n"); //imprime el mensaje pidiendo las notas
    for(i = 0; i < 5; i++){ //el contador i inicia en 0, se repite mientras i sea menor a 5, y aumenta 1 por vuelta
        scanf("%d", &notas[i]); //recibe un dato entero y guardalo en la posicion i del arreglo
        suma = suma + notas[i]; //suma acumula cada nota leida
    }
    printf("Nota 1: %d\n", notas[0]); //imprime la nota de la posicion 0
    printf("Nota 2: %d\n", notas[1]); //imprime la nota de la posicion 1
    printf("Nota 3: %d\n", notas[2]); //imprime la nota de la posicion 2
    printf("Nota 4: %d\n", notas[3]); //imprime la nota de la posicion 3
    printf("Nota 5: %d\n", notas[4]); //imprime la nota de la posicion 4
    promedio = (float)suma / i; //promedio es la suma convertida a float dividida entre i (5 notas)
    printf("Promedio: %.2f\n", promedio); //imprime el promedio con 2 decimales

    int max = notas[0]; //el maximo empieza siendo la primera nota
    for(int e = 1; e < 5; e++){ //recorre desde la posicion 1 hasta la 4
        if(notas[e] > max){ //si la nota actual es mayor al maximo entonces
            max = notas[e]; //el maximo se actualiza a esa nota
        }
    }
    printf("La nota mayor es: %d\n", max); //imprime la nota mayor

    int min = notas[0]; //el minimo empieza siendo la primera nota
    for(int e = 1; e < 5; e++){ //recorre desde la posicion 1 hasta la 4
        if(notas[e] < min){ //si la nota actual es menor al minimo entonces
            min = notas[e]; //el minimo se actualiza a esa nota
        }
    }
    printf("La nota menor es: %d\n", min); //imprime la nota menor

    return 0; //el programa termina bien
}
