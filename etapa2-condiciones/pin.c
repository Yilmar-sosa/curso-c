#include <stdio.h>
int main(){
    int pinCorrecto = 4321;
    int pin;
    int intentos = 0;
    do{
        printf("Ingresa tu pin\n");
        scanf("%d", &pin);
        if(pin < 1000 || pin > 9999 ){ 
            printf("Este numero no es valido, no contiene 4 digitos\n");
        }
        else if(pin != pinCorrecto){ 
            printf("Acceso denegado\n");
            intentos ++;
        }


    }while(!(pin == pinCorrecto));

    intentos ++;
    printf("Acceso concedido\nHizo un numero total de intentos %d\n", intentos);
    return 0;
}