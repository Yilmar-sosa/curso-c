#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
void mostrarNotas(int notas[], int tamano); //prototipo: muestra las notas, recibe el arreglo y su tamanio
float calcularPromedio(int notas[], int tamano); //prototipo: calcula el promedio, recibe el arreglo y su tamanio, devuelve float
int encontrarMaximo(int notas[], int tamano); //prototipo: encuentra el maximo, devuelve int
int encontrarMinimo(int notas[], int tamano); //prototipo: encuentra el minimo, devuelve int
int main(){ //funcion madre de los programas
    int notas[5]; //crea un arreglo de 5 enteros para guardar las notas
    int tamano = sizeof(notas)/ sizeof(notas[1]); //tamano guarda cuantos elementos tiene el arreglo
    
    printf("Escribe tus notas para que podamos sacar tu promedio\n"); //imprime el mensaje pidiendo las notas
    for(int i = 0; i < tamano; i++){ //el contador i inicia en 0, se repite mientras i sea menor a tamano, y aumenta 1 por vuelta
     scanf("%d", &notas[i]); //recibe un dato entero y guardalo en la posicion i del arreglo
    }
    mostrarNotas(notas, tamano); //llama a la funcion que muestra las notas
    calcularPromedio(notas, tamano); //llama a la funcion que calcula el promedio
    encontrarMaximo(notas, tamano); //llama a la funcion que encuentra el maximo
    encontrarMinimo(notas, tamano); //llama a la funcion que encuentra el minimo
   
    return 0; //el programa termina bien
}
// FUNCION PARA MOSTRAR NOTAS
void mostrarNotas(int notas[], int tamano){ //definicion: muestra las notas, recibe el arreglo y su tamanio, no retorna
    int numerador = 1; //crea un contador que va numerando las notas
    for(int i = 0; i < tamano; i++){ //el contador i inicia en 0, se repite mientras i sea menor a tamano, y aumenta 1 por vuelta
    printf("Nota %d: %d\n", numerador, notas[i]); //imprime el numero de la nota y su valor
    numerador++; //aumenta 1 al numerador
}
}
 

//FUNCION DE PROMEDIO
float calcularPromedio(int notas[], int tamano){ //definicion: calcula el promedio, recibe el arreglo y su tamanio, devuelve float
    int suma = 0; //crea un acumulador de suma con valor inicial 0
    float promedio = 0; //crea la variable flotante para el promedio

    for(int i = 0; i < tamano; i++){ //el contador i inicia en 0, se repite mientras i sea menor a tamano, y aumenta 1 por vuelta
        suma = suma + notas[i]; //suma acumula cada nota
    }
    promedio = (float)suma / tamano; //promedio es la suma convertida a float dividida entre tamano
    printf("Promedio: %.2f\n", promedio); //imprime el promedio con 2 decimales
   return promedio; //devuelve el promedio
}
//FUNCION PARA ENCONTRAR NUMERO MAXIMO
int encontrarMaximo(int notas[], int tamano){ //definicion: encuentra el maximo, recibe el arreglo y su tamanio, devuelve int
    int max = notas[0]; //el maximo empieza siendo la primera nota
    for(int e = 1; e < tamano; e++){ //recorre desde la posicion 1 hasta el final
        if(notas[e] > max){ //si la nota actual es mayor al maximo entonces
            max = notas[e]; //el maximo se actualiza a esa nota
        }
    }
    printf("La nota mayor es: %d\n", max); //imprime la nota mayor
    return max; //devuelve el maximo
}
//FUNCION PARA ENCONTRAR MINIMO
int encontrarMinimo(int notas[], int tamano){ //definicion: encuentra el minimo, recibe el arreglo y su tamanio, devuelve int
    int min = notas[0]; //el minimo empieza siendo la primera nota
        for(int e = 1; e < tamano; e++){ //recorre desde la posicion 1 hasta el final
            if(notas[e] < min){ //si la nota actual es menor al minimo entonces
                min = notas[e]; //el minimo se actualiza a esa nota
            }
    }
    printf("La nota menor es: %d\n", min); //imprime la nota menor
    return min; //devuelve el minimo
}
