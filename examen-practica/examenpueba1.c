/*
EXAMEN PRUEBA 1 - "Longest Word" (estilo coderbyte)
Encontrar la palabra MAS LARGA de una frase, ignorando puntuacion.

CODIGO ORIGINAL DEL ESTUDIANTE (este compila y sus 2 casos de ejemplo pasan).
Nota: coderbyte reemplaza coderbyteInternalStdinFunction(stdin) por la lectura
del INPUT real del test; aqui no compila tal cual, se prueba de forma local.

CASOS DE EJEMPLO (verificados):
  "fun&!! time"   -> time
  "I love dogs"   -> love  (empate de 4 letras, toma la PRIMERA mas larga)

MEJORAS PENDIENTES por revisar:
  - isalnum() acepta digitos (0-9) como letras. Si el enunciado dice "solo
    letras", usar isalpha() en su lugar.
  - Casos limites: string vacio, todo puntuacion -> imprime nada (OK, suele pasar).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void LongestWord(char * sen){
  int longitud = strlen(sen);

  char palabraActual[longitud + 1];
  char palabraLarga[longitud + 1];

  palabraActual[0] = '\0';
  palabraLarga[0] = '\0';

  int j = 0;

  /* Recorre cada caracter. Si es letra/digito (isalnum), lo agrega a la
     palabra actual (palabraActual). Si es otra cosa (espacio, puntuacion),
     compara la palabra terminada con la mas larga guardada (palabraLarga)
     y resetea palabraActual para la siguiente palabra. */
  for(int i = 0; i <= longitud; i++)
     if(isalnum(sen[i])){
       palabraActual[j] = sen[i];
       j++;
       palabraActual[j] = '\0';
     }
     else{
      /* Guardo solo si la palabra actual es MAYOR que la guardada.
         Con `>` (no `>=`) en caso de empate se mantiene la PRIMERA. */
      if(strlen(palabraActual) > strlen(palabraLarga)){
      strcpy(palabraLarga, palabraActual);
     }
      j = 0;
      palabraActual[0] = '\0';

  }

  printf("%s", palabraLarga);

}

int main(void) {

  LongestWord(coderbyteInternalStdinFunction(stdin));
  return 0;

}
