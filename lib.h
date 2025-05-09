//declarar tanto librerias, declarar funciones y estructuras
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct archivo{
    int entero = 0, flotante = 0, doble = 0, complejo = 0;
    char tipo;
}archivo;

typedef struct complex{
    float real, imaginario;
}complex;

typedef struct punteros{
    int *vec_entero;
    float *vec_flotante;
    double *vec_doble;
    complex *vec_complejo;
    archivo file;
}punteros;

void leer_archivo(FILE *a, punteros *p);
void vectores (FILE *a, punteros *p);
void llenar_vectores (FILE *a, punteros *p);
void mostrar_vectores (punteros *p);
void liberar_memoria (punteros *p);