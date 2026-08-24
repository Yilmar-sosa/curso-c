#include <stdio.h>
int main(){
    int segundosTotales;
    //Cada unidad equivale a un segundo
    int segundoEnSegundos = 1;
    int minutosEnSegundos = 60;
    int horaEnSEgundos = 60 * 60;
    
    printf("digita los segundos que quieres convertir: \n");
    scanf("%d", &segundosTotales);
    int sobrante = segundosTotales;
    
    
    //unidades reales de tiempo (conversion de segundos a unidades)
      int horas, minutos, segundos;
    
   while (segundosTotales > 0){ 
    if(sobrante >=horaEnSEgundos){
    horas = segundosTotales / horaEnSEgundos;
    sobrante = segundosTotales % horaEnSEgundos;
    printf("%d", sobrante);
    }
    else if(sobrante >= minutosEnSegundos){
        minutos = segundosTotales / minutosEnSegundos;
        sobrante = segundosTotales % minutosEnSegundos;
    }
    else if(sobrante >= segundoEnSegundos){
        segundos = segundosTotales / segundoEnSegundos;
        sobrante = segundosTotales % segundoEnSegundos;
    }
    printf("Horas: %d\nMinutos: %d\nSegundos: %d", horas, minutos, segundos);
    return 0;
}
}