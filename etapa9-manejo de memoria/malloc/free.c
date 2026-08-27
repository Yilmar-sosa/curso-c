#include <stdio.h>
#include <stdlib.h> //libreria que contiene funciones de memoria dinamica
int main(){
    printf("¿Cuantos elementos quieres almacenar?\n");
    int longitud; //Variable que recibira el numero por pantalla.
    scanf("%d", &longitud); //se escanea tipo de dato y direccion donde se alojara.

    float* valores = (float*) malloc (longitud * sizeof(float)); //ARRAY A PUNTERO QUE PIDE LA CANTIDAD DE MEMORIA QUE SE SOLICITA
    if(valores  == NULL){ //En caso de no tener memoria lo anterior devolvera NULL por lo que se crea una condicion para que reporte cuando eso pase
        printf("No tienes tanta memoria.\n");
        return 1; //SI SE CUMPLE LA CONDICON ANTERIOR SE TERMINA EL PROGRAMA
    }
    for (int i = 0; i < longitud; i++){//UN CICLO QUE NOS RECORRERA LA VARIABLE VALORES
        valores[i] = 5.55E5;//NOTACION CIENTIFICA-NOTACION EXPONECIAL
    }
    printf("Todo esta correcto\n"); 
    free(valores); //SE LIBERA EL ESPACIO DE MEMORIA QUE SE HABIA ASIGNADO A VALORE
}