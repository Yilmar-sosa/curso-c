#include <stdio.h>
int main (){
    int num1, num2;
printf("Digita tu primer numero\n");
scanf("%d", &num1);
printf("Digita tu segundo numero\n");
scanf("%d", &num2);
    int sum = num1 + num2;
    int rest = num1 - num2;
    int Mult = num1 * num2;
    float Div = (float)num1 / num2;
    int resto = num1 % num2;


printf("Suma: %d\nResta: %d\nMultiplicacion: %d\nDivision: %.2f\nModulo: %d",sum, rest, Mult, Div, resto);
return 0;

}