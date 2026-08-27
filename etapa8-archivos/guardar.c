/*🏋️ Ejercicio: etapa8-archivos/guardar.c                                        
                                                                                    
     1. Pedir al usuario su nombre y edad                                           
     2. Guardarlos en datos.txt (con "w")                                           
     3. Abrir con "r" y mostrar lo que se guardó                                    
                                                                                    
     Salida esperada:                                                               
                                                                                    
     ¿Cómo te llamas? Yilmar                                                        
     ¿Cuántos años tienes? 25                                                       
     Guardado en datos.txt                                                          
                                                                                    
     Contenido del archivo:                                                         
     Yilmar 25          */                      

     #include <stdio.h>

     int main(){
        char nombre[50];
        int edad;

        printf("¿Cómo te llamas\n?");
        scanf(" %[^\n]", nombre);

        printf("¿Cuantos años tiene\n");
        scanf("%d", &edad);

        FILE *Archivos = fopen("datos.txt", "w");
        fprintf(Archivos, "%s %d\n", nombre, edad);
        fclose(Archivos);

        FILE *Arch = fopen("datos.txt", "r");
        char linea[100];
        fgets(linea, 100, Arch);
        printf("Contenido: %s", linea);
        fclose(Arch);

       

     }