#include <stdio.h>
int main(){
    int secreto = 42;
    int intento;
    int intentosTotales = 0;
    do{
        printf("Adivina el numero\n");
        scanf("%d", &intento);
        if( intento < secreto){
            printf("Muy abajo\nIntenta nuevamente\n");
        }
        else if( intento > secreto){
            printf("Muy arriba\nIntenta nuevamente\n");
        }
        intentosTotales ++;
    } while(intento != secreto);
    printf("Felicidades adivinaste el numero despues de %d intentos", intentosTotales);
    return 0;
}