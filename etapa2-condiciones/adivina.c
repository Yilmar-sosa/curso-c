#include <stdio.h>
int main(){
    int secreto = 42;
    int intento;
    int intentosTotales = 0;
    do{//ejecuta estas instrucciones al menos una vez
        printf("Adivina el numero\n");
        scanf("%d", &intento);
        if( intento < secreto){
            printf("Muy abajo\nIntenta nuevamente\n");
        }
        else if( intento > secreto){
            printf("Muy arriba\nIntenta nuevamente\n");
        }
        intentosTotales ++;
    } while(intento != secreto);//si esta condicion se cumple ejecuta las instruccines anteriores ciclicamente hasta que deje de cumplir la condicion
    printf("Felicidades adivinaste el numero despues de %d intentos", intentosTotales);
    return 0;
}