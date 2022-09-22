/* 
 * File:   FuncionesColas.h
 * Author: Branny
 *
 * Created on September 10, 2022, 9:39 AM
 */

#ifndef FUNCIONESCOLAS_H
#define FUNCIONESCOLAS_H
#include "Cola1.h"

void construirCola(Cola1 *);

int esColaVacia(Cola1 );

NodoCola1* crearNuevoNodoCola(ElementoCola1 );

void encolar(Cola1 *, ElementoCola1 );

void mostrarCola(Cola1);

int obtenerLongitudCola(Cola1);

ElementoCola1 desencolar(Cola1 *);

#endif /* FUNCIONESCOLAS_H */

