#include <stdio.h> //incluye la libreria que permite escanear e imprimir en pantalla

int main(){ //funcion madre de los programas
    char nombre[50]; //crea un arreglo de 50 caracteres para guardar el nombre
    int edad; //crea la variable que guardara la edad

    printf("¿Cómo te llamas\n?"); //imprime el mensaje pidiendo el nombre
    scanf(" %[^\n]", nombre); //recibe todo hasta un salto de linea (permite espacios) y guardalo en nombre

    printf("¿Cuantos años tiene\n"); //imprime el mensaje pidiendo la edad
    scanf("%d", &edad); //recibe un dato de tipo entero y guardalo en la direccion de memoria edad

    FILE *Archivos = fopen("datos.txt", "w"); //abre el archivo datos.txt en modo escritura (lo borra y recrea), o no, devuelve NULL si falla
    fprintf(Archivos, "%s %d\n", nombre, edad); //escribe en el archivo el nombre y la edad
    fclose(Archivos); //cierra el archivo (guarda los cambios)

    FILE *Arch = fopen("datos.txt", "r"); //abre el archivo datos.txt en modo lectura
    char linea[100]; //crea un arreglo de 100 caracteres para guardar una linea
    fgets(linea, 100, Arch); //lee una linea del archivo y guardala en linea
    printf("Contenido: %s", linea); //imprime el contenido leido
    fclose(Arch); //cierra el archivo

}
