/* 
 * File:   ListasSimEnlazadas.h
 * Author: Branny
 *
 * Created on September 4, 2022, 5:25 PM
 */

#ifndef LISTASSIMENLAZADAS_H
#define LISTASSIMENLAZADAS_H

typedef int ElementoLista;

typedef struct nodo{
    ElementoLista elemento;
    struct nodo *sig;
} Nodo;

typedef struct lista{
    Nodo *cabeza;
} Lista;

void crearLista(Lista *pL);

int esListaVacia(Lista l);

//Devuelve la direccion donde se creo el nuevo nodo
Nodo* crearNuevoNodo(ElementoLista elemento, Nodo *sig);

void insertarComienzo(Lista *pL, ElementoLista elemento);

void mostrarLista(Lista l);

Nodo* obtenerUltimoNodo(Lista l);

void insertarFinal(Lista *pL, ElementoLista elemento);

int buscar(Lista l, ElementoLista elemento);

Nodo* obtenerNodo(Lista l, ElementoLista elemento);

Nodo* obtenerAnterior(Lista l, ElementoLista elemento);

Nodo* obtenerSiguiente(Lista l, ElementoLista elemento);

void eliminarNodo(Lista *pL, ElementoLista elemento);

int obtenerLongitud(Lista l);

void destruirLista(Lista *pL);

#endif /* LISTASSIMENLAZADAS_H */

