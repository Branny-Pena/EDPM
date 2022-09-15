#include <stdio.h>
#include <stdlib.h>
#include "FuncionesColas.h"

void construirCola(Cola *pC){
    pC->cabeza = NULL;
    pC->cola = NULL;
    pC->longitud = 0;
}

int esColaVacia(Cola c){
    return c.cabeza == NULL;
    //return c.longitud == 0;
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
    pC->longitud++;
}

void mostrar(Cola c){
    Nodo *pNodo;
    if(esColaVacia(c))
        printf("La cola esta vacia\n");
    else{
        pNodo = c.cabeza;
        while(pNodo != NULL){
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

int obtenerLongitud(Cola c){
    return c.longitud;
}

//Previo al uso de esta funcion se usa una verificacion para ver si la lista
//esta vacia o no
ElementoCola desencolar(Cola *pC){
    Nodo *pNodo;
    ElementoCola elemento;
    pNodo = pC->cabeza;
    elemento = pNodo->elemento;
    pC->cabeza = pNodo->sig;
    if(pNodo->sig == NULL)
        pC->cola = NULL;
    free(pNodo);
    pC->longitud--;
    return elemento;
}
