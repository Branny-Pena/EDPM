
/* 
 * File:   FuncionesPolleria.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 6:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ColaEmpaquetado.h"
#include "ColaPesado.h"
#include "PilaClasificacion.h"
#include "FuncionesColasPs.h"
#include "FuncionesPilas.h"
#include "FuncionesColasEmpqt.h"
#include "FuncionesPolleria.h"
#include "Abb.h"
#include "Colas.h"
#define MAX_LIN 28

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


void procesoPesado(ColaPeso *colaPeso, const char *nombArchivo){
    FILE* arch = abrirArchivo(nombArchivo, "r");
    ElColaPeso dato;
    int cod;
    char fecha[15];
    double peso;
    while(1){
        fscanf(arch, "%d ", &cod);
        if(feof(arch)) break;
        fscanf(arch, "%s %lf\n", fecha, &peso);
        dato = obtenerDatos(cod, fecha, peso);
        encolarPeso(colaPeso, dato);
    }
}

ElColaPeso obtenerDatos(int codigo, char* fecha, double peso){
    ElColaPeso dato;
    dato.codigo = codigo;
    strcpy(dato.fecha, fecha);
    dato.peso = peso;
    return dato;
}

void procesoClasificacion(PilaClas *pilaClas1, PilaClas *pilaClas2, ColaPeso *colaPeso){
    ElColaPeso datoPeso;
    ElPilaClas datoPila;
    while(!esColaVaciaPeso(*colaPeso)){
        datoPeso = desencolarPeso(colaPeso);
        datoPila.codigo = datoPeso.codigo;
        strcpy(datoPila.fecha, datoPeso.fecha);
        datoPila.peso = datoPeso.peso;
        strcpy(datoPila.tipo, asignarTipo(datoPeso.peso));
        apilar(pilaClas1, datoPila);
    }
    //Se vuelve a apilar ya que la primera vez que desapilo
    //se invierte el orden de la cola y la segunda vez, al desapilar y 
    //meter a la colaEmpqt se recupera el orden inicial de la colaPeso
    segundoProcesoClasificacion(pilaClas1, pilaClas2);
}
void segundoProcesoClasificacion(PilaClas *pilaClas1, PilaClas *pilaClas2){
    ElPilaClas datoPila;
    while(!esPila1Vacia(*pilaClas1)){
        datoPila = desapilar(pilaClas1);
        apilar(pilaClas2, datoPila);
    }
}

char* asignarTipo(double peso){
    if(peso <= 1.00)
        return "Tuttus";
    if(peso > 1.00 && peso <= 1.8)
        return "Morkys";
    if(peso > 1.8)
        return "Don Tico";
}

void procesoEmpaquetado(PilaClas *pilaClas2, ColaEmpqt *colaEmpqtTuttus, 
        ColaEmpqt *colaEmpqtMorkys, ColaEmpqt *colaEmpqtDonTico){
    ElPilaClas dato;
    ElColaEmpqt datoCola;
    while(!esPila1Vacia(*pilaClas2)){
        dato = desapilar(pilaClas2);
        datoCola = casteoDatoPila(dato);
        if(strcmp(datoCola.tipo, "Tuttus") == 0)
            encolarEmpqt(colaEmpqtTuttus, datoCola);
        if(strcmp(datoCola.tipo, "Morkys") == 0)
            encolarEmpqt(colaEmpqtMorkys, datoCola);
        if(strcmp(datoCola.tipo, "Don Tico") == 0)
            encolarEmpqt(colaEmpqtDonTico, datoCola);
    }
}

ElColaEmpqt casteoDatoPila(ElPilaClas dato){
    ElColaEmpqt datoCola;
    datoCola.codigo = dato.codigo;
    strcpy(datoCola.fecha, dato.fecha);
    datoCola.peso = dato.peso;
    strcpy(datoCola.tipo, dato.tipo);
    return datoCola;
}

void crearReporte(ColaEmpqt *colaEmpqtTuttus, ColaEmpqt *colaEmpqtMorkys, 
        ColaEmpqt *colaEmpqtDonTico, const char *nombRep){
    FILE* reporte = abrirArchivo(nombRep, "w");
    fprintf(reporte, "Tipo: Tuttus\n");
    fprintf(reporte, "Codigo%7sFecha%5sPeso\n", " ", " ");
    imprimeLineas(reporte, '=', MAX_LIN);
    mostrarColaEmpqt(reporte, *colaEmpqtTuttus);
    
    fprintf(reporte, "Tipo: Morkys\n");
    fprintf(reporte, "Codigo%7sFecha%5sPeso\n", " ", " ");
    imprimeLineas(reporte, '=', MAX_LIN);
    mostrarColaEmpqt(reporte, *colaEmpqtMorkys);
    
    fprintf(reporte, "Tipo: Don Tico\n");
    fprintf(reporte, "Codigo%7sFecha%5sPeso\n", " ", " ");
    imprimeLineas(reporte, '=', MAX_LIN);
    mostrarColaEmpqt(reporte, *colaEmpqtDonTico);
}

void imprimeLineas(FILE *archReporte, char c, int max){
    for(int i = 0; i < max; i++) fputc(c, archReporte);
    fputc('\n', archReporte);
}

ElementoArbol casteoArbol(ElColaEmpqt a){
    ElementoArbol aux;
    aux.codigo = a.codigo;
    strcpy(aux.fecha, a.fecha);
    aux.peso = a.peso;
    strcpy(aux.tipo, a.tipo);
    return aux;
}

void procesarDatosArbol(ColaEmpqt *colaEmpqtDonTico, ColaEmpqt *colaEmpqtMorkys,
        ColaEmpqt *colaEmpqtTuttus, ArbolBB *arbolPollos){
    ElColaEmpqt dato;
    ElementoArbol datoAbb;
    while(!esColaVaciaEmpqt(*colaEmpqtDonTico) || !esColaVaciaEmpqt(*colaEmpqtMorkys) ||
            !esColaVaciaEmpqt(*colaEmpqtTuttus)){
        if(!esColaVaciaEmpqt(*colaEmpqtMorkys)){
            dato = desencolarEmpqt(colaEmpqtMorkys);
            datoAbb = casteoArbol(dato);
            insertar_abb(arbolPollos, datoAbb);
        }
        if(!esColaVaciaEmpqt(*colaEmpqtDonTico)){
            dato = desencolarEmpqt(colaEmpqtDonTico);
            datoAbb = casteoArbol(dato);
            insertar_abb(arbolPollos, datoAbb);
        }
        if(!esColaVaciaEmpqt(*colaEmpqtTuttus)){
            dato = desencolarEmpqt(colaEmpqtTuttus);
            datoAbb = casteoArbol(dato);
            insertar_abb(arbolPollos, datoAbb);
        }
    }
}