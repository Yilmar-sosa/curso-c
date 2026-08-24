#include <stdio.h>
int main(){
    int num;
    printf("Digita un numero\n");
    scanf("%d", &num);
    printf("El cohete cuenta...\n");
    int i = num;
    while(i > 0){
        printf("%d\n", i);
        i--;
    }
    if(num > 0){
    printf("Despegue!.");
    }
    else{
        printf("Lo sentimos un cohete no puede despegar sin pre-conteo :(");
    }
    return 0;
    
    }
