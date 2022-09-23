
/* 
 * File:   FuncionesColas.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesColasEmpqt.h"
#include "ColaEmpaquetado.h"

void construirColaEmpqt(ColaEmpqt *pC){
    pC->cabeza = NULL;
    pC->cola = NULL;
}

int esColaVaciaEmpqt(ColaEmpqt c){
    return c.cabeza == NULL;
}

NodoColaEmpqt* crearNuevoNodoColaEmpqt(ElColaEmpqt elemento){
    NodoColaEmpqt *pNuevoNodoCola;
    pNuevoNodoCola = (NodoColaEmpqt*)malloc(sizeof(NodoColaEmpqt));
    pNuevoNodoCola->elemento = elemento;
    pNuevoNodoCola->sig = NULL;
    return pNuevoNodoCola;
}

void encolarEmpqt(ColaEmpqt *pC, ElColaEmpqt elemento){
    NodoColaEmpqt *pNuevoNodoCola, *pFinal;
    pNuevoNodoCola = crearNuevoNodoColaEmpqt(elemento);
    if(esColaVaciaEmpqt(*pC))
        pC->cabeza = pNuevoNodoCola;
    else{
        pFinal = pC->cola;
        pFinal->sig = pNuevoNodoCola;
    }
    pC->cola = pNuevoNodoCola;
}

void mostrarColaEmpqt(FILE* arch, ColaEmpqt c){
    NodoColaEmpqt *pNodoCola;
    if(esColaVaciaEmpqt(c))
        fprintf(arch, "La cola esta vacia\n");
    else{
        pNodoCola = c.cabeza;
        while(pNodoCola != NULL){
            ElColaEmpqt dato = pNodoCola->elemento;
            fprintf(arch, "%4d %15s %6.2lfg\n", dato.codigo, dato.fecha, dato.peso);
            pNodoCola = pNodoCola->sig;
        }
        fprintf(arch, "\n");
    }
}

ElColaEmpqt desencolarEmpqt(ColaEmpqt *pC){
    NodoColaEmpqt *pNodoCola;
    ElColaEmpqt elemento;
    pNodoCola = pC->cabeza;
    elemento = pNodoCola->elemento;
    pC->cabeza = pNodoCola->sig;
    if(pNodoCola->sig == NULL)
        pC->cola = NULL;
    free(pNodoCola);
    return elemento;
}
