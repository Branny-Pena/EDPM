/* 
 * File:   ArbolBinarioBusqueda.h
 * Author: Branny
 *
 * Created on September 20, 2022, 8:16 AM
 */

#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H
#include "ArbolesBinarios.h"

typedef arbolBinario ArbolBB;

void insertarAbb(ArbolBB *, ElementoArbol);

ElementoArbol minimoAbb(ArbolBB tad);

ElementoArbol maximoAbb(ArbolBB tad);

ArbolBB minimoArbol(ArbolBB tad);

ArbolBB borraNodo(ArbolBB tad, ElementoArbol dato);

int comparaAbb(ElementoArbol a, ElementoArbol b);

#endif /* ARBOLBINARIOBUSQUEDA_H */

