
/* 
 * File:   FuncionesListas.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 8, 2022, 4:39 PM
 */

#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H
#include "ListaSimEnlazada.h"

void crearLista(Lista *pL);

int esListaVacia(Lista l);

Nodo* crearNuevoNodo(ElementoLista elemento, Nodo* sgte);

void insertarComienzo(Lista *pL, ElementoLista elemento);

void mostrarLista(Lista l);

void insertarClienteOrden(Lista *pL, ElementoLista elemento);

void insertarOrdenadoVip(Lista *lista, ElementoLista elemento, Nodo *pNodo);

Nodo* obtenerAnteriorV(Lista *lista, ElementoLista elemento);

void insertarOrdenadoNormal(Lista *lista, ElementoLista elemento, Nodo* fin);

Nodo* obtenerAnteriorC(Nodo* inicio, ElementoLista elemento, Nodo* fin);

Nodo* acceso(Lista lista, ElementoLista elemento);

Nodo* buscarElemento(Nodo* inicio, Nodo* fin, ElementoLista elemento);

void actualizacion(Lista *pL, ElementoLista elemento);

void cargarElementos(Cliente *elemento1, Cliente *elemento2, Cliente *elemento3,
        Cliente *elemento4, Cliente *elemento5, Cliente *elemento6, Lista l);

void actualizarElementos(Cliente *elemento1, Cliente *elemento2, Cliente *elemento3,
        Cliente *elemento4, Cliente *elemento5, Cliente *elemento6, Lista l);

void eliminarNodo(Lista *pL, ElementoLista elemento);

Nodo* buscarAnterior(Lista *pL, ElementoLista elemento);

Nodo* obtenerNodo(Lista l, ElementoLista elemento);

#endif /* FUNCIONESLISTAS_H */

