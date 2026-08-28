/*
ARCHIVO DE COMPARACION - Muestra tu codigo original (con errores) 
COMENTADO, y al lado la version correcta para que veas la diferencia.
No se compila como programa; es una guia visual.
*/

/* ============================================================
   TU VERSION (la que tenia errores) - COMENTADA
   ============================================================ */

// En tu struct tenias un campo notas con doble puntero que no era
// parte del ejercicio. El struct correcto solo tiene los 3 campos.
/*
struct Alumno{
    char nombre[50];
    int edad;
    int **notas;   // <-- ERROR: sobraba. No lo pediamos. Solo debe haber:
    float promedio;    // nombre, edad, promedio
}
// <-- ERROR: faltaba el punto y coma (;) al final del struct
*/

// TU ERROR 1: el total lo calculabas con sizeof, que da 10 (la capacidad),
// no cuantos hay. Debe empezar en 0.
/*
int total = sizeof(alumnos) / sizeof(alumnos[0]);  // ERROR: esto da 10
int total = 0;                                     // CORRECTO: empieza en 0
*/

// TU ERROR 2: el switch lo ponias sobre alumnos, no sobre la opcion.
/*
switch (alumnos)   // <-- ERROR: no puedes evaluar el arreglo
switch (opcion)    // <-- CORRECTO: evaluas la opcion que el usuario escribio
*/

// TU ERROR 3: faltaba la variable opcion y su scanf
/*
// faltaba:
int opcion;
scanf("%d", &opcion);
*/

// TU ERROR 4: en AGREGAR usabas un for, pero solo se agrega UN alumno.
// El for es para listar, no para agregar.
/*
for(int i = 0; i < total; i++){   // ERROR: sobraba el for en agregar
    scanf(...);                    // solo se agrega a alumnos[total]
}
*/

// TU ERROR 5: en LISTAR estabas pidiendo datos con scanf, pero listar
// debe MOSTRAR, no leer.
/*
case 2:
    for(int i = 0; i < total; i++){
        scanf(...);   // <-- ERROR: esto es de agregar, no de listar
    }
*/

// TU ERROR 6: el scanf del nombre usaba %[^\n] con & delante del arreglo
/*
scanf(" %[^\n]", &alumnos[total].nombre);  // ERROR: el & sobra para arreglos
fgets(alumnos[total].nombre, 50, stdin);   // CORRECTO: fgets es mas seguro
*/

// TU ERROR 7: faltaban las llaves del do-while; el while quedaba suelto
/*
}          // cierra switch
while(opcion != 3);   // ERROR: quedaba fuera del do
}
/* 
   CORRECTO:
}while(opcion != 3);   // la llave del do y el while van JUNTOS
return 0;
}
*/


/* ============================================================
   VERSION CORRECTA (la que esta en Agenda.c ahora)
   ============================================================ */
/*
#include <stdio.h>
#include <string.h>

struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
};

int main(){
    struct Alumno alumnos[10];
    int total = 0;          // cuenta real de alumnos, empieza en 0
    int opcion;             // se declara AQUI, fuera del do, para que el while la vea

    do{
        printf("=== MENU ===\n");
        printf("1) Agregar alumno\n");
        printf("2) Listar alumnos\n");
        printf("3) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while(getchar() != '\n');   // limpia el Enter

        switch (opcion)
        {
        case 1:  // AGREGAR - sin for, un solo alumno
            if(total >= 10){
                printf("No hay espacio\n");
            }
            else{
                printf("Nombre: ");
                fgets(alumnos[total].nombre, 50, stdin);
                alumnos[total].nombre[strcspn(alumnos[total].nombre, "\n")] = '\0';
                printf("Edad: ");
                scanf("%d", &alumnos[total].edad);
                while(getchar() != '\n');
                printf("Promedio: ");
                scanf("%f", &alumnos[total].promedio);
                while(getchar() != '\n');
                total++;
            }
            break;

        case 2:  // LISTAR - usa for para MOSTRAR
            for(int i = 0; i < total; i++){
                printf("Alumno %d: %s, %d anos, %.2f\n",
                       i + 1, alumnos[i].nombre, alumnos[i].edad, alumnos[i].promedio);
            }
            break;

        case 3:
            printf("Nos vemos pronto\n");
            break;
        }

    }while(opcion != 3);   // el while va pegado al cierre del do

    return 0;
}
*/
