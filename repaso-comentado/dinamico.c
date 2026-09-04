#include <stdio.h>//scanf, printf
#include <stdlib.h>//memoria dinamica malloc y realloc

int main(){
    int cantidad; //crea la variable que guardara cuantos numeros se van a ingresar
    
    printf("Cuantos valores quiere ingresar\n"); //imprime el mensaje pidiendo la cantidad
    scanf("%d", &cantidad); //recibe un dato de tipo entero y guardalo en la direccion de memoria cantidad
    int* valor = malloc (cantidad * sizeof(int)); //operacion que calcula espacio en bytes que permitira registrar la cierta cantidad de datos en el array
    printf("Sus valores a agregar son: %d\n\nA continuación empiece a ingresarlos\n", cantidad); //imprime la cantidad y el mensaje de inicio
        
    for(int i = 0; i < cantidad; i++){
    scanf("%d", &valor[i]);//CICLO QUE PERMITE AGREGAR VALORES AL ARREGLO
        
    }
    for(int i = 0; i < cantidad; i++){
    printf("Numero %d: %d\n", i+1, valor[i]);//CICLO QUE MUESTRA POR PANTALLA 
    }//CADA UNO DE LOS ARREGLOS
    //ENCONTRA LE NUMERO MAYOR 
    int max = valor[0]; //se crea una variable que guardara el puntero de valor posicion 0
    for(int i = 1; i < cantidad; i++){
        if(valor[i] > max  ){//si la posicion i(1 + 1 e cada vuelta) es mayor que la posicion 0
           max = valor[i];   //maximo reescribira su dato como  la posicion (1 + 1 en cada vuelta)
        }     //como resultado max encontrara el numero mayor y por sus reescrituras guardara ese unico numero.
     }
     printf("El numero mayor de los que proporciono  es: %d\n", max); //imprime el numero mayor
    free(valor); //libera la memoria reservada con malloc
    return 0; //el programa termina bien
    
}
