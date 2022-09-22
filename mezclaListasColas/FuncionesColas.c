#include <stdio.h>
#include <stdlib.h>
#include "Cola1.h"
#include "FuncionesColas.h"

void construirCola(Cola1 *pC){
    pC->cabeza = NULL;
    pC->cola = NULL;
    //pC->longitud = 0;
}

int esColaVacia(Cola1 c){
    return c.cabeza == NULL;
    //return c.longitud == 0;
}

NodoCola1* crearNuevoNodoCola(ElementoCola1 elemento){
    NodoCola1 *pNuevoNodoCola;
    pNuevoNodoCola = (NodoCola1*)malloc(sizeof(NodoCola1));
    pNuevoNodoCola->elemento = elemento;
    pNuevoNodoCola->sig = NULL;
    return pNuevoNodoCola;
}

void encolar(Cola1 *pC, ElementoCola1 elemento){
    NodoCola1 *pNuevoNodoCola, *pFinal;
    pNuevoNodoCola = crearNuevoNodoCola(elemento);
    if(esColaVacia(*pC))
        pC->cabeza = pNuevoNodoCola;
    else{
        pFinal = pC->cola;
        pFinal->sig = pNuevoNodoCola;
    }
    pC->cola = pNuevoNodoCola;
}

void mostrarCola(Cola1 c){
    NodoCola1 *pNodoCola;
    if(esColaVacia(c))
        printf("La cola esta vacia\n");
    else{
        pNodoCola = c.cabeza;
        while(pNodoCola != NULL){
            ElementoCola1 dato = pNodoCola->elemento;
            printf("%s %.2lfg\n", dato.ingredientes, dato.peso);
            pNodoCola = pNodoCola->sig;
        }
        printf("\n");
    }
}

/*
int obtenerLongitudCola(Cola1 c){
    return c.longitud;
}
*/

ElementoCola1 desencolar(Cola1 *pC){
    NodoCola1 *pNodoCola;
    ElementoCola1 elemento;
    pNodoCola = pC->cabeza;
    elemento = pNodoCola->elemento;
    pC->cabeza = pNodoCola->sig;
    if(pNodoCola->sig == NULL)
        pC->cola = NULL;
    free(pNodoCola);
    return elemento;
}
