/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 27, 2022, 8:21 AM
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
    aux.llave = "Alumno";
    aux.valor = "Delegado";
    registrar_entrada(&tabla1, aux);
    
    aux.llave = "Profesor";
    aux.valor = "Viktor ya viene";
    registrar_entrada(&tabla1, aux);
    
    aux.llave = "JP";
    aux.valor = "Se van rapido";
    registrar_entrada(&tabla1, aux);
    
    aux.llave = "Arboles";
    aux.valor = "Es muy temido en LP1";
    registrar_entrada(&tabla1, aux);
    
    aux.llave = "Robot";
    aux.valor = "Siempre viene";
    registrar_entrada(&tabla1, aux);
    en_orden(tabla1);
    
    elimina_entrada(&tabla1, "JP");
    printf("\n");
    en_orden(tabla1);
    
    actualiza_entrada(&tabla1, "Robot", "Siempre viene y nunca les sale");
    printf("\n");
    en_orden(tabla1);
    
    destruir_tabla(&tabla1);
    en_orden(tabla1);
    return (EXIT_SUCCESS);
}

