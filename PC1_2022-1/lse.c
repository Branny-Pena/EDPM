
/* 
 * File:   lse.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 6, 2022, 10:15 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lse.h"

void crearLista(Lista *lista){
    lista->cabeza = NULL;
}

int esListaVacia(Lista lista){
    return lista.cabeza == NULL;
}

Nodo* crearNuevoNodo(ElementoLista elemento, Nodo *sgte){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sgte = sgte;
    return pNuevoNodo;
}

void insertarComienzo(Lista *lista, ElementoLista elemento){
    Nodo* pNuevoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, lista->cabeza);
    lista->cabeza = pNuevoNodo;
}

void mostrarLista(Lista lista){
    Nodo* pNodo;
    if(esListaVacia(lista))
        printf("La lista esta vacia\n");
    else{
        pNodo = lista.cabeza;
        printf("%s\n", lista.nombre);
        while(pNodo != NULL){
            printf("%s\n", pNodo->elemento.titulo);
            printf("%s\n", pNodo->elemento.autor);
            printf("%02d:%02d\n", pNodo->elemento.duracionM, pNodo->elemento.duracionS);
            pNodo = pNodo->sgte;
        }
    }
}

void destruirLista(Lista *lista){
    Nodo* pNodo, *pNodoAux;
    pNodo = lista->cabeza;
    while(pNodo != NULL){
        pNodoAux = pNodo->sgte;
        free(pNodo);
        pNodo = pNodoAux;
    }
    lista->cabeza = NULL;
}

void insertar_en_orden(Lista *tad, ElementoLista elemento){
    Nodo *nuevo_nodo = crearNuevoNodo(elemento, NULL);
    Nodo *nodo_anterior = obtenerNodoAnterior(*tad, elemento);    
    if (nodo_anterior==NULL){
        nuevo_nodo->sgte = tad->cabeza;
        tad->cabeza=nuevo_nodo;
    }else{    
        nuevo_nodo->sgte=nodo_anterior->sgte;
        nodo_anterior->sgte=nuevo_nodo;
    }
    tad->longitud++;     
}

Nodo* obtenerNodoAnterior(Lista lista, ElementoLista elemento){
    Nodo *pNodoAnterior = NULL;
    Nodo *pNodo = lista.cabeza;
    while(pNodo != NULL && strcmp(pNodo->elemento.titulo, elemento.titulo) < 0){
        pNodoAnterior = pNodo;
        pNodo = pNodoAnterior->sgte;
    }
    return pNodoAnterior;
}
