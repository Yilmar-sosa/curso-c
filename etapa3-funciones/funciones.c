/*     🏋️ Ejercicio 3: Tu primera fábrica                                             
                                                                                    
     Crea funciones.c en una carpeta nueva etapa3-funciones/ (ya estamos en etapa   
     nueva, ordenaditos desde el inicio 😄):                                        
                                                                                    
     1. Escribe la función suma del ejemplo.                                        
     2. Escribe resta(int a, int b) tú solo.                                        
     3. En main: pide dos números al usuario, y muestra su suma y su diferencia     
        usando las funciones — prohibido hacer a + b directo en el main.            
     4. Extra: agrega multiplicacion y observa qué tienen en común las tres.        */

     #include <stdio.h>
     int suma(int a, int b);
     int resta(int a, int b);
     int multiplicacion(int a, int b);
     
     
     int main(){
        int num1, num2;
        printf("Escribe tu primer numero\n");
        scanf("%d", &num1);
        printf("Escribe tu segundo numero\n");
        scanf("%d", &num2);
        printf("%d + %d = %d\n", num1, num2, suma(num1, num2));
        printf("%d - %d = %d\n", num1, num2, resta(num1, num2));
        printf("%d * %d = %d\n", num1, num2, multiplicacion(num1, num2));
        return 0;
     }   
      int suma(int a, int b){
        return a + b;
     }
     int resta(int a, int b){
        return a - b;
     }
     int multiplicacion(int a, int b){
        return a * b;      
     }             



        