/* 
 * File:   FuncionesColas.h
 * Author: Branny
 *
 * Created on September 10, 2022, 9:39 AM
 */

#ifndef FUNCIONESCOLAS_H
#define FUNCIONESCOLAS_H

typedef int ElementoCola;

typedef struct nodo{
    ElementoCola elemento;
    struct nodo *sig;
} Nodo;

typedef struct cola{
    Nodo *cabeza;
    Nodo *cola;
} Cola;

void construirCola(Cola *pC);

int esColaVacia(Cola c);

Nodo* crearNuevoNodo(ElementoCola elemento);

void encolar(Cola *pC, ElementoCola elemento);

#endif /* FUNCIONESCOLAS_H */

