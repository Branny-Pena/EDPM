/* 
 * File:   FuncionesListasDE.h
 * Author: Branny
 *
 * Created on September 10, 2022, 8:09 AM
 */

#ifndef FUNCIONESLISTASDE_H
#define FUNCIONESLISTASDE_H

typedef int ElementoListaDE;

typedef struct nodo{
    struct nodo *ant;
    ElementoListaDE elemento;
    struct nodo *sig;
} Nodo;

typedef struct listaDE{
    Nodo *cabeza;
} ListaDE;

void crearListaDE(ListaDE *pL);

int esListaDEVacia(ListaDE l);

Nodo* crearNuevoNodo(ElementoListaDE elemento, Nodo *ant, Nodo *sgte);

void insertarComienzo(ListaDE *pL, ElementoListaDE elemento);

void mostrarListaDE(ListaDE l);

Nodo* obtenerUltimoNodo(ListaDE l);

void mostrarListaDEreves(ListaDE l);

void insertarFinal(ListaDE *pL, ElementoListaDE elemento);

void eliminarNodo(ListaDE *pL, ElementoListaDE elemento);

void destruirLista(ListaDE *pL);

#endif /* FUNCIONESLISTASDE_H */

