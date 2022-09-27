/* 
 * File:   Tabla.h
 * Author: Branny
 *
 * Created on September 27, 2022, 8:27 AM
 */

#ifndef TABLA_H
#define TABLA_H
#include "Abb.h"

typedef ArbolBB Tabla;

typedef ElementoArbol ElementoTabla;

void construir_tabla(Tabla *);

void registrar_entrada(Tabla *, ElementoArbol);

void elimina_entrada(Tabla *, char *);

#endif /* TABLA_H */

