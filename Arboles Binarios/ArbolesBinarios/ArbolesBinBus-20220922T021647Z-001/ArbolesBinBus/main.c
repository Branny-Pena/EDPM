/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 14 de septiembre de 2022, 09:28 AM
 */
#include "Abb.h"
#include "Ab.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    ArbolBB arbol1;
    ElementoArbol auxele;
    
    construir_ab(&arbol1);
    insertar_abb(&arbol1,20);
    insertar_abb(&arbol1,10);
    insertar_abb(&arbol1,11);
    insertar_abb(&arbol1,25);
    insertar_abb(&arbol1,9);
    insertar_abb(&arbol1,13);
    insertar_abb(&arbol1,15);
    insertar_abb(&arbol1,19);
    en_orden(arbol1);
    printf("\n");
    post_orden(arbol1);
    auxele=minimoabb(arbol1);
    printf("\n");
    imprimirelemento(auxele);
    
    auxele=maximoabb(arbol1);
    printf("\n");
    imprimirelemento(auxele);
    printf("\n");    
    post_orden(arbol1);
    arbol1=borranodo(arbol1,19);
    printf("\n");
    post_orden(arbol1);
    printf("\n");
    recorrido_nivel(arbol1);
    
    return 0;
}

