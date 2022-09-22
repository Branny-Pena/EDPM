
/* 
 * File:   FuncionesPizza.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 21, 2022, 7:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesColas.h"
#include "FuncionesPilas.h"
#include "FuncionesPizza.h"

void formarPilaDeCola(Cola1 *pc1, Pila1 *pp1){
    ElementoCola1 datoC1;
    ElementoPila1 datoP1;
    NodoCola1 *pNodoC1;
    while(!esColaVacia(*pc1)){
        datoC1 = desencolar(pc1);
        
        strcpy(datoP1.ingredientes, datoC1.ingredientes);
        datoP1.peso = datoC1.peso;
        
        if(strcmp(datoC1.ingredientes, "Pepperoni") == 0)
            strcpy(datoP1.sabor, "Pepperoni");

        if(strcmp(datoC1.ingredientes, "Jamon") == 0)
            strcpy(datoP1.sabor, "Americana");

        if(strcmp(datoC1.ingredientes, "Pina") == 0)
            strcpy(datoP1.sabor, "Hawaiana");

        apilar(pp1, datoP1);
    }
}
