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

typedef struct{
    int codigo;
    double peso;
    char fecha[10];
    char tipo[10];
} ElementoArbol;

typedef struct nodoab{
    ElementoArbol elemento;    
    struct nodoab *hijo_izq;
    struct nodoab *hijo_der;
}NodoArbol;

typedef NodoArbol* ArbolB;

void construir_ab(ArbolB *);
NodoArbol* crear_nodoab(ElementoArbol ,ArbolB ,ArbolB );
void insertar_ab(ArbolB* ,ElementoArbol ,ArbolB ,ArbolB );
void en_orden(ArbolB );
int altura(ArbolB );
void destruir_ab(ArbolB *);
int cuenta_nodos(ArbolB );
int cuenta_hojas(ArbolB );
void imprimirelemento(ElementoArbol);
void post_orden(ArbolB );
int es_arbol_vacio(ArbolB);
void pre_orden(ArbolB);

#endif /* AB_H */
