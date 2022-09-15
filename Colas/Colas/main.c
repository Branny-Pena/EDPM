/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 10, 2022, 9:39 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesColas.h"

int main(int argc, char** argv) {
    Cola q;
    int longQ;
    ElementoCola elemento;
    construirCola(&q);
    mostrar(q);
    
    longQ = obtenerLongitud(q);
    printf("La cola tiene %d nodos\n", longQ);
    
    encolar(&q, 56);
    mostrar(q);
    longQ = obtenerLongitud(q);
    printf("La cola tiene %d nodos\n", longQ);
    
    encolar(&q, 25);
    mostrar(q);
    longQ = obtenerLongitud(q);
    printf("La cola tiene %d nodos\n", longQ);
    
    encolar(&q, 80);
    mostrar(q);
    longQ = obtenerLongitud(q);
    printf("La cola tiene %d nodos\n", longQ);
    
    while(!esColaVacia(q)){
        elemento = desencolar(&q);
        printf("Elemento desencolado: %d\n", elemento);
        mostrar(q);
        longQ = obtenerLongitud(q);
        if(longQ == 1)
            printf("La cola ahora tiene %d nodo\n", longQ);
        else
            printf("La cola ahora tiene %d nodos\n", longQ);
    }
    
    return (EXIT_SUCCESS);
}

