/*Nuevo ejercicio: intercambiar dos valores                                      
                                                                                    
     Objetivo: crear una función intercambiar que reciba dos punteros e             
     intercambie sus valores.                                                       
                                                                                    
     void intercambiar(int *a, int *b){                                             
         int temp = *a;                                                             
         *a = *b;                                                                   
         *b = temp;                                                                 
     }                                                                              
                                                                                    
     En main:                                                                       
                                                                                    
     1. Crear int x = 10 y int y = 25                                               
     2. Imprimir antes: x = 10, y = 25                                              
     3. Llamar intercambiar(&x, &y) — pasas direcciones                             
     4. Imprimir después: x = 25, y = 10                                            
                                                                                    
     Puntos clave:                                                                  
                                                                                    
     - La función recibe int * (punteros)                                           
     - Al llamar, usas &x y &y (direcciones)                                        
     - Dentro de la función, *a y *b acceden a los valores reales                   
     - La función modifica las variables originales, no copias    */
     # include <stdio.h>
     
     void intercambiar(int *a, int *b);

     int main(){
        int x = 10;
        int y = 25;
        printf("x es = %d Y y es = %d\n", x, y);
        intercambiar(&x, &y);
        printf("x es = %d Y y es = %d\n", x, y);
     }
     void intercambiar(int *a, int *b){
        int tem = *a;
        *a = *b;
        *b = tem;

        
     }