#include <stdio.h>
int main(){
    int segundosTotales, restante;

    printf("Digite sus segundos\n");
    scanf("%d", &segundosTotales);
    //Cada unidad equivale a un segundo
    int horas = segundosTotales / 3600;
    restante = segundosTotales % 3600;
    int minutos = restante / 60;
    restante = restante % 60;
    int segundos = restante;
       printf("Horas: %d\nMinutos: %d\nSegundos: %d", horas, minutos, segundos);
    return 0;
}
