#include <stdio.h>
int main(){
    int num;
    printf("Digite un numero: \n");
    scanf("%d", &num);

    if(num % 2 == 0 && num != 0){//si el reciduo de num dividido en 2 es igual a 0 y su vez num es diferente de 0 entonces
        printf("Paridad: Par\n");//imprime Paridad: par

        //evaluaremos una condicion interna
        if(num > 0){//si num es mayor a 0 entonces
            printf("signo: Positivo\n");//imprime singo positivo
        }
        else{//sino
            printf("signo: Negativo\n");//imprime
        }
    }
    else if(num % 2!= 0){// si la  condicion externa no se cumple revisa si esta operacion da un resultado diferente a  0 y si es asi
        printf("Paridad: impar\n");//imprime
        if(num < 0){
            printf("signo: Negativo\n");
        }
        else{
            printf("signo: positivo\n");
        }
        }
    else{
        printf("NUMERO 0");
    }
    return 0;
    //termina el programa bien 
    }
