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
     #include <stdio.h>//incluye scanf, printf
     #include <string.h>//incluye fgets


        typedef struct{ //se le asinara un alias a la palabra reservada struct
            //internamente al struct creamos los siguientes miembros.
            char nombre[50];//char de 50 espacios
            int edad; //variable tipo int
            float promedio; //variable tipo float
        }Estudiante; //nombre del molde de la struct por el alias podemos llamar a la struct solo con el nombre del molde
    int main(){
        Estudiante Yilmar; //Llamos al molde de la struct...Estudiante y creamos una estructura llamada Yilmar
        printf("¿Como te llamas?\n"); //pregunta el nombre
        fgets(Yilmar.nombre, 50, stdin);//scanea texto, guardalo en el miembro nombre de la struct Yilmar
        Yilmar.nombre[strcspn(Yilmar.nombre, "\n")] = '\0';//En el miembro nombre de la struct Yilmar busca la concidencia con "\n" y asignale a esa posicion '\0?

        printf("¿Cuantos años tienes?\n");//se pregunta al usuario
        scanf("%d", &Yilmar.edad);//se almacena el dato de tipo int en la direccion del campo estructura Yilmar.edad

        printf("¿Cual fue tu promedio?\n");//se le pregunta al usuario
        scanf("%f", &Yilmar.promedio);//se recibe un dato tipo float por el usuario y se almacena en la direccion Yilmar.promedio

        
        

        printf("Nombre: %s\n", Yilmar.nombre);
        
        printf("Edad: %d\n", Yilmar.edad);

        printf("Promedio: %.2f\n", Yilmar.promedio);

        return 0;
     }
     