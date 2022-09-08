/* 
 * File:   ListasCirculares.h
 * Author: Branny
 *
 * Created on September 8, 2022, 8:45 AM
 */

#ifndef LISTASCIRCULARES_H
#define LISTASCIRCULARES_H

typedef int ElementoListaC;

typedef struct nodo{
    ElementoListaC elemento;
    struct nodo *sig;
} Nodo;

typedef struct listaC{
    Nodo *cabeza;
} ListaC;

void crearListaC(ListaC *pL);

int esListaCVacia(ListaC l);

Nodo* crearNuevoNodo(ElementoListaC elemento, Nodo *sig);

Nodo* obtenerUltimoNodo(ListaC l);

void insertarComienzo(ListaC *pL, ElementoListaC elemento);

void insertarFinal(ListaC *pL, ElementoListaC elemento);

void mostrarListaC(ListaC l);

Nodo* obtenerNodo(ListaC l, ElementoListaC elemento);

Nodo* obtenerAnterior(ListaC l, ElementoListaC elemento);

void eliminarNodo(ListaC *pL, ElementoListaC elemento);

void destruirLista(ListaC *pL);

#endif /* LISTASCIRCULARES_H */

