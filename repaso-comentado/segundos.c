#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main(){ //funcion madre de los programas
    int segundosTotales, restante; //crea dos variables de tipo entero para los segundos y el sobrante

    printf("Digite sus segundos\n"); //imprime el mensaje pidiendo los segundos
    scanf("%d", &segundosTotales); //recibe un dato de tipo entero y guardalo en la direccion de memoria segundosTotales
    //Cada unidad equivale a un segundo
    int horas = segundosTotales / 3600; //horas sera igual a la division de los segundos entre 3600 (un minuto son 60s, una hora 3600s)
    restante = segundosTotales % 3600; //restante guarda el sobrante de esa division
    int minutos = restante / 60; //minutos sera igual al sobrante dividido en 60
    restante = restante % 60; //restante guarda el nuevo sobrante
    int segundos = restante; //los segundos finales son el sobrante
       printf("Horas: %d\nMinutos: %d\nSegundos: %d", horas, minutos, segundos); //imprime el resultado de las conversiones
    return 0; //el programa termina bien
}
