
/* 
 * File:   FuncionesColasPs.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ColaPesado.h"

void construirColaPeso(ColaPeso *pC){
    pC->cabeza = NULL;
    pC->cola = NULL;
}

int esColaVaciaPeso(ColaPeso c){
    return c.cabeza == NULL;
}

NodoColaPeso* crearNuevoNodoColaPeso(ElColaPeso elemento){
    NodoColaPeso *pNuevoNodoCola;
    pNuevoNodoCola = (NodoColaPeso*)malloc(sizeof(NodoColaPeso));
    pNuevoNodoCola->elemento = elemento;
    pNuevoNodoCola->sig = NULL;
    return pNuevoNodoCola;
}

void encolarPeso(ColaPeso *pC, ElColaPeso elemento){
    NodoColaPeso *pNuevoNodoCola, *pFinal;
    pNuevoNodoCola = crearNuevoNodoColaPeso(elemento);
    if(esColaVaciaPeso(*pC))
        pC->cabeza = pNuevoNodoCola;
    else{
        pFinal = pC->cola;
        pFinal->sig = pNuevoNodoCola;
    }
    pC->cola = pNuevoNodoCola;
}

void mostrarColaPeso(ColaPeso c){
    NodoColaPeso *pNodoCola;
    if(esColaVaciaPeso(c))
        printf("La cola esta vacia\n");
    else{
        pNodoCola = c.cabeza;
        while(pNodoCola != NULL){
            ElColaPeso dato = pNodoCola->elemento;
            printf("%d %s %.2lfg\n", dato.codigo, dato.fecha, dato.peso);
            pNodoCola = pNodoCola->sig;
        }
        printf("\n");
    }
}

ElColaPeso desencolarPeso(ColaPeso *pC){
    NodoColaPeso *pNodoCola;
    ElColaPeso elemento;
    pNodoCola = pC->cabeza;
    elemento = pNodoCola->elemento;
    pC->cabeza = pNodoCola->sig;
    if(pNodoCola->sig == NULL)
        pC->cola = NULL;
    free(pNodoCola);
    return elemento;
}
