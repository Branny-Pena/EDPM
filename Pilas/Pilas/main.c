/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 15, 2022, 9:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesPilas.h"

int main(int argc, char** argv) {
    Pila stack;
    int longitud;
    ElementoPila elemento;
    construirPila(&stack);
    mostrar(stack);
    
    apilar(&stack, 12);
    mostrar(stack);
    
    apilar(&stack, 234);
    mostrar(stack);
    
    apilar(&stack, 264);
    mostrar(stack);
    
    apilar(&stack, 456);
    mostrar(stack);
    
    apilar(&stack, 78);
    mostrar(stack);
    
    longitud = obtenerLongitud(stack);
    printf("La longitud de la pila es: %d\n", longitud);
    
    while(!esPilaVacia(stack)){
        elemento = desapilar(&stack);
        printf("Elemento desapilado: %d\n", elemento);
        mostrar(stack);
    }
    return (EXIT_SUCCESS);
}

