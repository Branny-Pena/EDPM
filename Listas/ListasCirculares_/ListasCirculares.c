#include <stdio.h>
#include <stdlib.h>
#include "ListasCirculares.h"

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
    pUltimo = NULL;
    if(!esListaCVacia(l)){
        pNodo = l.cabeza;
        do{
            pUltimo = pNodo;
            pNodo = pNodo->sig;
        } while(pNodo != l.cabeza);
    }
    return pUltimo;
}



void insertarComienzo(ListaC *pL, ElementoListaC elemento){
    Nodo *pNuevoNodo, *pUltimoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, pL->cabeza);
    pUltimoNodo = obtenerUltimoNodo(*pL);
    if(pUltimoNodo == NULL)
        pNuevoNodo->sig = pNuevoNodo;
    else
        pUltimoNodo->sig = pNuevoNodo;
    
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

void insertarFinal(ListaC *pL, ElementoListaC elemento){
    Nodo *pUltimo, *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, pL->cabeza);
    pUltimo = obtenerUltimoNodo(*pL);
    if(pUltimo == NULL){
        pL->cabeza = pNuevoNodo;
        pNuevoNodo->sig = pNuevoNodo;
    }
    else{
        pUltimo->sig = pNuevoNodo;
    }
}

Nodo* obtenerNodo(ListaC l, ElementoListaC elemento){
    Nodo *pNodo;
    if(!esListaCVacia(l)){
        pNodo = l.cabeza;
       do{
            if(pNodo->elemento == elemento)
                return pNodo;
            pNodo = pNodo->sig;
        } while(pNodo != l.cabeza);
    }
    return NULL;
}

//cuando estamos seguros de que el elemento esta en la lista
Nodo* obtenerAnterior(ListaC l, ElementoListaC elemento){
    Nodo *pNodo, *pNodoAnterior;
    pNodo = l.cabeza;
    pNodoAnterior = NULL;
    do{
        if(pNodo->elemento == elemento)
            break;
        pNodoAnterior = pNodo;
        pNodo = pNodo->sig;
    } while(pNodo != l.cabeza);
    
    return pNodoAnterior;
}

void eliminarNodo(ListaC *pL, ElementoListaC elemento){
    Nodo *pNodoEliminar, *pNodoAnterior, *pUltimo;
    pNodoEliminar = obtenerNodo(*pL, elemento);
    if(pNodoEliminar != NULL){
        pNodoAnterior = obtenerAnterior(*pL, elemento);
        if(pNodoAnterior == NULL){
            pUltimo = obtenerUltimoNodo(*pL);
            if(pUltimo == pNodoEliminar)
                pL->cabeza = NULL;
            else{
                pL->cabeza = pNodoEliminar->sig;
                pUltimo->sig = pL->cabeza;
            }
        }
        else
            pNodoAnterior->sig = pNodoEliminar->sig;
        free(pNodoEliminar);
        printf("El nodo ha sido eliminado\n");
    }
    else
        printf("No existe el elemento\n");
}

void destruirLista(ListaC *pL){
    Nodo *pNodo, *pNodoAux;
    if(!esListaCVacia(*pL)){
        pNodo = pL->cabeza;
        do{
            pNodoAux = pNodo->sig;
            free(pNodo);
            pNodo = pNodoAux;
        } while(pNodo != pL->cabeza);
        pL->cabeza = NULL;
    }
}