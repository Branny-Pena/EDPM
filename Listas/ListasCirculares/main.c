/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 3, 2022, 9:24 AM
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementoListaC;

typedef struct nodo{
    ElementoListaC elemento;
    struct nodo *sig;
} Nodo;

typedef struct listaC{
    Nodo *cabeza;
} ListaC;

void crearListaC(ListaC *pL){
    pL->cabeza = NULL;
}

int esListaCVacia(ListaC l){
    return l.cabeza == NULL;
}

Nodo* crearNuevoNodo(ElementoListaC elemento, Nodo *sig){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

Nodo* obtenerUltimoNodo(ListaC l){
    Nodo *pNodo, *pUltimo;
    if(esListaCVacia(l))
        return NULL;
    pUltimo = NULL;
    pNodo = l.cabeza;
    do{
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    } while(pNodo != l.cabeza);
    return pUltimo;
}

void insertarComienzo(ListaC *pL, ElementoListaC elemento){
    Nodo *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, pL->cabeza);
    pL->cabeza = pNuevoNodo;
}

void mostrarListaC(ListaC l){
    Nodo *pNodo;
    if(esListaCVacia(l))
        printf("La lista esta vacia\n");
    else{
        pNodo = l.cabeza;
        do{
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        } while(pNodo != l.cabeza);
        printf("\n");
    }
}

int obtenerLongitud(ListaC l){
    Nodo *pNodo;
    int nodos = 0;
    pNodo = l.cabeza;
    if(esListaCVacia(l)) return 0;
    do{
        nodos++;
    } while(pNodo != l.cabeza);
    return nodos;
}

int main(int argc, char** argv) {
    
    return (EXIT_SUCCESS);
}

