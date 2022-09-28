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

void elimina_entrada(Tabla *tad, int codigo){
    ElementoTabla temp;
    temp.codigo = codigo;
    temp.peso = 0;
     *tad = borranodo(*tad, temp);
}

void destruir_tabla(Tabla *tad){
    destruir_ab(tad);
}

void actualiza_entrada(Tabla *tad, int codigo, double peso){
    ElementoTabla temp;
    ArbolBB aux;
    
    temp.codigo = codigo;
    temp.peso = peso;
    
    aux = buscaarbol(*tad, temp);
    if(es_arbol_vacio(*tad))
        printf("No se puede actualizar\n");
    else
        asigna(&(aux->elemento), temp);
}