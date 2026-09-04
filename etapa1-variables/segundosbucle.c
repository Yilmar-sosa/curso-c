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
    
   while (segundosTotales > 0){ //mientras seguntosTotales sea mayor a 0 se repetira las instrucciones internas
    if(sobrante >=horaEnSEgundos){//si sobrante es mayor 0 igual a horas entonces
    horas = segundosTotales / horaEnSEgundos;//horas sera igual a la division de estas dos variables
    sobrante = segundosTotales % horaEnSEgundos;//la variable sobrante recibira el valor de la operacion matematica de estas dos variables
    printf("%d", sobrante);//imprime la variable sobrante 
    }
    else if(sobrante >= minutosEnSegundos){//si la anterior condicion no se cumple revisamos esta y si se cumple entonces hacemos los siguiente
        minutos = segundosTotales / minutosEnSegundos;//guardamos esta division en la variable minutos
        sobrante = segundosTotales % minutosEnSegundos;//guardamos el resultado de una operacion de modulo en sobrante
    }
    else if(sobrante >= segundoEnSegundos){//si la anterior tampoco se cumple revisamos si esta si se cumple y ejecutamos sus instrucciones internas
        segundos = segundosTotales / segundoEnSegundos;
        sobrante = segundosTotales % segundoEnSegundos;
    }
    printf("Horas: %d\nMinutos: %d\nSegundos: %d", horas, minutos, segundos);
    return 0;
}
}