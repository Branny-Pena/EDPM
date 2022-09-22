/* 
 * File:   FuncionesPilas.h
 * Author: Branny
 *
 * Created on September 15, 2022, 9:28 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H
#include "Pila1.h"

void construirPila(Pila1 *);

int esPilaVacia(Pila1 );

NodoPila1* crearNuevoNodoPila(ElementoPila1 , NodoPila1 *);

void apilar(Pila1 *, ElementoPila1 );

void mostrarPila1(Pila1);

int obtenerLongitudPila(Pila1);

ElementoPila1 desapilar(Pila1 *);

#endif /* FUNCIONESPILAS_H */

