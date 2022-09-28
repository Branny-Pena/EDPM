/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 28, 2022, 9:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Abb.h"
#include "Tabla.h"
#include "lse.h"

int main(int argc, char** argv) {
    Tabla tabla1;
    ElementoTabla aux;
    construir_tabla(&tabla1);
    aux.codigo = 1;
    aux.peso = 1.9;
    registrar_entrada(&tabla1, aux);
    
    aux.codigo = 2;
    aux.peso = 0.8;
    registrar_entrada(&tabla1, aux);
    
    aux.codigo = 3;
    aux.peso = 1.1;
    registrar_entrada(&tabla1, aux);
    
    aux.codigo = 4;
    aux.peso = 1.2;
    registrar_entrada(&tabla1, aux);
    
    aux.codigo = 5;
    aux.peso = 1.5;
    registrar_entrada(&tabla1, aux);
    en_orden(tabla1);
    
    elimina_entrada(&tabla1, 1);
    printf("\n");
    en_orden(tabla1);
    
    actualiza_entrada(&tabla1, 3, 5);
    printf("\n");
    en_orden(tabla1);
    
    aux.codigo = 1;
    aux.peso = 3.9;
    registrar_entrada(&tabla1, aux);
    
    printf("\n");
    pre_orden(tabla1);
    printf("\n");
    en_orden(tabla1);
    
    destruir_tabla(&tabla1);
    en_orden(tabla1);
    return (EXIT_SUCCESS);
}