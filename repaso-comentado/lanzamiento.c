#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla
int main(){ //funcion madre de los programas
    int num; //crea una variable de tipo entero para guardar el numero que digita el usuario
    printf("Digita un numero\n"); //imprime el mensaje pidiendo el numero
    scanf("%d", &num); //recibe un dato de tipo entero y guardalo en la direccion de memoria num
    printf("El cohete cuenta...\n"); //imprime el texto del conteo
    int i = num; //crea una variable i de tipo entero que guarda el valor de num
    while(i > 0){ //mientras i sea mayor a 0 se repetira las instrucciones internas
        printf("%d\n", i); //imprime el valor de i en cada vuelta
        i--; //disminuye 1 a i al finalizar cada vuelta
    }
    if(num > 0){ //si num es mayor a 0 entonces
    printf("Despegue!."); //imprime despegue
    }
    else{ //si no
        printf("Lo sentimos un cohete no puede despegar sin pre-conteo :("); //imprime el mensaje de error
    }
    return 0; //el programa termina bien
    
    }
