/*
ARCHIVO: Agenda.c (version funcional + tus errores comentados para comparar)
Este archivo SÍ compila y funciona. Cada bloque "TÚ ESCRIBISTE" muestra tu
error original comentado, y debajo la corrección que se usa. Así ves qué
estaba mal y por qué, en el mismo archivo funcional.
*/

#include <stdio.h>
#include <string.h>

struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
};
/* TU ESCRITE: el struct tenia un campo int **notas que sobraba
struct Alumno{
    char nombre[50];
    int edad;
    int **notas;    // <-- ERROR 1: no era parte del ejercicio, sobraba
    float promedio;
}                   // <-- ERROR 2: faltaba el punto y coma (;) al final
*/

int main(){
    struct Alumno alumnos[10];   // arreglo fijo de 10
    int total = 0;               // cuenta real de alumnos
    int opcion;                  // se declara aqui (fuera del do) para el while

    /* TÚ ESCRIBISTE (ERROR 3): total daba 10, no 0
    int total = sizeof(alumnos) / sizeof(alumnos[0]);   // 10 = capacidad, no cuantos hay
    int total = 0;                                      // 0 = cuantos hay ahora  CORRECTO
    */

    printf("Bienvenido a la agenda de alumnos\n\n");

    do{
        printf("=== MENU ===\n");
        printf("1) Agregar alumno\n");
        printf("2) Listar alumnos\n");
        printf("3) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while(getchar() != '\n');   // limpia el Enter que deja scanf

        /* TÚ ESCRIBISTE (ERROR 4 y 5):
        switch (alumnos)   // ERROR 4: no evaluabas la opcion sino el arreglo
        {                  // y faltaba la variable opcion + su scanf
            ...
        }while(alumnos != 3);   // ERROR 5: comparabas el arreglo, no la opcion
        CORRECTO (se usa abajo): switch(opcion) ... }while(opcion != 3);
        */

        switch (opcion)
        {
        case 1:  // AGREGAR
            if(total >= 10){
                printf("No hay espacio, ya hay 10 alumnos\n");
            }
            else{
                /* TÚ ESCRIBISTE (ERROR 6): usabas un for para agregar UN alumno
                for(int i = 0; i < total; i++){   // sobra: solo se agrega a alumnos[total]
                    scanf(" %[^\n]", &alumnos[i].nombre);   // el & sobra en arreglos (ERROR 7)
                    scanf("%d", alumnos[i].edad);           // falta &  (ERROR 8)
                    scanf("%d", &alumnos[i].promedio);      // %d deberia ser %f (ERROR 9)
                }
                CORRECTO (abajo): sin for, con total como indice, fgets para el nombre,
                & para edad, %f para promedio.
                */
                printf("\n-- Agregando alumno %d --\n", total + 1);

                printf("Nombre: ");
                fgets(alumnos[total].nombre, 50, stdin);
                alumnos[total].nombre[strcspn(alumnos[total].nombre, "\n")] = '\0';

                printf("Edad: ");
                scanf("%d", &alumnos[total].edad);
                while(getchar() != '\n');

                printf("Promedio: ");
                scanf("%f", &alumnos[total].promedio);
                while(getchar() != '\n');

                total++;   // ahora hay un alumno mas
                printf("Alumno guardado. Total: %d\n\n", total);
            }
            break;

        case 2:  // LISTAR
            if(total == 0){
                printf("\nNo hay alumnos registrados todavia\n\n");
            }
            else{
                /* TÚ ESCRIBISTE (ERROR 10): en LISTAR pedias datos con scanf.
                Listar debe MOSTRAR, no leer.
                for(int i = 0; i < total; i++){
                    scanf(...);   // <-- eso era de AGREGAR, no de listar
                }
                CORRECTO (abajo): usar printf para mostrar cada campo por separado,
                con %s para nombre y %f para promedio.
                */
                printf("\n-- Lista de alumnos --\n");
                for(int i = 0; i < total; i++){
                    printf("Alumno %d: %s, %d anos, promedio %.2f\n",
                           i + 1, alumnos[i].nombre, alumnos[i].edad, alumnos[i].promedio);
                }
                printf("\n");
            }
            break;

        case 3:  // SALIR
            printf("Nos vemos pronto\n");
            break;

        default:
            printf("Opcion incorrecta, intenta de nuevo\n\n");
            break;
        }

    }while(opcion != 3);

    return 0;
}
