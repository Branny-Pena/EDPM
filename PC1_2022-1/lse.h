
/* 
 * File:   lse.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 6, 2022, 10:15 AM
 */

#ifndef LSE_H
#define LSE_H

typedef struct cancion{
    char* titulo;
    char* autor;
    int duracionM;
    int duracionS;
} Cancion;

typedef Cancion ElementoLista;

typedef struct nodo{
    ElementoLista elemento;
    struct nodo *sgte;
} Nodo;

typedef struct lista{
    int longitud;
    Nodo *cabeza;
    char *nombre;
} Lista;

void crearLista(Lista *lista);

int esListaVacia(Lista lista);

Nodo* crearNuevoNodo(ElementoLista elemento, Nodo *sgte);

void insertarComienzo(Lista *lista, ElementoLista elemento);

void mostrarLista(Lista lista);

void destruirLista(Lista *lista);

void insertar_en_orden(Lista *tad, ElementoLista elemento);

Nodo* obtenerNodoAnterior(Lista lista, ElementoLista elemento);

#endif /* LSE_H */

