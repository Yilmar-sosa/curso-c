/*El reto                                                                        
                                                                                    
                                                                                    
     1. Pedir un número al usuario                                                  
     2. Imprimir su tabla de multiplicar del 1 al 10                                
                                                                                    
     Ya lo hiciste antes sin funciones. Esta vez hay una restricción: una parte     
     de la lógica debe vivir dentro de su propia función.                           
                                                                                    
     Tu trabajo (sin código, solo diseño)                                           
                                                                                    
     Antes de escribir una sola línea, respóndeme:                                  
                                                                                    
     1. ¿Qué código exacto harías para pedir el número? (ya lo sabes)               
     2. ¿Qué código exacto imprime la tabla? (ya lo sabes)                          
     3. De esas dos partes, ¿cuál tiene sentido separar y por qué? Pista: una se    
        repite fácilmente con otros números y la otra no.                           
     Cuando tengas claro qué función crear y qué nombre ponerle, escríbela y        
     conéctala al main. Si se te bloquea en algún punto específico, dime cuál y     
     te guío.                                                                       
                                                                                    
     Cuando lo tengas, compílalo y prueba con 7. Deberías ver:                      
                                                                                    
     7 x 1 = 7                                                                      
     7 x 2 = 14                                                                     
     7 x 3 = 21                                                                     
     ...                                                                            
     7 x 10 = 70                                                                    
                                                                                    
     Intenta y muéstrame cómo te fue.                                               
                                         */
    #include <stdio.h>
void numero(void);

int main(){
    numero();
    numero();
    numero();
    return 0;

}
void numero(void){
    int num;
    printf("cual es su numero\n\n");
    scanf("%d", &num);
    for (int i = 1; i < 11; i++){
         int resultado = num * i;
    printf("%d x %d = %d\n", num, i, resultado);
    }

}