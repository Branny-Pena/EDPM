#include <stdio.h>
#include <stdlib.h>
#include "FuncionesColas.h"

void construirCola(Cola *pC){
    pC->cabeza = NULL;
    pC->cola = NULL;
}

int esColaVacia(Cola c){
    return c.cabeza == NULL;
}

Nodo* crearNuevoNodo(ElementoCola elemento){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    //Direccion NULL porque todos los nodos nuevos se encolan
    pNuevoNodo->sig = NULL;
    return pNuevoNodo;
}

void encolar(Cola *pC, ElementoCola elemento){
    Nodo *pNuevoNodo, *pFinal;
    pNuevoNodo = crearNuevoNodo(elemento);
    if(esColaVacia(*pC))
        pC->cabeza = pNuevoNodo;
    else{
        pFinal = pC->cola;
        pFinal->sig = pNuevoNodo;
    }
    pC->cola = pNuevoNodo;
}


