
/* 
 * File:   FuncionesListas.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 8, 2022, 4:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSimEnlazada.h"
#include "FuncionesListas.h"

void crearLista(Lista *pL){
    pL->cabeza = NULL;
    pL->ClienteV = NULL;
}

int esListaVacia(Lista l){ 
    return l.cabeza == NULL;
}

Nodo* crearNuevoNodo(ElementoLista elemento, Nodo* sgte){
    Nodo* pNodo;
    pNodo = (Nodo*)malloc(sizeof(Nodo));
    pNodo->elemento = elemento;
    pNodo->sgte = sgte;
    return pNodo;
}

void insertarComienzo(Lista *pL, ElementoLista elemento){
    Nodo* pNodo;
    pNodo = crearNuevoNodo(elemento, pL->cabeza);
    pL->cabeza = pNodo;
}

void mostrarLista(Lista l){
    Nodo *pNodo;
    if(esListaVacia(l))
        printf("La lista esta vacia\n");
    else{
        pNodo = l.cabeza;
        while(pNodo != NULL){
            printf("%15d %50s %10.2lf %10c\n", pNodo->elemento.dni, pNodo->elemento.nombre
                    , pNodo->elemento.saldo, pNodo->elemento.tipoCliente);
            pNodo = pNodo->sgte;
        }
        printf("\n");
    }
}

void insertarClienteOrden(Lista *pL, ElementoLista elemento){
    Nodo *pNodo;
    //Si la lista esta vacia se inserta el valor al comienzo y se asigna el valor
    //de la posicion donde comienzan los clientes vip para ser usado como tope
    if(esListaVacia(*pL)){
        insertarComienzo(pL, elemento);
        if(elemento.tipoCliente == 'V'){
            pL->ClienteV = pL->cabeza;
        }
    }
    else{
        if(elemento.tipoCliente == 'V'){
            pNodo = pL->ClienteV;
            insertarOrdenadoVip(pL, elemento, pNodo);
        }
        else{
            pNodo = pL->cabeza;
            insertarOrdenadoNormal(pL, elemento, pL->ClienteV);
        }
    }
}
//Insertar ordenado para los clientes vip
void insertarOrdenadoVip(Lista *lista, ElementoLista elemento, Nodo *pNodo){
    Nodo *pNuevoNodo, *pNodoAnterior;
    pNuevoNodo = crearNuevoNodo(elemento, NULL);
    pNodoAnterior = obtenerAnteriorV(lista, elemento);
    
    pNuevoNodo->sgte = pNodoAnterior->sgte;
    pNodoAnterior->sgte = pNuevoNodo;
}

Nodo* obtenerAnteriorV(Lista *lista, ElementoLista elemento){
    Nodo* pNodoAnterior, *pNodo;
    pNodo = lista->cabeza;
    pNodoAnterior = NULL;
    while(pNodo != NULL){
        pNodoAnterior = pNodo;
        pNodo = pNodo->sgte;
    }
    pNodo = lista->ClienteV;
    while(pNodo != NULL && pNodo->elemento.saldo > elemento.saldo){
        pNodoAnterior = pNodo;
        pNodo = pNodo->sgte;
    }
    return pNodoAnterior;
}

//Insertar ordenado para los clientes normales
void insertarOrdenadoNormal(Lista *lista, ElementoLista elemento, Nodo* fin){
    Nodo *pNuevoNodo, *pNodoAnterior;
    pNuevoNodo = crearNuevoNodo(elemento, NULL);
    pNodoAnterior = obtenerAnteriorC(lista->cabeza, elemento, lista->ClienteV);
    if(pNodoAnterior == NULL){
        pNuevoNodo->sgte = lista->cabeza;
        lista->cabeza = pNuevoNodo;
    }
    else{
        pNuevoNodo->sgte = pNodoAnterior->sgte;
        pNodoAnterior->sgte = pNuevoNodo;
    }
}

Nodo* obtenerAnteriorC(Nodo* inicio, ElementoLista elemento, Nodo* fin){
    Nodo* pNodoAnterior = NULL;
    Nodo* pNodo = inicio;
    while(pNodo != fin && pNodo->elemento.saldo > elemento.saldo){
        pNodoAnterior = pNodo;
        pNodo = pNodo->sgte;
    }
    return pNodoAnterior;
}

Nodo* acceso(Lista lista, ElementoLista elemento){
    Nodo* pNodo;
    if(elemento.tipoCliente == 'V')
        pNodo = buscarElemento(lista.cabeza, lista.ClienteV, elemento);
    else
        pNodo = buscarElemento(lista.ClienteV, NULL, elemento);
    return pNodo;
}

Nodo* buscarElemento(Nodo* inicio, Nodo* fin, ElementoLista elemento){
    Nodo *pNodo;
    pNodo = inicio;
    while(pNodo != fin){
        if(pNodo->elemento.dni == elemento.dni){
            return pNodo;
        }
        pNodo = pNodo->sgte;
    }
    return NULL;
}

void actualizacion(Lista *pL, ElementoLista elemento){
    Nodo* pNodo;
    pNodo = acceso(*pL, elemento);
    eliminarNodo(pL, elemento);
    insertarClienteOrden(pL, elemento);
    //pNodo->elemento = elemento;
}

void eliminarNodo(Lista *pL, ElementoLista elemento){
    Nodo *pNodoEliminar, *pNodoAnterior;
    pNodoEliminar = obtenerNodo(*pL, elemento);
    if(pNodoEliminar != NULL){
        pNodoAnterior = buscarAnterior(pL, elemento);
        if(pNodoAnterior == NULL){
            pL->cabeza = pNodoEliminar->sgte;
        }
        else
            pNodoAnterior->sgte = pNodoEliminar->sgte;
        free(pNodoEliminar);
    }
}

Nodo* obtenerNodo(Lista l, ElementoLista elemento){
    Nodo *pNodo;
    pNodo = l.cabeza;
    while(pNodo != NULL){
        if(pNodo->elemento.dni == elemento.dni)
            break;
        pNodo = pNodo->sgte;
    }
    return pNodo;
}

Nodo* buscarAnterior(Lista *pL, ElementoLista elemento){
    Nodo *pNodo, *pNodoAnterior;
    pNodo = pL->cabeza;
    pNodoAnterior = NULL;
    while(pNodo != NULL){
        if(pNodo->elemento.dni == elemento.dni)
            break;
        pNodoAnterior = pNodo;
        pNodo = pNodo->sgte;
    }
    return pNodoAnterior;
}

void cargarElementos(Cliente *elemento1, Cliente *elemento2, Cliente *elemento3,
        Cliente *elemento4, Cliente *elemento5, Cliente *elemento6, Lista l){
    elemento1->dni = 1234567;
    elemento1->nombre = (char*)malloc(sizeof(char)*51);
    strcpy(elemento1->nombre, "Pedro perez");
    elemento1->saldo = 1231.43;
    elemento1->tipoCliente = 'C';
    
    elemento2->dni = 1234577;
    elemento2->nombre = (char*)malloc(sizeof(char)*51);
    strcpy(elemento2->nombre, "PeASDro perez");
    elemento2->saldo = 125.43;
    elemento2->tipoCliente = 'V';
    
    elemento3->dni = 1236667;
    elemento3->nombre = (char*)malloc(sizeof(char)*51);
    strcpy(elemento3->nombre, "PeG perez");
    elemento3->saldo = 91341.43;
    elemento3->tipoCliente = 'C';
    
    elemento4->dni = 127867;
    elemento4->nombre = (char*)malloc(sizeof(char)*51);
    strcpy(elemento4->nombre, "PRTYro perez");
    elemento4->saldo = 25767.43;
    elemento4->tipoCliente = 'C';
    
    elemento5->dni = 11440567;
    elemento5->nombre = (char*)malloc(sizeof(char)*51);
    strcpy(elemento5->nombre, "WTT perez");
    elemento5->saldo = 2555.43;
    elemento5->tipoCliente = 'C';
    
    elemento6->dni = 5267778;
    elemento6->nombre = (char*)malloc(sizeof(char)*51);
    strcpy(elemento6->nombre, "WJWH perez");
    elemento6->saldo = 456.43;
    elemento6->tipoCliente = 'V';
}

void actualizarElementos(Cliente *elemento1, Cliente *elemento2, Cliente *elemento3,
        Cliente *elemento4, Cliente *elemento5, Cliente *elemento6, Lista l){
    elemento6->saldo = 123143.4;
    elemento4->saldo = 9898.04;
}