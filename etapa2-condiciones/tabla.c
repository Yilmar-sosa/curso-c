#include <stdio.h>
int main(){
    int num;
    printf("Escribe el numero de la tabla de multiplicar que deseas\n");
    scanf("%d", &num);

    for(int i = 1; i < 11; i++){
    int multiplicacion = num * i;
    printf("%d x %d = %d\n", num, i, multiplicacion);
    }
    return 0;
}