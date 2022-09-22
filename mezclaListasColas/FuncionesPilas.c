#include <stdio.h>
#include <stdlib.h>
#include "Pila1.h"
#include "FuncionesPilas.h"

void construirPila(Pila1 *pP){
    pP->cima = NULL;
    //pP->longitud = 0;
}

int esPila1Vacia(Pila1 p){
    return p.cima == NULL;
    //return c.longitud == 0;
}

NodoPila1* crearNuevoNodoPila1Pila1(ElementoPila1 elemento, NodoPila1 *sgte){
    NodoPila1 *pNuevoNodoPila1;
    pNuevoNodoPila1 = (NodoPila1*)malloc(sizeof(NodoPila1));
    pNuevoNodoPila1->elemento = elemento;
    pNuevoNodoPila1->sig = sgte;
    return pNuevoNodoPila1;
}

void apilar(Pila1 *pP, ElementoPila1 elemento){
    NodoPila1 *pNuevoNodoPila1;
    pNuevoNodoPila1 = crearNuevoNodoPila1Pila1(elemento, pP->cima);
    pP->cima = pNuevoNodoPila1;
    //pP->longitud++;
}

void mostrarPila1(Pila1 p){
    NodoPila1 *pNodoPila1;
    if(esPila1Vacia(p))
        printf("La pila esta vacia\n");
    else{
        pNodoPila1 = p.cima;
        while(pNodoPila1 != NULL){
            ElementoPila1 dato = pNodoPila1->elemento;
            printf("%s %.2lfg %s\n", dato.ingredientes, dato.peso, dato.sabor);
            pNodoPila1 = pNodoPila1->sig;
        }
    }
    printf("\n");
}

/*
int obtenerLongitudPila1(Pila1 p){
    return p.longitud;
}
*/

ElementoPila1 desapilar(Pila1 *pP){
    NodoPila1 *pNodoPila1;
    ElementoPila1 elemento;
    pNodoPila1 = pP->cima;
    elemento = pNodoPila1->elemento;
    pP->cima = pNodoPila1->sig;
    //pP->longitud--;
    free(pNodoPila1);
    return elemento;
}
