/*
EXAMEN PRUEBA 2 - Sistema de Inventario (Producto)
CODIGO TAL COMO ESTA (aun NO corrige, para revisar juntos despues).

IMPORTANTE - regla de acceso segun la firma:
  Producto *inventario   (una estrella)  -> inventario[i]      sin parentesis
  Producto **inventario  (dos estrellas) -> (*inventario)[i]   con parentesis

PENDIENTES DE CORREGIR (resumen de la revision):
 1. inicializarInventario: `*` suelto en linea propia; if(*capacidad==NULL) es
    incorrecto (capacidad es int, no puntero); debe comparar *inventario==NULL.
 2. agregarProducto: falta `;` en (.*inventario)[i].precio=precio; llaves mal cerradas.
 3. buscarProductoPorId: usar (.*inventario)[i] con una estrella esta mal ->
    debe ser inventario[i]; bug logico: else return -1 corta en la primer
    posicion sin revisar el resto (debe revisar todo y retornar -1 al final).
 4. actualizarCantidad: (.*cantidad)[i] no existe -> inventario[i].cantidad.
 5. calcularValorTotal: .valor no existe (es cantidad), [i+1] esta mal ->
    suma += inventario[i].cantidad * inventario[i].precio.
 6. imprimirInventario: parametro es cantidadProductos (no cantidad);
    inventario.cantidad -> inventario[i].cantidad / inventario[i].precio.
 7. liberarInventario: free(**inventario) incorrecto -> free(*inventario);
    typo "invertario"; falta ;.
 8. Varias funciones sin llaves de cierre balanceadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

void inicializarInventario(Producto **inventario, int *cantidadProductos, int *capacidad) {



*cantidadProductos = 0;//* Inicializar cantidadProductos en 0.*/
*capacidad = 3;/* Inicializar capacidad en 3;*/
*inventario = malloc(3 * sizeof(Producto));// Reservar memoria dinamica para guardar inicialmente 3 productos.Usar malloc.
*
if(*capacidad == NULL){
  printf("Error al asignar memoria");// Verificar si la memoria fue asignada correctamente.
  return;
}

void agregarProducto(Producto **inventario, int *cantidadProductos, int *capacidad, int id, char nombre[], int cantidad, float precio) {
    // code goes here
    //Esta funcion debe:

// Agregar un nuevo producto al final del inventario.
if(*cantidadProductos == *capacidad){
  int nuevacap = *capacidad * 2; //* Si el inventario esta lleno, debe duplicar su capacidad usando realloc.*/
   Producto * tem = realloc(*inventario, nuevacap * sizeof(Producto)); // Usar un puntero temporal al hacer realloc para no perder la memoria original si falla.
    if(tem == NULL){
      printf("Error no se ha podido expandir la memoria");
      return;
      *inventario = tem;
      *capacidad = nuevacap;
    }
    int i = *cantidadProductos;
    (*inventario)[i].id = id;
    strcpy((*inventario)[i].nombre, nombre);
    (*inventario)[i].cantidad = cantidad;
    (*inventario)[i].precio = precio

    (*cantidadProductos)++;//Actualizar correctamente cantidadProductos.

 }

int buscarProductoPorId(Producto *inventario, int cantidadProductos, int id) {

for(int i = 0; i < cantidadProductos; i++){
   if((*inventario)[i].id == id){//* Buscar un producto por su id.*/
      int indice = i;
      return indice; ////* Retornar el indice donde se encuentra el producto.
   }
   else{           //* Retornar -1 si no existe.
    return -1;
   }
}

void actualizarCantidad(Producto *inventario, int cantidadProductos, int id, int nuevaCantidad){
    for(int i = 0; i < cantidadProductos; i++){//* Buscar un producto por su id.
       if((*inventario)[i].id == id){//Si existe, actualizar su cantidad.
          (*cantidad)[i].cantidad = nuevaCantidad;
    }
       else{
          printf("Producto con ID X no encontrado");//* Si no existe, imprimir: Producto con ID X no encontrado. */
}

float calcularValorTotal(Producto *inventario, int cantidadProductos) {
    int cantidadActual = 0;
    int suma = 0;
    for(int i = 0; i < cantidadProductos; i++){// Calcular el valor total del inventario.
        cantidadActual = (*inventario)[i].valor * (*inventario)[i+1].precio
        suma = suma + cantidadActual;// El valor de cada producto es: cantidad * precio
    }
    return suma;
}

void imprimirInventario(Producto *inventario, int cantidadProductos) {
    // code goes here
    for(int i = 0; i < cantidad; i++){//Esta funcion debe imprimir todos los productos con el siguiente formato:
       printf("D %d | Nombre: %s | Cantidad: %d | Precio: %.2f\n", i+1, inventario[i].nombre, inventario.cantidad, inventario.precio);//D: 1 | Nombre: Teclado | Cantidad: 10 | Precio: 25.50
}

void liberarInventario(Producto **inventario, int *cantidadProductos, int *capacidad) {
    // code goes here
    //Esta funcion debe:

free(**inventario);//Liberar la memoria dinamica con free.
Producto ** invertario = NULL//* Colocar el puntero inventario en NULL.*/
*cantidadProductos = 0;
*capacidad = 0;//* Reiniciar cantidadProductos y capacidad a 0.
}

int main() {
    Producto *inventario = NULL;
    int cantidadProductos = 0;
    int capacidad = 0; // Se inicializa en 3 dentro de inicializarInventario()

    inicializarInventario(&inventario, &cantidadProductos, &capacidad);

    agregarProducto(&inventario, &cantidadProductos, &capacidad, 1, "Teclado", 10, 25.50);
    agregarProducto(&inventario, &cantidadProductos, &capacidad, 2, "Mouse", 15, 12.75);
    agregarProducto(&inventario, &cantidadProductos, &capacidad, 3, "Monitor", 5, 150.00);

    printf("Inventario inicial:\n");
    imprimirInventario(inventario, cantidadProductos);

    agregarProducto(&inventario, &cantidadProductos, &capacidad, 4, "Audifonos", 8, 40.00);

    printf("\nInventario despues de agregar un producto:\n");
    imprimirInventario(inventario, cantidadProductos);

    actualizarCantidad(inventario, cantidadProductos, 2, 20);

    printf("\nInventario despues de actualizar cantidad:\n");
    imprimirInventario(inventario, cantidadProductos);

    int indice = buscarProductoPorId(inventario, cantidadProductos, 3);

    if (indice != -1) {
        printf("\nProducto encontrado:\n");
        printf("ID: %d | Nombre: %s | Cantidad: %d | Precio: %.2f\n",
               inventario[indice].id,
               inventario[indice].nombre,
               inventario[indice].cantidad,
               inventario[indice].precio);
    } else {
        printf("\nProducto no encontrado.\n");
    }

    float total = calcularValorTotal(inventario, cantidadProductos);
    printf("\nValor total del inventario: %.2f\n", total);

    liberarInventario(&inventario, &cantidadProductos, &capacidad);

    return 0;
}
