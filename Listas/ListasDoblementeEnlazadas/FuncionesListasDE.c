#include <stdio.h>
#include <stdlib.h>
#include "FuncionesListasDE.h"

void crearListaDE(ListaDE *pL){
    pL->cabeza = NULL;
}

int esListaDEVacia(ListaDE l){
    return l.cabeza == NULL;
}

Nodo* crearNuevoNodo(ElementoListaDE elemento, Nodo *ant, Nodo *sgte){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->ant = ant;
    pNuevoNodo->sig = sgte;
    return pNuevoNodo;
}

void insertarComienzo(ListaDE *pL, ElementoListaDE elemento){
    Nodo *pNuevoNodo, *pNodoPrimero;
    pNuevoNodo = crearNuevoNodo(elemento, NULL, pL->cabeza);
    if(!esListaDEVacia(*pL)){
        pNodoPrimero = pL->cabeza;
        pNodoPrimero->ant = pNuevoNodo;
    }
    pL->cabeza = pNuevoNodo;
}

void mostrarListaDE(ListaDE l){
    Nodo *pNodo;
    if(esListaDEVacia(l))
        printf("La lista esta vacia\n");
    else{
        pNodo = l.cabeza;
        while(pNodo != NULL){
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        } 
        printf("\n");
    }
}

Nodo* obtenerUltimoNodo(ListaDE l){
    Nodo *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}

void mostrarListaDEreves(ListaDE l){
    Nodo *pNodo;
    if(esListaDEVacia(l))
        printf("La lista esta vacia\n");
    else{
        pNodo = obtenerUltimoNodo(l);
        while(pNodo != NULL){
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->ant;
        } 
        printf("\n");
    }
}

void insertarFinal(ListaDE *pL, ElementoListaDE elemento){
    Nodo *pUltimo, *pNuevoNodo;
    pUltimo = obtenerUltimoNodo(*pL);
    pNuevoNodo = crearNuevoNodo(elemento, pUltimo, NULL);
    if(pUltimo == NULL)
        pL->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
}

Nodo* obtenerNodo(ListaDE l, ElementoListaDE elemento){
    Nodo *pNodo;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        if(pNodo->elemento == elemento)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

void eliminarNodo(ListaDE *pL, ElementoListaDE elemento){
    Nodo *pNodoEliminar, *pNodoAnterior, *pNodoSgte;
    pNodoEliminar = obtenerNodo(*pL, elemento);
    if(pNodoEliminar != NULL){
        pNodoAnterior = pNodoEliminar->ant;
        pNodoSgte = pNodoEliminar->sig;
        if(pNodoAnterior == NULL){
            pL->cabeza = pNodoSgte;
            pNodoSgte->ant = NULL;
        }
        else{
            pNodoAnterior->sig = pNodoSgte;
            if(pNodoSgte != NULL)
                pNodoSgte->ant = pNodoAnterior;
        }
        free(pNodoEliminar);
        printf("El nodo ha sido eliminado\n");
    }
    else
        printf("No existe el elemento\n");
}

void destruirLista(ListaDE *pL){
    Nodo *pNodo, *pNodoAux;
    pNodo = pL->cabeza;
    while(pNodo != NULL){
        pNodoAux = pNodo->sig;
        free(pNodo);
        pNodo = pNodoAux;
    }
    pL->cabeza = NULL;
    printf("Todos los nodos han sido eliminados\n");
}