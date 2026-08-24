/*Especificación                                                                 
                                                                                    
     Fase 1 — Acceso: reutiliza tu guardián: PIN 4321 con do-while e intentos       
     contados. Sin acceso correcto, no hay menú. */
    
     #include <stdio.h>
     int main(){
        int pinCorrecto = 4321;
        int pin;
        int intentos = 0;
        do{
            printf("Ingrese su PIN\n\n");
            scanf("%d", &pin);

            if( pin < 1000 || pin > 9999){
                printf("Error!! Su pin debe contener 4 digitos\n\n");
            }
            else if( pin != pinCorrecto){ 
                printf("Acceso Denegado\nIntente nuevamente\n\n");
                intentos ++;
            }
        }while(!(pin == pinCorrecto));
        intentos ++;
      
      printf("Acceso concedido\n");
      printf("Realizo %d intentos para poder acceder\n", intentos);
     

                              
                                                                                    
     /*Fase 2 — Menú en bucle: saldo inicial $1000. Muestra:                          
                                                                                    
     --- CAJERO ---                                                                 
     1) Consultar saldo                                                             
     2) Depositar                                                                   
     3) Retirar                                                                     
     4) Salir                                                                       
                                                                                    
     y repite hasta que el usuario elija salir. 
                                                                                         
     Reglas por opción:                                                             
                                                                                    
     ┌──────┬────────────────────────────────────────────────────────────────────┐  
     │Opción│Comportamiento                                                      │  
     ├──────┼────────────────────────────────────────────────────────────────────┤  
     │1     │Imprime el saldo                                                    │  
     ├──────┼────────────────────────────────────────────────────────────────────┤  
     │2     │Pide monto; si es menor o igual a 0 → "Monto invalido" y NO         │  
     │      │modifica saldo                                                      │  
     ├──────┼────────────────────────────────────────────────────────────────────┤  
     │3     │Pide monto; rechaza si es inválido o si excede el saldo (¡ahí va tu │  
     │      │||!)                                                                │  
     ├──────┼────────────────────────────────────────────────────────────────────┤  
     │4     │Despedida y fin del programa                                        │  
     ├──────┼────────────────────────────────────────────────────────────────────┤  
     │otra  │"Opcion no valida" y vuelve al menú                                 │  
     └──────┴────────────────────────────────────────────────────────────────────┘  */
    
     int opcion = 0;
     int saldoInicial = 1000;
     do{
        printf("BIENVENIDO A SU CAJERO!!!\n\n¿Que desea hacer(seleccione un numero)?\n");
        printf("CAEJERO\n1) Consultar saldo\n2) Depositar\n3) Retirar\n4) Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
            printf("Su saldo es $%d\n", saldoInicial);
            break;

            case 2:
                int monto;
                printf("Ingrese el monto el que desea depositar\n");
                scanf("%d", &monto);

                if(monto <= 0){ 
                printf("Monto invalido\n\n");
                }
                else{
                    saldoInicial = saldoInicial + monto;
                    printf("Su saldo ahora es: %d", saldoInicial);
                }
             break;

            case 3:
                int retiro;
                printf("¿Cuanto desea retirar?\n");
                scanf("%d", &retiro);

                if(!(retiro <= 0 || retiro > saldoInicial)){ 
                saldoInicial = saldoInicial-retiro;
                printf("Su nuevo saldo disponible es: $%d\n", saldoInicial);
                }
                else{
                printf("Monto invalido");
                }
            break;

            case 4:
               printf("Saliste\n\n");
            break;

            default:
                printf("Valor\n");
               
            }

     } while(!(opcion == 4));    
      printf("Gracias por confiar en nosotros\nEsperamos verte pronto\n");

        return 0;
    }
    


       /*()
                       

                                                                                    
     Requisitos técnicos                                                            
                                                                                    
     - Un solo switch dentro de un solo do-while.                                   
     - Usa continue en al menos una validación.                                     
     - Usa ! en al menos una condición.                                             
     - Cero mensajes falsos: si el retiro es rechazado, el saldo no se toca ni se   
       reimprime como si hubiera pasado algo.                                       
     - El último mensaje de cada camino con su \n. Ya sabes por qué lo pido. 😄     
                                                                                    
     Predicciones antes de codificar                                                
                                                                                    
     1. ¿Dónde declaras saldo para que sobreviva a todas las vueltas del bucle?     
     2. Si el usuario deposita -50, traza tu programa línea por línea: ¿qué         
        imprime y qué vale saldo después?                                           
                                                                                    
     Este es de los grandes: tómate tu tiempo, compila seguido y pruébalo todo (    
     retiro mayor al saldo, depósito negativo, opción 7, PIN mal escrito). Cuando   
     digas "listo", hago revisión completa y cerramos sesión con tu ritual de git   
     si aprueba.                                                                    
                                */