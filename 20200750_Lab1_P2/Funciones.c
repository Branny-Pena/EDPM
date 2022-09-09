
/* 
 * File:   Funciones.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 8, 2022, 11:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ListaSimEnlazada.h"
#include "FuncionesListas.h"

FILE *abrirArchivo(const char *nombre,const char*modo){
    FILE *arch;
    arch=fopen(nombre,modo);
    if (arch==NULL){
        printf("Error: El archivo %s no se puede abrir\n",nombre);
        exit(1);
    }
    return arch;
}

void leerCadena(char *cadena,int tope, FILE *Archivo){
    int numcar;
    fgets(cadena,tope,Archivo);
    numcar=strlen(cadena);
    if (cadena[numcar-1]=='\n') cadena[numcar-1]=0;
}

void leerClientes(char* nombreArch,Lista* lista){
    FILE* archClientes = abrirArchivo(nombreArch, "r");
    ElementoLista cliente;
    int dni;
    char nombre[50], tipoCliente;
    double saldo;
    char buffer[100];
    while(1){
        fscanf(archClientes, "%c", &tipoCliente);
        if(feof(archClientes)) break;
        fscanf(archClientes, "%d %s %lf\n", &dni, nombre, &saldo);
        cliente = obtenerCliente(tipoCliente, dni, nombre, saldo);
        insertarClienteOrden(lista, cliente);
    }
    //mostrar correcta lectura, para probar
    mostrarLista(*lista);
}

Cliente obtenerCliente(char tipo, int dni, char* nombre, double saldo){
    Cliente cliente;
    cliente.dni = dni;
    cliente.saldo = saldo;
    cliente.tipoCliente = tipo;
    cliente.nombre = (char*)malloc(sizeof(malloc)*51);
    strcpy(cliente.nombre, nombre);
    return cliente;
}

void realizarModificaciones(char* nombreArch, Lista* lista){
    FILE* archModificaciones = abrirArchivo(nombreArch, "r");
    ElementoLista cliente;
    int dni;
    char nombre[50], tipoModificacion, tipoCliente;
    double saldo;
    char buffer[100];
    while(1){
        fscanf(archModificaciones, "%c ", &tipoModificacion);
        if(feof(archModificaciones)) break;
        if(tipoModificacion == 'I'){
            fscanf(archModificaciones, "%c %d %s %lf\n", &tipoCliente, &dni, nombre, &saldo);
            cliente = obtenerCliente(tipoCliente, dni, nombre, saldo);
            insertarClienteOrden(lista, cliente);
        }
        else if(tipoModificacion == 'E'){
            fscanf(archModificaciones, "%d\n", &dni);
            cliente.dni = dni;
            eliminarNodo(lista, cliente);
        }
        else{
            fscanf(archModificaciones, "%d %lf\n", &dni, &saldo);
            cliente.dni = dni;
            cliente.saldo = saldo;
            actualizacion(lista, cliente);
        }
    }
    mostrarLista(*lista);
}

void mostrarReporte(char* nombreArch, Lista lista){
    FILE* archReporte = abrirArchivo(nombreArch, "w");
    fprintf(archReporte, "DNI%15sNombre del Cliente%32sSaldo%10sTipo de Cliente\n", 
            " ", " ", " ");
    for(int i = 0; i < 100; i++) fputc('=', archReporte);
    fputc('\n', archReporte);
    Nodo *pNodo;
    if(esListaVacia(lista))
        fprintf(archReporte, "La lista esta vacia\n");
    else{
        pNodo = lista.cabeza;
        while(pNodo != NULL){
            fprintf(archReporte, "%-15d %-50s %-10.2lf %12c\n", pNodo->elemento.dni, pNodo->elemento.nombre
                    , pNodo->elemento.saldo, pNodo->elemento.tipoCliente);
            pNodo = pNodo->sgte;
        }
        fprintf(archReporte, "\n");
    }
}