/*🏋️ Ejercicio: etapa7-structs/estudiante.c                                      
                                                                                    
     Crea un programa que:                                                          
                                                                                    
     1. Defina un struct Estudiante con: nombre, edad, promedio                     
     2. Pida al usuario los3 datos                                                  
     3. Muestre un reporte formateado                                               
                                                                                    
     Pista para leer el nombre con espacios:                                        
                                                                                    
     fgets(yilmar.nombre, 50, stdin);                                               
     yilmar.nombre[strcspn(yilmar.nombre, "\n")] = '\0';                            
                                                                                    
     Salida esperada:                                                               
                                                                                    
     Nombre: Yilmar Sosa                                                            
     Edad: 25                                                                       
     Promedio: 86.60                               */
     #include <stdio.h>
     #include <string.h>


        struct Estudiante{
            char nombre[50];
            int edad;
            float promedio;
        };
    int main(){
        struct Estudiante Yilmar;
        printf("¿Como te llamas?\n"); 
        fgets(Yilmar.nombre, 50, stdin);
        Yilmar.nombre[strcspn(Yilmar.nombre, "\n")] = '\0';

        printf("¿Cuantos años tienes?\n");
        scanf("%d", &Yilmar.edad);

        printf("¿Cual fue tu promedio?\n");
        scanf("%f", &Yilmar.promedio);

        
        

        printf("Nombre: %s\n", Yilmar.nombre);
        
        printf("Edad: %d\n", Yilmar.edad);

        printf("Promedio: %.2f\n", Yilmar.promedio);

        return 0;
     }
     