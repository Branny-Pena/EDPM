
/* 
 * File:   FuncionesPilas.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "PilaClasificacion.h"

void construirPila(PilaClas *pP){
    pP->cima = NULL;
}

int esPila1Vacia(PilaClas p){
    return p.cima == NULL;
}

NodoPilaClas* crearNuevoNodoPilaClasPila1(ElPilaClas elemento, NodoPilaClas *sgte){
    NodoPilaClas *pNuevoNodoPilaClas;
    pNuevoNodoPilaClas = (NodoPilaClas*)malloc(sizeof(NodoPilaClas));
    pNuevoNodoPilaClas->elemento = elemento;
    pNuevoNodoPilaClas->sig = sgte;
    return pNuevoNodoPilaClas;
}

void apilar(PilaClas *pP, ElPilaClas elemento){
    NodoPilaClas *pNuevoNodoPilaClas;
    pNuevoNodoPilaClas = crearNuevoNodoPilaClasPila1(elemento, pP->cima);
    pP->cima = pNuevoNodoPilaClas;
}

void mostrarPila1(PilaClas p){
    NodoPilaClas *pNodoPilaClas;
    if(esPila1Vacia(p))
        printf("La pila esta vacia\n");
    else{
        pNodoPilaClas = p.cima;
        while(pNodoPilaClas != NULL){
            ElPilaClas dato = pNodoPilaClas->elemento;
            printf("%d %s %.2lfg %s\n", dato.codigo, dato.fecha, dato.peso, dato.tipo);
            pNodoPilaClas = pNodoPilaClas->sig;
        }
    }
    printf("\n");
}


ElPilaClas desapilar(PilaClas *pP){
    NodoPilaClas *pNodoPilaClas;
    ElPilaClas elemento;
    pNodoPilaClas = pP->cima;
    elemento = pNodoPilaClas->elemento;
    pP->cima = pNodoPilaClas->sig;
    free(pNodoPilaClas);
    return elemento;
}
