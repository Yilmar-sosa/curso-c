#include <stdio.h>
int main(){
    int num;
    printf("Digite un numero: \n");
    scanf("%d", &num);

    if(num % 2 == 0 && num != 0){
        printf("Paridad: Par\n");
        if(num > 0){
            printf("signo: Positivo\n");
        }
        else{
            printf("signo: Negativo\n");
        }
    }
    else if(num % 2!= 0){
        printf("Paridad: impar\n");
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
    }
