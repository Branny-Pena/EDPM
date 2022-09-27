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
    
    en_orden(tabla1);
    
    elimina_entrada(&tabla1, "Alumno");
    printf("\n");
    en_orden(tabla1);
    
    return (EXIT_SUCCESS);
}

