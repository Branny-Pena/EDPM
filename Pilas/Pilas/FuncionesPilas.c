#include <stdio.h>
#include <stdlib.h>
#include "FuncionesPilas.h"

/*1)Apilar: Agregar un nuevo nodo en la cima de la pila
  2)Desapila: Eliminar un nodo de la cima de la pila
 */
void construirPila(Pila *pP){
    pP->cima = NULL;
    pP->longitud = 0;
}

int esPilaVacia(Pila p){
    return p.cima == NULL;
    //return c.longitud == 0;
}

Nodo* crearNuevoNodo(ElementoPila elemento, Nodo *sgte){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sgte;
    return pNuevoNodo;
}

void apilar(Pila *pP, ElementoPila elemento){
    Nodo *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, pP->cima);
    pP->cima = pNuevoNodo;
    pP->longitud++;
}

void mostrar(Pila p){
    Nodo *pNodo;
    if(esPilaVacia(p))
        printf("La pila esta vacia\n");
    else{
        pNodo = p.cima;
        while(pNodo != NULL){
            printf("%03d\n", pNodo->elemento);
            pNodo = pNodo->sig;
        }
    }
    printf("\n");
}

int obtenerLongitud(Pila p){
    return p.longitud;
}

ElementoPila desapilar(Pila *pP){
    Nodo *pNodo;
    ElementoPila elemento;
    pNodo = pP->cima;
    elemento = pNodo->elemento;
    pP->cima = pNodo->sig;
    pP->longitud--;
    free(pNodo);
    return elemento;
}
