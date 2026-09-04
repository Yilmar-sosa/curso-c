/*🏋️ Ejercicio 2: Cafetería La Terminal                                          
                                                                                    
     Crea cafeteria.c en etapa2-condiciones/.                                       
                                                                                    
     Parte A:                                                                       
                                                                                    
     1. Imprime el menú:                                                            
                                                                                    
     --- Cafeteria La Terminal ---                                                  
     1) Cafe                                                                        
     2) Te                                                                          
     3) Chocolate                                                                   
     Elige una opcion:                                                              
                                                                                    
     2. Lee la opción con scanf.                                                    
     3. Con switch: cada opción imprime "Preparando tu cafe" (etc.). Opción         
        inválida → "No tenemos esa opcion" vía default. Todos los case con su       
        break.                                                                      
                                                                                    
     Parte B: cada bebida tiene precio (café $25, té $18, chocolate $30). Declara   
     una variable `total` antes del switch, asígnale el precio dentro de cada       
     `case`, y después del switch imprime `"Total a pagar: $%d\n"`. Fíjate: el      
     switch no solo sirve para imprimir — también puede preparar datos para         
     usarlos fuera.                                                                 
                                                                                    
     Predice primero: si escribo 7, ¿qué camino sigue tu programa? Y ya sabes...    
     el \n del último mensaje. 😄   */
     #include <stdio.h>
     int main(){
        int opcion;
        int total = 0;
        printf("CAFETERIA TERMINAL\nEscriba el numero de su petición\n\n1) Cafe\n2) Te\n3) Chocolate\n");
        scanf("%d", &opcion);
        
        switch (opcion){//interruptor que activara un caso dependiendo el valor de la opcion
            case 1://si es uno ejecuta las siguientes instruccion si no lo es buscara en los otros casos hasta que lo encuentre y cuando lo encuentre saldra
            printf("Preparando un cafe\n");
            total = 25;
            break;
            
            case 2:
            printf("Preparando un Te\n");
            total = 18;
            break;

            case 3:
            printf("Preparando un Chocolate\n");
            total = 30;
            break;

            default:
            printf("No tenemos esa opcion\n");
            return 0;
        
        }

        printf("Total a pagar: $%d\n", total);
        return 0;
            
    
     }
    