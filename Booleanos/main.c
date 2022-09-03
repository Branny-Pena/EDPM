/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on August 27, 2022, 8:20 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0

typedef struct{
    int valor;
} Booleano;

void construirV(Booleano *pB){
    pB->valor = VERDADERO;
}

void construirF(Booleano *pB){
    pB->valor = FALSO;
}

void mostrar(Booleano B){
    if(B.valor == VERDADERO)
        printf("Verdadero\n");
    else
        printf("Falso\n");
}

void asignarValor(Booleano *pB, int nuevoValor){
    if(nuevoValor == VERDADERO || nuevoValor == FALSO)
        pB->valor = nuevoValor;
    else
        printf("Valor no valido\n");
}

Booleano negacion(Booleano B){
    Booleano Bn;
    if(B.valor == FALSO)
        asignarValor(&Bn, VERDADERO);
    else
        asignarValor(&Bn, FALSO);  
    return Bn;
}

Booleano conjuncion(Booleano B1, Booleano B2){
    Booleano C;
    if(B1.valor == VERDADERO && B2.valor == VERDADERO)
        C.valor = VERDADERO;
    else
        C.valor = FALSO;
    return C;
}

Booleano disyuncion(Booleano b1, Booleano b2){
    Booleano d;
    if(b1.valor == VERDADERO || b2.valor == VERDADERO)
        asignarValor(&d, VERDADERO);
    else
        asignarValor(&d,  FALSO);
    return d;
}

// ----------------------------------------------------------------------
//|Acceder a los valores de los datos solo desde las operaciones definidas|
// ----------------------------------------------------------------------
int main(int argc, char** argv) {
    Booleano B1, B2, B1n, B3, b4;
    construirV(&B1);
    construirF(&B2);
    printf("B1 = ");
    mostrar(B1);
    printf("B2 = ");
    mostrar(B2);
    
    asignarValor(&B1, FALSO);
    printf("B1 = ");
    mostrar(B1);
    
    asignarValor(&B2, 35);
    printf("B2 = ");
    mostrar(B2);
    
    B1n = negacion(B1);
    printf("B1n = ");
    mostrar(B1n);
    
    B3 = conjuncion(B2, B2);
    printf("B3 = ");
    mostrar(B3);
    \
    b4 = disyuncion(B1, B2);
    printf("b4 = ");
    mostrar(b4);
    return (EXIT_SUCCESS);
}

