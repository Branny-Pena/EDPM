/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on August 27, 2022, 9:26 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListasSimEnlazadas.h"



int main(int argc, char** argv) {
    Lista a;
    Nodo *b;
    int longitud;
    crearLista(&a);
    mostrarLista(a);
    insertarComienzo(&a, 45);
    mostrarLista(a);
    insertarComienzo(&a, 80);
    mostrarLista(a);
    insertarFinal(&a, 37);
    mostrarLista(a);
    insertarFinal(&a, 12);
    mostrarLista(a);
    printf("%d\n", buscar(a, 37));
    b = obtenerNodo(a, 37);
    if(b == NULL)
        printf("NULL\n");
    else    
        printf("%d\n", b->elemento);
    b = obtenerAnterior(a, 80);
    if(b == NULL)
        printf("NULL\n");
    else    
        printf("%d\n", b->elemento);
    b = obtenerSiguiente(a, 37);
    if(b == NULL)
        printf("NULL\n");
    else    
        printf("%d\n", b->elemento);
    eliminarNodo(&a, 80);
    mostrarLista(a);
    b = obtenerNodo(a, 80);
    if(b == NULL)
        printf("NULL\n");
    else    
        printf("%d\n", b->elemento);
    eliminarNodo(&a, 80);
    longitud = obtenerLongitud(a);
    printf("Elementos: %d\n", longitud);
    destruirLista(&a);
    mostrarLista(a);
    return (EXIT_SUCCESS);
}

