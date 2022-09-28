
/* 
 * File:   FuncionesPilas.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:51 PM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H
#include "PilaClasificacion.h"

void construirPila(PilaClas *pP);

int esPila1Vacia(PilaClas p);

NodoPilaClas* crearNuevoNodoPilaClasPila1(ElPilaClas elemento, NodoPilaClas *sgte);

void apilar(PilaClas *pP, ElPilaClas elemento);

void mostrarPila1(PilaClas p);

ElPilaClas desapilar(PilaClas *pP);

#endif /* FUNCIONESPILAS_H */

