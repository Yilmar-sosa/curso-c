#include <stdio.h>

int main(){
    char nombre[50];
    int longitud = 0;
    printf("¿Cómo te llamas?\n");
    scanf("%s", nombre);
    
    while(nombre[longitud] != '\0'){
           longitud++;
    }
    for(int i = 0; i < longitud; i++){
         nombre[i] = nombre[i] - 32;
}
    printf("Tu nombre tiene %d letras\n", longitud);
    
 
    printf("Tu nombre en mayusculas es: %s\n", nombre);

  
    return 0;
    
}
#include <stdio.h>                                                             
     #include <ctype.h>                                                             
     #include <string.h>                                                            
                                                                                    
     int main(){                                                                    
         char nombre[50];                                                           
         printf("¿Cómo te llamas?\n");                                              
         fgets(nombre, 50, stdin);                                                  
         nombre[strcspn(nombre, "\n")] = '\0';                                      
                                                                                    
         int longitud = 0;                                                          
         while(nombre[longitud] != '\0'){                                           
             longitud++;                                                            
         }                                                                          
         for(int i = 0; i < longitud; i++){                                         
             nombre[i] = toupper(nombre[i]);                                        
         }                                                                          
         printf("Tu nombre tiene %d letras\n", longitud);                           
         printf("Tu nombre en mayusculas es: %s\n", nombre);                        
         return 0;                                                                  
     }                                                                              
                                            