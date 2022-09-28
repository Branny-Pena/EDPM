#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla.h"
#include "Ab.h"
#include "Abb.h"

void construir_tabla(Tabla *tad){
    construir_ab(tad);
}

void registrar_entrada(Tabla *tad, ElementoArbol dato){
    ArbolBB aux;
    aux = buscaarbol(*tad, dato);
    if(es_arbol_vacio(aux))
        insertar_abb(tad, dato);
    else
        printf("Llave ya existe no se puede registrar\n");
}

void elimina_entrada(Tabla *tad, char *llave){
    ElementoTabla temp;
    temp.llave = llave;
    temp.valor = NULL;
     *tad = borranodo(*tad, temp);
}

void destruir_tabla(Tabla *tad){
    destruir_ab(tad);
}

void actualiza_entrada(Tabla *tad, char *llave, char *nvalor){
    ElementoTabla temp;
    ArbolBB aux;
    
    temp.llave = (char*)malloc(sizeof(char)*strlen((llave)+1));
    strcpy(temp.llave, llave);
    
    temp.valor = (char*)malloc(sizeof(char)*strlen((nvalor)+1));
    strcpy(temp.valor, nvalor);
    
    aux = buscaarbol(*tad, temp);
    if(es_arbol_vacio(*tad))
        printf("No se puede actualizar\n");
    else
        asigna(&(aux->elemento), temp);
    
    free(temp.llave);
    free(temp.valor);
}