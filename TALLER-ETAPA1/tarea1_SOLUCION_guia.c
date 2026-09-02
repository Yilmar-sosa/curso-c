/*
 * ============================================================================
 *  TAREA 1 — TALLER RUTA 1  |  SOLUCIÓN-GUÍA (con traducción línea a línea)
 * ============================================================================
 *  PROPÓSITO DE ESTE ARCHIVO:
 *    Es UNA SOLUCIÓN de referencia que pediste para estudiar. Está deliberadamente
 *    aparte de tu archivo (primernombre_apellido_tarea1.c) para no pisar tu código.
 *    Mañana, inténtalo SOLO con la lógica que te quede grabada; esta guía queda
 *    como material de consulta y comparación.
 *
 *  ENUNCIADO ORIGINAL:
 *    Implementa un programa en C que lea el archivo binario e imprima los nombres,
 *    edades y géneros de todos los estudiantes dentro de un rango de edades.
 *    El rango de edades y el nombre del archivo binario se proporcionarán como
 *    argumentos de línea de comandos.
 *
 *  ESTRUCTURA DEL BINARIO (VERIFICADA contra sample_data.bin):
 *    [Encabezado, 14 bytes]
 *      uint16 magic        (2 bytes)  -> el archivo guarda los bytes "aa ae"
 *        escrito "de humano" es 0xAAAE; al leerlo en tu maquina little-endian
 *        quedaria 0xAEAA (ver comentarios en PASO 3)
 *      uint32 studentCount (4 bytes)  -> 1000
 *      uint32 courseCount  (4 bytes)  -> 50
 *      uint32 enrollCount  (4 bytes)  -> 12060
 *    [Luego 1000 estudiantes, 32 bytes cada uno]
 *      uint32        id      (4 bytes)
 *      unsigned char flags  (1 byte)   -> bit 7 = género (1=MUJER, 0=HOMBRE)
 *      char          nombre[23] (23 bytes)
 *      uint32        edad    (4 bytes)
 *    Después vienen cursos y matrículas; NO los necesitamos para esta tarea.
 *
 *  CÓMO EJECUTARLO (linea de comandos / bash):
 *    gcc -Wall -Wextra -g tarea1_SOLUCION_guia.c -o tarea1_SOLUCION_guia.exe
 *    ./tarea1_SOLUCION_guia.exe sample_data.bin 18 20
 *      argv[0]=programa, argv[1]=archivo, argv[2]=edad minima, argv[3]=edad maxima
 *    (Si el enunciado de tu taller pide otro orden de argumentos, cambia las
 *     líneas con "argv" y listo.)
 * ============================================================================
 */

#include <stdio.h>   /* Trae la "ficha" (prototipos) de: fopen, fread, fclose, printf */
#include <stdlib.h>  /* Trae la "ficha" de: atoi (convierte texto a numero int)      */
#include <stdint.h>  /* Trae los tipos de tamaño fijo: uint16_t y uint32_t           */

