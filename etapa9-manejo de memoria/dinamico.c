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

     #include <stdio.h>
     #include <stdlib.h>

     int main(){
        int cantidad;
        
    

        printf("Cuantos valores quiere ingresar\n");
        scanf("%d", &cantidad);
        int* valor = malloc (cantidad * sizeof(int));
        printf("Sus valores a agregar son: %d\n\nA continuación empiece a ingresarlos\n", cantidad);
        
        for(int i = 0; i < cantidad; i++){
        scanf("%d", &valor[i]);
        
        }
        for(int i = 0; i < cantidad; i++){
        printf("Numero %d: %d\n", i+1, valor[i]);
        }
        free(valor);
        return 0;
        
     }