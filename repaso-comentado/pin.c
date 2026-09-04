#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main(){ //funcion madre de los programas
    int pinCorrecto = 4321; //crea la variable que guarda el pin correcto (4 digitos)
    int pin; //crea la variable que guardara el pin que digita el usuario
    int intentos = 0; //crea un contador de intentos con valor inicial 0
    do{ //ejecuta estas instrucciones al menos una vez
        printf("Ingresa tu pin\n"); //imprime el mensaje pidiendo el pin
        scanf("%d", &pin); //recibe un dato de tipo entero y guardalo en la direccion de memoria pin
        if(pin < 1000 || pin > 9999 ){ //si el pin es menor a 1000 O es mayor a 9999 entonces (no tiene 4 digitos)
            printf("Este numero no es valido, no contiene 4 digitos\n"); //imprime el mensaje de error
        }
        else if(pin != pinCorrecto){ //si el pin es diferente al pin correcto entonces
            printf("Acceso denegado\n"); //imprime que el acceso fue denegado
            intentos ++; //aumenta 1 al contador de intentos
        }


    }while(!(pin == pinCorrecto)); //repite mientras el pin sea diferente al pin correcto (el ! invierte la condicion)

    intentos ++; //aumenta 1 al contador porque el intento final correcto tambien cuenta
    printf("Acceso concedido\nHizo un numero total de intentos %d\n", intentos); //imprime el acceso concedido y el numero de intentos
    return 0; //el programa termina bien
}
