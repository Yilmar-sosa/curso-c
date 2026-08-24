#include <stdio.h>
int main(){
    int num1, num2, num3;
    printf("Digita un numero: \n");
    scanf("%d", &num1);
    printf("Digita un segundo numero: \n");
    scanf("%d", &num2);
    printf("Digita un tercer numero: \n");
    scanf("%d", &num3);

    if(num1 > num2 && num1 > num3){
        printf("El numero %d es el numero mayor", num1);
    }
    else if(num2 > num1 && num2 > num3){
        printf("El numero %d es el numero mayor", num2);

        }
    else if(num1 == num2 && num2 >= num3){
        printf("El numero %d es el numero mayor", num1);
    }
    else{
            printf("El numero %d es el numero mayor", num3);
        }
    return 0;
    }
