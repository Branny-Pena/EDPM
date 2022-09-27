/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 13 de septiembre de 2022, 08:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Ab.h"

int main(int argc, char** argv) {
    ArbolB arbol1,arbol2,arbol3,arbol4;
    
    construir_ab(&arbol1);
    insertar_ab(&arbol1,5,NULL,NULL);
    insertar_ab(&arbol2,4,NULL,NULL);
    insertar_ab(&arbol3,10,arbol1,arbol2);
    insertar_ab(&arbol4,6,arbol3,NULL);
    en_orden(arbol4);
    printf("\nLa altura es:%d\n",altura(arbol4));
    printf("El numero de nodos es:%d\n",cuenta_nodos(arbol4));
    printf("El numero de hojas es:%d\n",cuenta_hojas(arbol4));
    
    destruir_ab(&arbol4);
    en_orden(arbol4);
    printf("\nLa altura es:%d\n",altura(arbol4));
    
    return 0;
}

