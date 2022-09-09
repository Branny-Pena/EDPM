
/* 
 * File:   ListaSimEnlazada.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 8, 2022, 4:45 PM
 */

#ifndef LISTASIMENLAZADA_H
#define LISTASIMENLAZADA_H
//Se definen los tipos de datos a usar

typedef struct cliente{
    char tipoCliente;
    int dni;
    char *nombre;
    double saldo;
} Cliente;

typedef Cliente ElementoLista;

typedef struct nodo{
    ElementoLista elemento;
    struct nodo *sgte;
}Nodo;

typedef struct lista{
    //direccion de memoria del primer cliente vip
    Nodo* ClienteV;
    Nodo* cabeza;
} Lista;

#endif /* LISTASIMENLAZADA_H */

