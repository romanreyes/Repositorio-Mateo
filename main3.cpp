//lo hago devuelta por que la tengo gigante 
#include "lib.h"

int main() {
    punteros p; // inicializamos la estructura punteros
    
    FILE *a = fopen("C:\\Users\\roman\\Downloads\\number_mixed.dat", "rb"); // abrimos en modo binario de sólo lectura
    if (!a) {
        perror("ERROR al abrir el archivo");
        return 1;
    }
    // contamos en f
    leer_archivo(a, &p); // leemos el archivo y contamos los tipos de datos

    // mostramos resultados
    printf("Cantidad de cada tipo en el archivo:\n");
    printf(" enteros : %d\n", p.file.entero);
    printf(" flotantes: %d\n", p.file.flotante);
    printf(" dobles   : %d\n", p.file.doble);
    printf(" complex  : %d\n", p.file.complejo);

    vectores(a, &p); // asignamos memoria para los vectores
    llenar_vectores(a, &p); // llenamos los vectores con los datos del archivo
    mostrar_vectores(&p); // mostramos los vectores
    liberar_memoria(&p); // liberamos la memoria asignada a los vectores
   fclose(a); 
   return 0;// hola Gusti
}
