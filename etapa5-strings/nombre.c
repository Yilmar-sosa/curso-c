#include <stdio.h>//incluye la libreria que contiene printf y scanf

int main(){//inicia el codigo con la funcion madre
    char nombre[50];//declara arreglo de 50 campos de tipo str:
    int longitud = 0;//declara variable longitud tipo entera con valor de 0
    printf("¿Cómo te llamas?\n");//imprime
    scanf("%s", nombre);//escanea un tipo de dato string y guardalo en nombre
    
    while(nombre[longitud] != '\0'){//repite ciclicamente las siguientes instrucciones mientra el arrglo posicion[longitud] se diferente al caracter finalizador de texto
           longitud++;//aumenta 1 a longitud
    }
    for(int i = 0; i < longitud; i++){//iniciador variable temporal en 0; repite las instrucciones internas mientras la variable temporal se menor a longitud y aumenta 1 al valor del iniciador al finalizar cada vuelta
         nombre[i] = nombre[i] - 32;//a la posicion arreglo[i](actual) asignale el valor de la posicion arreglo [i](actual) -32 posiciones(en ASCCI cada minuscula esta 32 posiciones antes que su mayuscula)
}
    printf("Tu nombre tiene %d letras\n", longitud); //imprime el texto junto con el dato que señala el tipo de dato que proviene de la variable longitud
    
 
    printf("Tu nombre en mayusculas es: %s\n", nombre);//imprime el texto : dato tipo str recibido de la direccion de la variable arreglo nombre

  
    return 0;
    //termina el programa bien
    
}
#include <stdio.h>//incluye libreria de funciones de entrada y salida                                                             
     #include <ctype.h>  //incluye librerias de funciones para transformar caracteres individuales tipo                                                            
     #include <string.h> //incluye librerias de funciones de string             

     //inicia la funcion madre del programa-no necesita parametros por terminal                                                                                
     int main(){                                                                   
         char nombre[50]; //char de 50 caracteres                                               
         printf("¿Cómo te llamas?\n");//imprimir                                         
         fgets(nombre, 50, stdin); //scanea texto(arreglo, memoria, estandar de ingreso)                                    
         nombre[strcspn(nombre, "\n")] = '\0'; //dentro del arreglo busca en donde concide el indice con el salto de linea y cambialo por un final de linea                                     
                                                                                    
         int longitud = 0; //crea variable de tipo int llamada longitud y asignale el valor de 0                                                         
         while(nombre[longitud] != '\0'){ //repite las instrucciones ciclicas internas mientras el indice igual a longitud dentro del arreglo nombre sea diferente al final de linea               
             longitud++; //aumenta 1 a longitud como ultima instruccion de este ciclo                                                           
         }                                                                          
         for(int i = 0; i < longitud; i++){//ciclo con iniciador variable entera temporal; se repira siempre y cuando variable temporal sea menor a longitud; la variable temporal aumenta su valor +1 al finalizar cada vuelta
             nombre[i] = toupper(nombre[i]);//a cada indice mientras ciclo se repita cambia conviere a mayusculas cada valor                                        
         }                                                                          
         printf("Tu nombre tiene %d letras\n", longitud);                           
         printf("Tu nombre en mayusculas es: %s\n", nombre);                        
         return 0;                                                                  
     }                                                                              
                                            