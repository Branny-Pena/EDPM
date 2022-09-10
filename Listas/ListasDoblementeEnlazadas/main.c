/* 
 * File:   main.c
 * Author: Branny
 *
 * Created on September 10, 2022, 8:08 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesListasDE.h"

int main(int argc, char** argv) {
    ListaDE lD;
    crearListaDE(&lD);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    insertarComienzo(&lD, 52);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    insertarComienzo(&lD, 39);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    insertarComienzo(&lD, 61);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    insertarFinal(&lD, 24);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    insertarFinal(&lD, 15);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    eliminarNodo(&lD, 39);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    eliminarNodo(&lD, 15);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    eliminarNodo(&lD, 61);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    destruirLista(&lD);
    mostrarListaDE(lD);
    mostrarListaDEreves(lD);
    
    return (EXIT_SUCCESS);
}

