
/* 
 * File:   FuncionesColas.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:56 PM
 */

#ifndef FUNCIONESCOLAS_H
#define FUNCIONESCOLAS_H
#include "ColaEmpaquetado.h"

void construirColaEmpqt(ColaEmpqt *pC);

int esColaVaciaEmpqt(ColaEmpqt c);

NodoColaEmpqt* crearNuevoNodoColaEmpqt(ElColaEmpqt elemento);

void encolarEmpqt(ColaEmpqt *pC, ElColaEmpqt elemento);

void mostrarColaEmpqt(FILE* arch, ColaEmpqt c);

ElColaEmpqt desencolarEmpqt(ColaEmpqt *pC);

#endif /* FUNCIONESCOLAS_H */

