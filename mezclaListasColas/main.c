
/* 
 * File:   main.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 * Created on September 21, 2022, 6:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesPilas.h"
#include "FuncionesColas.h"
#include "FuncionesPizza.h"

int main(int argc, char** argv){
    Cola1 c1;
    construirCola(&c1);
    ElementoCola1 datoC1;
    strcpy(datoC1.ingredientes, "Pepperoni");
    datoC1.peso = 20;
    encolar(&c1, datoC1);
    
    strcpy(datoC1.ingredientes, "Pina");
    datoC1.peso = 30;
    encolar(&c1, datoC1);
    
    strcpy(datoC1.ingredientes, "Jamon");
    datoC1.peso = 30;
    encolar(&c1, datoC1);
    mostrarCola(c1);
    
    Pila1 p1;
    construirPila(&p1);
    
    formarPilaDeCola(&c1, &p1);
    mostrarPila1(p1);
    return (EXIT_SUCCESS);
}

