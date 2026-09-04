/*                                                                               
     🏋️ Ejercicio: etapa9-memoria/dinamico.c                                        
                                                                                    
     1. Pedir al usuario cuántos números quiere ingresar                            
     2. Reservar memoria para esa cantidad con malloc                               
     3. Leer esa cantidad de números                                                
     4. Mostrar cuál es el máximo                                                   
     5. Liberar la memoria con free                                                 
                                                                                    
     Salida esperada:                                                               
                                                                                    
     ¿Cuántos números vas a ingresar? 4                                             
     Número 1: 15                                                                   
     Número 2: 8                                                                    
     Número 3: 42                                                                   
     Número 4: 7                                                                    
     El máximo es: 42   */

     #include <stdio.h>//scanf, printf
     #include <stdlib.h>//memoria dinamica malloc y realloc

     int main(){
        int cantidad;
        
    

        printf("Cuantos valores quiere ingresar\n");
        scanf("%d", &cantidad);
        int* valor = malloc (cantidad * sizeof(int)); //operacion que calcula espacio en bytes que permitira registrar la cierta cantidad de datos en el array
        printf("Sus valores a agregar son: %d\n\nA continuación empiece a ingresarlos\n", cantidad);
        
        for(int i = 0; i < cantidad; i++){
        scanf("%d", &valor[i]);//CICLO QUE PERMITE AGREGAR VALORES AL ARREGLO
        
        }
        for(int i = 0; i < cantidad; i++){
        printf("Numero %d: %d\n", i+1, valor[i]);//CICLO QUE MUESTRA POR PANTALLA 
        }//CADA UNO DE LOS ARREGLOS
        //ENCONTRA LE NUMERO MAYOR 
        int max = valor[0]; //se crea una variable que guardara el puntero de valor posicion 0
        for(int i = 1; i < cantidad; i++){
            if(valor[i] > max  ){//si la posicion i(1 + 1 e cada vuelta) es mayor que la posicion 0
               max = valor[i];   //maximo reescribira su dato como  la posicion (1 + 1 en cada vuelta)
            }     //como resultado max encontrara el numero mayor y por sus reescrituras guardara ese unico numero.
         }
         printf("El numero mayor de los que proporciono  es: %d\n", max);
        free(valor);
        return 0;
        
     }