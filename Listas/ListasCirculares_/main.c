/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 8, 2022, 8:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListasCirculares.h"

int main(int argc, char** argv) {
    ListaC lista;
    crearListaC(&lista);
    mostrarListaC(lista);
    insertarComienzo(&lista, 42);
    mostrarListaC(lista);
    insertarComienzo(&lista, 74);
    mostrarListaC(lista);
    insertarFinal(&lista, 93);
    mostrarListaC(lista);
    insertarFinal(&lista, 98);
    mostrarListaC(lista);
/*
    eliminarNodo(&lista, 50);
    eliminarNodo(&lista, 42);
    mostrarListaC(lista);
    eliminarNodo(&lista, 98);
    mostrarListaC(lista);
    eliminarNodo(&lista, 93);
    mostrarListaC(lista);
    eliminarNodo(&lista, 74);
*/
    destruirLista(&lista);
    mostrarListaC(lista);
    
    return (EXIT_SUCCESS);
}

