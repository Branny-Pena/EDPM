
/* 
 * File:   Funciones.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 8, 2022, 11:23 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "ListaSimEnlazada.h"

FILE *abrirArchivo(const char *nombre,const char*modo);

void leerCadena(char *cadena,int tope, FILE *Archivo);

void leerClientes(char* nombreArch, Lista* lista);

Cliente obtenerCliente(char tipo, int dni, char* nombre, double saldo);

void realizarModificaciones(char* nombreArch, Lista* lista);

#endif /* FUNCIONES_H */

