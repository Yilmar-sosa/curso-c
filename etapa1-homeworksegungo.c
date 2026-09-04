#include <stdio.h>
#define MAX_SIZE 100

//Inicializa la lista de arreglos estableciendo listSize en 0 

void initArrayList(int* listArray, int* listSize){
    *listSize = 0;
}
//Inserta un nuevo elemento con el valor de datos proporcionado al principio de la lista de arreglos.
void insertAtBeginning(int* listArray, int* listSize, int data){//Fucion que no retorna valores, debe recibir una lista de arreglos de tipo entero
    if(*listSize == MAX_SIZE){
        printf("No se puede agregar, la lista esta llena\n");
    }
    //recibe un segundo parametro como puntero de una variable entera y como ultimo parametro un dato de tipo entero.
    for(int i = *listSize; i > 0 ; i--){//ciclo con inicador igual al al valor de la variable i = a un puntero, que se ejecutara mientras i > 0; con cada vuelta
//disminuira el iniciador 1
        listArray[i] = listArray[i-1];//El indice i(iniciador) copiara el valor de su indice anterior con el fin de mover cada dato una posicion
        //hacia adelante.
    }
    listArray[0] = data;//El indice 0 recibira el dato pasado por parametro
    (*listSize)++;//Se localizara el dato de la ubicacion y se le sumara 1
}

//Inserta un nuevo elemento con el valor de datos proporcionado al final de la lista de arreglos

void insertAtEnd(int *listArray, int *listSize, int data){//funcion que recibe un arreglo de enteros, recibe un puntero a un direccion de un entero, y un dato de tipo entero
    if(*listSize == MAX_SIZE){
        printf("No se puede agregar la lista llena\n");
        return;
    }

    listArray[*listSize] = data;//se le asigna el dato entero al indice que señala *listSize en la matriz listArray
    (*listSize)++;//se ubica el dato en la direeccion de listSize y se le aumenta 1 al dato real para actualizar.
}
//Inserta un nuevo elemento con el valor de datos proporcionado después del elemento en el índice proporcionado en la lista de arreglos.

void insertAfterIndex(int* listArray, int* listSize, int data,  int index){//Fucion que insera despues del indice indicado, recibe como parametros
    if(*listSize == MAX_SIZE){
        printf("No se puede agregar la lista esta llena\n");
        return;
    }
    //un arreglo de tipo entero, recibe la ubicacion de una variable entera, recibe un dato tipo entero y un indice tipo entero
    for(int i = *listSize; i > index; i--){//ciclo con iniciador que corresponte a la ubicacion del dato de una variable tipo entero, se ejecutara
        // minetras la variable de iniacion sea mayor al indice, y la variable inicado disminuira 1 al terminar cada vuelta
        listArray[i] = listArray[i-1];//El indice del momento copiara el dato del indice anterior
    }
    listArray[index + 1] = data; //El indice + una posicion adelante copiara el dato;
    (*listSize)++; //Se ubicara el dato real y se le sumara 1
}
// Elimina el elemento en el índice proporcionado de la lista de arreglos.
void deleteAtIndex(int* listArray, int* listSize, int index){
    if (*listSize == 0) {
    printf("La lista esta vacia\n");
    return;
}

    if(index < 0 || index >= *listSize){
        printf("Ese indice a eliminar no es valido\n");
        return;
    }
    for(int i = index ; i < *listSize -1 ; i++){
        listArray[i] = listArray[i+1];
    }
    (*listSize)--;
}
//Devuelve la longitud de la lista de arreglos (número de elementos).
int findLength(int* listSize){
    return *listSize;
}
 //Imprime los valores de datos de todos los elementos en la lista de arreglos.
 void printArrayList(int *listArray, int *listSize){
    for(int i = 0; i < *listSize; i ++){
        if(i > 0 ){
        printf(" -> ");
        }
        printf("%d", listArray[i]);
    }
        printf("\n");
        
}
 

int main() {
   int listArray[MAX_SIZE];
   int listSize = 0;
  
   initArrayList(listArray, &listSize);
  
   insertAtEnd(listArray, &listSize, 10);
   insertAtEnd(listArray, &listSize, 20);
   insertAtEnd(listArray, &listSize, 30);
   printArrayList(listArray, &listSize);  // Output: 10 -> 20 -> 30
  
   insertAtBeginning(listArray, &listSize, 5);
   printArrayList(listArray, &listSize);  // Output: 5 -> 10 -> 20 -> 30
  
   insertAfterIndex(listArray, &listSize, 25, 2);
   printArrayList(listArray, &listSize);  // Output: 5 -> 10 -> 20 -> 25 -> 30
  
   deleteAtIndex(listArray, &listSize, 1);
   printArrayList(listArray, &listSize);  // Output: 5 -> 20 -> 25 -> 30
  
   int length = findLength(&listSize);
   printf("Length of the array list: %d\n", length);  // Output: Length of the array list: 4
  
   return 0;

}