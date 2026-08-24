#include <stdio.h>

int main() {
    int num;

    printf("Digite un numero: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("El numero es cero\n");
        return 0;
    }

    if (num % 2 == 0) {
        printf("Paridad: Par\n");
    } else {
        printf("Paridad: Impar\n");
    }

    if (num > 0) {
        printf("Signo: Positivo\n");
    } else {
        printf("Signo: Negativo\n");
    }

    return 0;
}
