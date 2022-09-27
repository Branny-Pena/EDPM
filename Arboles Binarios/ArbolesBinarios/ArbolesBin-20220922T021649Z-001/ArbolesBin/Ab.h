/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ab.h
 * Author: cueva.r
 *
 * Created on 13 de septiembre de 2022, 08:43 AM
 */

#ifndef AB_H
#define AB_H

typedef int ElementoArbol;

typedef struct nodo{
    ElementoArbol elemento;    
    struct nodo *hijo_izq;
    struct nodo *hijo_der;
}NodoArbol;

typedef NodoArbol* ArbolB;

void construir_ab(ArbolB *tad);
NodoArbol* crear_nodo(ElementoArbol ,ArbolB ,ArbolB );
void insertar_ab(ArbolB* ,ElementoArbol ,ArbolB ,ArbolB );
void en_orden(ArbolB );
int altura(ArbolB );
void destruir_ab(ArbolB *);
int cuenta_nodos(ArbolB );
int cuenta_hojas(ArbolB );

#endif /* AB_H */
