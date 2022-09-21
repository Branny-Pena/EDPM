#include <stdio.h>
#include <stdlib.h>
#include "ArbolesBinarios.h"
#include "ArbolBinarioBusqueda.h"

//se especifica segun el problema
int comparaAbb(ElementoArbol a, ElementoArbol b){
    if(a==b)
        return 0;
    if(a<b) 
        return -1;
    if(a>b)
        return 1;
}

void insertarAbb(ArbolBB *tad, ElementoArbol dato){
    if(esArbolVacio(*tad))
        insertarAb(tad, dato, NULL, NULL);
    else{
        if(!comparaAbb((*tad)->elemento, dato)){
            printf("No se puede insertar repetido");
            return;
        }
        if(comparaAbb(tad->elemento, dato) == 1)
            insertarAbb(&(*tad)->hIzq, dato);
        else{
            insertarAbb(&(*tad)->hDrch, dato);
        }
    }
}

ElementoArbol minimoAbb(ArbolBB tad){
    if(esArbolVacio(tad)){
        printf("El arbol esta vacio");
        exit(2);
    }
    if(esArbolVacio(tad->hIzq))
        return tad->elemento;
    minimoAbb(tad->hIzq);
}

ElementoArbol maximoAbb(ArbolBB tad){
    if(esArbolVacio(tad)){
        printf("El arbol esta vacio");
        exit(2);
    }
    if(esArbolVacio(tad->hDrch))
        return tad->elemento;
    maximoAbb(tad->hDrch);
}

//maximo del lado izquierdo o el minimo del lado derecho para borrar nodo
ArbolBB borraNodo(ArbolBB tad, ElementoArbol dato){
    if(esArbolVacio(tad))
        return tad;
    if(comparaAbb(tad->elemento, dato) == 1)
        tad->hIzq = borraNodo(tad->hIzq, dato);
    else{
        if(comparaAbb(tad->elemento, dato) == -1)
            tad->hDrch = borraNodo(tad->hDrch, dato);
        else{
            if(esArbolVacio(tad->hIzq)){
                ArbolBB temp = tad->hDrch;
                free(tad);
                return temp;
            }
            else{
                if(esArbolVacio(tad->hDrch)){
                    ArbolBB temp = tad->hIzq;
                    free(tad);
                    return temp;
                }
                else{
                    ArbolBB temp = minimoArbol(tad->hDrch);
                    tad->elemento = temp->elemento;
                    tad->hDrch = borraNodo(tad->hDrch, temp->elemento);
                }
            }
        }
    }
    return tad;
}

ArbolBB minimoArbol(ArbolBB tad){
    if(esArbolVacio(tad)){
        return tad;
    }
    if(esArbolVacio(tad->hIzq))
        return tad;
    minimoArbol(tad->hIzq);
}

ArbolBB buscarArbol(ArbolBB tad, ElementoArbol dato){
    if(esArbolVacio(tad)){
        return tad;
    }
    if(comparaAbb(tad->elemento, dato) == 0){
        return tad;
    }
    if(comparaAbb(tad->elemento, dato) == 1){
        return buscarArbol(tad->hDrch, dato);
    }
    else{
        if(comparaAbb(tad->elemento, dato) == -1){
            return buscarArbol(tad->hDrch, dato);
        }
    }
}

