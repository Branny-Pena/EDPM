#include <stdio.h>
#include <stdlib.h>
#include "ListasSimEnlazadas.h"

void crearLista(Lista *pL){
    pL->cabeza = NULL;
}

int esListaVacia(Lista l){
    return l.cabeza == NULL;
}

//Devuelve la direccion donde se creo el nuevo nodo
Nodo* crearNuevoNodo(ElementoLista elemento, Nodo *sig){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

void insertarComienzo(Lista *pL, ElementoLista elemento){
    Nodo *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, pL->cabeza);
    pL->cabeza = pNuevoNodo;
}

void mostrarLista(Lista l){
    Nodo *pNodo;
    if(esListaVacia(l))
        printf("La lista esta vacia\n");
    else{
        pNodo = l.cabeza;
        while(pNodo != NULL){
            printf("%d ", pNodo->elemento);
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}

Nodo* obtenerUltimoNodo(Lista l){
    Nodo *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
}

void insertarFinal(Lista *pL, ElementoLista elemento){
    Nodo *pUltimo, *pNuevoNodo;
    pNuevoNodo = crearNuevoNodo(elemento, NULL);
    pUltimo = obtenerUltimoNodo(*pL);
    if(pUltimo == NULL)
        pL->cabeza = pNuevoNodo;
    else
        pUltimo->sig = pNuevoNodo;
}

int buscar(Lista l, ElementoLista elemento){
    Nodo *pNodo;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        if(pNodo->elemento == elemento)
            return 1;
        pNodo = pNodo->sig;
    }
    return 0;
}

/*                    MIO
Nodo* obtenerNodo(Lista l, ElementoLista elemento){
    Nodo *pNodo, *pNodoPosicion;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        if(pNodo->elemento == elemento){
            pNodoPosicion = pNodo;
            return pNodoPosicion;
        }
        pNodo = pNodo->sig;
    }
    return NULL;
}
*/

Nodo* obtenerNodo(Lista l, ElementoLista elemento){
    Nodo *pNodo;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        if(pNodo->elemento == elemento)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

Nodo* obtenerAnterior(Lista l, ElementoLista elemento){
    Nodo *pNodo, *pNodoAnterior;
    pNodo = l.cabeza;
    pNodoAnterior = NULL;
    while(pNodo != NULL){
        if(pNodo->elemento == elemento)
            break;
        pNodoAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pNodoAnterior;
}

Nodo* obtenerSiguiente(Lista l, ElementoLista elemento){
    Nodo *pNodo, *pNodoSiguiente;
    pNodo = l.cabeza;
    pNodoSiguiente = pNodo->sig;
    while(pNodo != NULL){
        if(pNodo->elemento == elemento)
            break;
        pNodo = pNodo->sig;
        pNodoSiguiente = pNodo->sig;
    }
    return pNodoSiguiente;
}

void eliminarNodo(Lista *pL, ElementoLista elemento){
    Nodo *pNodoEliminar, *pNodoAnterior;
    pNodoEliminar = obtenerNodo(*pL, elemento);
    if(pNodoEliminar != NULL){
        pNodoAnterior = obtenerAnterior(*pL, elemento);
        if(pNodoAnterior == NULL){
            pL->cabeza = pNodoEliminar->sig;
        }
        else
            pNodoAnterior->sig = pNodoEliminar->sig;
        free(pNodoEliminar);
        printf("El nodo ha sido eliminado\n");
    }
    else
        printf("No existe el elemento\n");
}

int obtenerLongitud(Lista l){
    Nodo *pNodo;
    int contador = 0;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        contador++;
        pNodo = pNodo->sig;
    }
    return contador;
}

void destruirLista(Lista *pL){
    Nodo *pNodo, *pNodoAux;
    pNodo = pL->cabeza;
    while(pNodo != NULL){
        pNodoAux = pNodo->sig;
        free(pNodo);
        pNodo = pNodoAux;
    }
    pL->cabeza = NULL;
}
