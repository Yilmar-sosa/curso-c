/*1. Leer5 números del usuario                                                   
     2. Función void ordenar(int arr[], int tam) — aplica bubble sort               
     3. Función void mostrar(int arr[], int tam) — imprime el arreglo               
     4. Mostrar el arreglo antes y después de ordenar                               
                                                                                    
     Esto usa: arreglos, funciones, ciclos anidados, lógica de intercambio. Es      
     genuinamente nuevo.*/
     
     #include <stdio.h>
     void ordenar(int numeros[], int tam);
     void mostrar(int numeros[], int tam);
     
     int main(){
        int numeros[5];
        int tam = sizeof(numeros)/sizeof(numeros[0]);

        printf("Escribe los numeros que quieres ordenar\n");
        for(int i = 0; i < tam; i++){
            scanf("%d", &numeros[i]);
        }
        printf("Tus numeros son:\n\n");
        mostrar(numeros, tam);
        ordenar(numeros, tam);
        printf("Tus numeros ordenados de menor a mayor quedan asi:\n\n");
        mostrar(numeros, tam);


    
     }
     //FUNCION BUBBLE SORT
     void ordenar(int numeros[], int tam){
        for (int p = 0; p < tam -1; p++){
            for(int i = 0; i < tam -1; i++){
                if(numeros[i] > numeros[i+1]){ 
                    int temp = numeros[i]; 
                    numeros [i] = numeros[i+1];
                    numeros[i+1] = temp; 
                }
            }
        }
    }
    //FUNCION PARA MOSTRAR ARREGLOS
    void mostrar(int numeros[], int tam){
        for(int i = 0; i < tam; i++){
            printf("%d ", numeros[i]);
        }
        printf("\n\n");
    }
