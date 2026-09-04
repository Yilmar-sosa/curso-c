#include <stdio.h>

     int pedirPin(void); //nombrar funcion que retornara un dato de tipo int tendra un nombre y no reciber parametros
     void mostrarMenu(void);//funcion no retorna ni recibe parametros
     void consultarSaldo(int saldoActual);//no retorna, recibe un parametro de tipo entero
     int depositar(int saldoActual);//retorna un int, recibe un int como parametro 
     int retirar(int saldoActual);

     int main(){
        
     int opcion = 0;//crea variable int opcion que guardara 0
     int saldo = 1000;

     pedirPin();//hacemos el llamado a la funcion pedir pin
     
     do{
        mostrarMenu();
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1:
            consultarSaldo(saldo);
            break;

            case 2:
            saldo = depositar(saldo);
            
            break;

            case 3:
            saldo = retirar(saldo); 
            break;

            default:
                printf("Seleccion incorrecta\n");
               
            }

     } while(!(opcion == 4));    
      printf("Gracias por confiar en nosotros\nEsperamos verte pronto\n");

        return 0;
    }
    
    //FUNCION PARA PEDIR Y VERIFICAR pedirPin
    int pedirPin(){//funcion retorna int llamada pedirPin no necesita parametro dentro se crearan las instrucciones que contendra esa funcion
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
      
      return intentos;
    }

      //Funcion PARA MOSTRAR OPCIONES DEL CAJERO

    void mostrarMenu(void){
        printf("BIENVENIDO A SU CAJERO!!!\n\n¿Que desea hacer(seleccione un numero)?\n");
        printf("CAEJERO\n1) Consultar saldo\n2) Depositar\n3) Retirar\n4) Salir\n");
    }
    
    //FUCION QUE RETORNA EL SALDO
    
    void consultarSaldo(int saldoActual){ 
        printf("Su saldo actual es: %d\n", saldoActual);
    }

    //Funcion QUE IMPRIME SALDO ACTUAL

    int depositar(int saldoActual){
        int monto;
                printf("Ingrese el monto el que desea depositar\n");
                scanf("%d", &monto);

                if(monto <= 0){ 
                    printf("Monto invalido\n\n");
                }
                else{
                    saldoActual = saldoActual + monto;
                    printf("Su nuevo saldo es %d\n", saldoActual);
                }
                    return saldoActual;
                }

    //Funcion Para retirar

    int retirar(int saldoActual){
        int retiro;
                printf("¿Cuanto desea retirar?\n");
                scanf("%d", &retiro);

                if(!(retiro <= 0 || retiro > saldoActual)){ 
                saldoActual = saldoActual-retiro;
                printf("Su nuevo saldo disponible es: $%d\n", saldoActual);
                }
                else{
                printf("Monto invalido");
    }
    return saldoActual;
}