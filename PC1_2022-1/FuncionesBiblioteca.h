
/* 
 * File:   FuncionesBiblioteca.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 6, 2022, 11:58 AM
 */

#ifndef FUNCIONESBIBLIOTECA_H
#define FUNCIONESBIBLIOTECA_H
#include "lse.h"

FILE *abrirArchivo(const char *nombre,const char*modo);

void leerCadena(char *cadena,int tope, FILE *Archivo);

char *leeCadenaExacta(FILE *arch);

void sacaPalabras(char *cadena,char **palabras,int *num_pal,char carSep);

void leerBiblioteca();

ElementoLista obtenerCancion(FILE* archBiblio);

#endif /* FUNCIONESBIBLIOTECA_H */

