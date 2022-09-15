/* 
 * File:   FuncionesPilas.h
 * Author: Branny
 *
 * Created on September 15, 2022, 9:28 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

typedef int ElementoPila;

typedef struct nodo{
    ElementoPila elemento;
    struct nodo *sig;
} Nodo;

typedef struct pila{
    Nodo *cima;
    int longitud;
} Pila;

void construirPila(Pila *pP);

int esPilaVacia(Pila p);

Nodo* crearNuevoNodo(ElementoPila elemento, Nodo *sgte);

void apilar(Pila *pP, ElementoPila elemento);

void mostrar(Pila p);

#endif /* FUNCIONESPILAS_H */

