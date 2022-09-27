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

