//desarrollo las funciones y procedimientos
#include "lib.h"

 void leer_archivo(FILE *a, punteros *p) {
    int contador;
    while(fread(&p->file.tipo, sizeof(char), 1, a)){
        fread(&contador, sizeof(int), 1, a);
        switch (p->file.tipo) {
            case 'i':
                p->file.entero += contador;
                fseek(a, contador * sizeof(int), SEEK_CUR);
                break;
            case 'd':
                p->file.doble += contador;
                fseek(a, contador * sizeof(double), SEEK_CUR);
                break;
            case 'f':
                p->file.flotante += contador;
                fseek(a, contador * sizeof(float), SEEK_CUR);
                break;
            case 'z':
                p->file.complejo += contador;
                fseek(a, contador * sizeof(complex), SEEK_CUR);
                break;
        }
    }
 rewind(a); // Regresamos al inicio del archivo para poder leerlo nuevamente
}

void vectores (FILE *a, punteros *p) {
    p->vec_entero = (int *)malloc(p->file.entero * sizeof(int));
    p->vec_flotante = (float *)malloc(p->file.flotante * sizeof(float));
    p->vec_doble = (double *)malloc(p->file.doble * sizeof(double));
    p->vec_complejo = (complex *)malloc(p->file.complejo * sizeof(complex));
}

void llenar_vectores (FILE *a, punteros *p) {
    int contador;
    int i_count = 0;
    int f_count = 0;
    int d_count = 0;
    int c_count = 0;
    char tipo;
    while(fread(&tipo, sizeof(char), 1, a)){
        fread(&contador, sizeof(int), 1, a);
        switch (tipo) {
            case 'i':
                fread(&p->vec_entero[i_count], sizeof(int), contador, a);
                i_count += contador; // Incrementamos el contador de enteros
                break;
            case 'd':
                fread(&p->vec_doble[d_count], sizeof(double), contador, a);
                d_count += contador; // Incrementamos el contador de dobles
                break;
            case 'f':
                fread(&p->vec_flotante[f_count], sizeof(float), contador, a);
                f_count += contador; // Incrementamos el contador de flotantes
                break;
            case 'z':
                fread(&p->vec_complejo[c_count], sizeof(complex), contador, a);
                c_count += contador; // Incrementamos el contador de complejos
                break;
        }
    }
    rewind(a); // Regresamos al inicio del archivo para poder leerlo nuevamente
}

void mostrar_vectores (punteros *p) {
    printf("\nVector de enteros:\n");
    for (int i = 0; i < p->file.entero; i++) {
        printf("%d ", p->vec_entero[i]);
    }
    printf("\n\nVector de flotantes:\n");
    for (int i = 0; i < p->file.flotante; i++) {
        printf("%f ", p->vec_flotante[i]);
    }
    printf("\n\nVector de dobles:\n");
    for (int i = 0; i < p->file.doble; i++) {
        printf("%lf ", p->vec_doble[i]);
    }
    printf("\n\nVector de complejos:\n");
    for (int i = 0; i < p->file.complejo; i++) {
        printf("%f + %fi ", p->vec_complejo[i].real, p->vec_complejo[i].imaginario);
    }
}

void liberar_memoria (punteros *p) {
    free(p->vec_entero);
    free(p->vec_flotante);
    free(p->vec_doble);
    free(p->vec_complejo);
}