#include <stdio.h>                                                             
                                                                                    
     void duplicar(int x);                                                          
                                                                                    
     int main() {                                                                   
         int n = 5;                                                                 
         duplicar(n);                                                               
         printf("Fuera de la funcion n vale: %d\n", n);                             
         return 0;                                                                  
     }                                                                              
                                                                                    
     void duplicar(int x) {                                                         
         x = x * 2;                                                                 
         printf("Dentro de la funcion x vale: %d\n", x);                            
     }                                                      