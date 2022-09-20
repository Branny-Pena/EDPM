/* 
 * File:   ArbolesBinarios.h
 * Author: Branny
 *
 * Created on September 17, 2022, 9:44 AM
 */

#ifndef ARBOLESBINARIOS_H
#define ARBOLESBINARIOS_H
#include "ArbolBinarioBusqueda.h"

typedef int ElementoArbol;

typedef struct nodo{
    struct nodo *hIzq;
    ElementoArbol elemento;
    struct nodo *hDrch;
} Nodo;

typedef Nodo* arbolBinario;


#endif /* ARBOLESBINARIOS_H */

