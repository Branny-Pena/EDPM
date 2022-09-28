
/* 
 * File:   FuncionesColasPs.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:58 PM
 */

#ifndef FUNCIONESCOLASPS_H
#define FUNCIONESCOLASPS_H
#include "ColaPesado.h"

void construirColaPeso(ColaPeso *pC);

int esColaVaciaPeso(ColaPeso c);

NodoColaPeso* crearNuevoNodoColaPeso(ElColaPeso elemento);

void encolarPeso(ColaPeso *pC, ElColaPeso elemento);

void mostrarColaPeso(ColaPeso c);

ElColaPeso desencolarPeso(ColaPeso *pC);

#endif /* FUNCIONESCOLASPS_H */

