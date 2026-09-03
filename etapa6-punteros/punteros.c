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
     # include <stdio.h>//incluye libreria contiene scanf y printf
     
     void intercambiar(int *a, int *b);//avisale al compilador que esta funcion existe

     int main(){
        int x = 10; 
        int y = 25;
        printf("x es = %d Y y es = %d\n", x, y);
        intercambiar(&x, &y);//Entrega a la funcion intercambiar dos parametros que contienen la direccion de las variables
        printf("x es = %d Y y es = %d\n", x, y);
     }
     //funcion que intercambia valor que recibe por ubicaciones de variables
     //se necesita un cambo libre para transcribir los datos y no sobreescribir ninguno en el proceso
     void intercambiar(int *a, int *b){//crea funcion vallada intercambiar que no retorna valores(recibe la ubicacion de la variable a, y la ubicacion de la variable b)
        int tem = *a;//variable tipo int se le asigna el valor ubicado en la variable a
        *a = *b; //al valor apuntado por a asignale el valor apunta por b
        *b = tem;//apunta al valor de b y asignale el valor de tem

        
     }