int main(int argc, char *argv[]) {
    /* argc = CUANTOS argumentos escribio en la terminal (contando el programa).
       argv = UN ARREGLO de cadenas; cada posicion es un argumento.
       argv[0] = "tarea1_SOLUCION_guia.exe" (el nombre del propio programa).          */

    /* ---------------- PASO 1: validar que llegaron los 4 argumentos ----------------
       Si el usuario escribio menos argumentos de los que hace falta, avisar como
       usar el programa y terminar. (Guard clause: salir temprano si falta algo.)     */
    if (argc != 4) {
        /* printf imprime en pantalla el texto que esta entre comillas.
           %s se reemplaza por un texto, %d por un numero entero.
           El \\n es "salto de linea" (cursor baja a la siguiente fila).
                                                                                      */
        printf("Uso: %s <archivo.bin> <edadMin> <edadMax>\n", argv[0]);
        /* Le paso argv[0] para que el mensaje siempre muestre el nombre real
           del programa, aunque alguien lo renombre.                                    */
        return 1;   /* 1 = le aviso al sistema operativo que el programa termino MAL */
    }

    /* ---------------- PASO 2: abrir el archivo binario en modo LECTURA ----------------
       "r"  = read  (leer).
       "b"  = binary: que Windows NO aplique trucos con saltos de linea.
       fopen DEVUELVE la direccion de una estructura FILE, o NULL si no pudo.           */
    FILE *archivo = fopen(argv[1], "rb");

    /* El resultado de fopen siempre hay que comprobarlo: NULL = fallo (el archivo
       no existe, no hay permisos, etc.).                                               */
    if (archivo == NULL) {
        /* %s imprime el nombre del archivo que vino en argv[1].                        */
        printf("Error: no se pudo abrir el archivo %s\n", argv[1]);
        return 1;   /* Salir con codigo de error.                                       */
    }

    /* ---------------- PASO 3: leer el encabezado (14 bytes) ----------------
       Lo leemos aunque no lo usemos, porque es OBLIGATORIO avanzar el "puntero de
       lectura" del archivo hasta donde empiezan los estudiantes. Si no leyera el
       encabezado, el primer estudiante que lea seria basura.                          */
    uint16_t magic;
    uint32_t studentCount, courseCount, enrollCount;

    /* fread(memoria, tamano, cantidad, archivo):
       1er argumento = a DONDE guardar lo leido (direcciones de las variables).
       2do = cuantos bytes mide cada dato.
       3ro = cuantos datos quiere leer.
       4to = de que archivo.                                                           */
    fread(&magic,         sizeof(magic),         1, archivo);  /* leo 2  bytes: identificador */
    fread(&studentCount,  sizeof(studentCount),  1, archivo);  /* leo 4  bytes: total alumnos  */
    fread(&courseCount,   sizeof(courseCount),   1, archivo);  /* leo 4  bytes: total cursos   */
    fread(&enrollCount,   sizeof(enrollCount),   1, archivo);  /* leo 4  bytes: total matricula*/

    /* Balance de lectura SOLO para verificar que entendimos el archivo.
       Si la terminal muestra 1000 / 50 / 12060, el encabezado se leyo bien.
       %u = numero entero SIN signo (uint32_t).                                          */
    printf("Encabezado correcto: %u estudiantes, %u cursos, %u matriculas\n",
           studentCount, courseCount, enrollCount);

    /* ---------------- PASO 4: convertir los argumentos de edad a numeros ----------------
       argv[2] y argv[3] son TEXTOS (ej: "18"). atoi los convierte en un numero
       (ej: 18) para poder compararlos con la edad de cada estudiante.
       Los declaro SIN signo (unsigned) para que la comparacion con la edad
       (que tambien es sin signo) no genere warnings del compilador.                    */
    unsigned int edadMin = atoi(argv[2]);
    unsigned int edadMax = atoi(argv[3]);

    /* ---------------- PASO 5: recorrer los 1000 estudiantes y filtrar ----------------
       Las variables se declaran FUERA del bucle para reutilizarlas en cada vuelta.
       (Si se declararan dentro, se crearian y destruirian 1000 veces.)                 */
    uint32_t id, edad;
    unsigned char flags;      /* 1 byte con bits que guardan informacion extra          */
    char nombre[23];          /* arreglo de 23 chars = espacio para el nombre           */
    unsigned int i;           /* contador de vueltas del bucle                          */

    /* for = bucle con 3 casillas:
       (1) i = 0           : al principio, empieza en 0
       (2) i < studentCount: sigue mientras i sea MENOR que 1000 (posiciones 0..999)
       (3) i++             : al final de cada vuelta, suma 1 a i                        */
    for (i = 0; i < studentCount; i++) {
        /* Leo los 4 campos de UN estudiante, en el ORDEN REAL del archivo.
           Devuelve la cantidad de datos leidos; si fuera MENOR a la esperada,
           el archivo termino antes de tiempo. (No la comprobamos, por simplicidad.)    */
        fread(&id,      sizeof(id),     1, archivo);  /* leo su id   (4 bytes)          */
        fread(&flags,   sizeof(flags),  1, archivo);  /* leo su flags(1 byte)           */
        fread(nombre,   sizeof(nombre), 1, archivo);  /* leo su nombre (23 bytes):
           NOTA: nombre NO lleva & porque un arreglo YA es una direccion de memoria;
           &nombre seria "la direccion de la caja", que no es lo que pide fread.         */
        fread(&edad,    sizeof(edad),   1, archivo);  /* leo su edad (4 bytes)          */

        /* ---------------- PASO 6: filtro de edad + genero ----------------
           Condicion compuesta con && ("Y"): se cumple solo si la edad es
           MAYOR O IGUAL que el minimo Y MENOR O IGUAL que el maximo.
           El rango es INCLUSIVO (incluye ambos limites), como pide el enunciado.       */
        if (edad >= edadMin && edad <= edadMax) {
            /* Descifro el genero desde el bit 7 del flags:
               el operador & (AND de bits) "enciende" solo el bit que preguntamos.
               Si (flags & 0x80) da distinto de cero, ese bit esta activo -> MUJER.      */
            char genero = (flags & 0x80) ? 'F' : 'M';
            /* (condicion) ? valorSiVerdadero : valorSiFalso  -> operador ternario.     */

            /* Imprimo el estudiante que paso el filtro.
               %s = texto (nombre) | %u = numero sin signo (edad) | %c = caracter.
               -23 en %-23s alinea el texto a la izquierda en 23 columnas (formato bonito)*/
            printf("%-23s Edad: %-3u Genero: %c\n", nombre, edad, genero);
        }
    }   /* Fin del bucle: i++ -> comprueba i < studentCount -> ... hasta 999 */

    /* ---------------- PASO 7: cerrar el archivo ----------------
       Todo archivo que se abre CON fopen debe cerrarse CON fclose, para liberar
       el recurso y asegurar que no quede nada pendiente de escribir.                   */
    fclose(archivo);

    return 0;   /* 0 = el programa termino BIEN */
}