
/* 
 * File:   FuncionesPolleria.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 6:19 PM
 */

#ifndef FUNCIONESPOLLERIA_H
#define FUNCIONESPOLLERIA_H
#include "ColaEmpaquetado.h"
#include "ColaPesado.h"
#include "PilaClasificacion.h"

FILE *abrirArchivo(const char *nombre,const char*modo);

void leerCadena(char *cadena,int tope, FILE *Archivo);

void procesoPesado(ColaPeso *colaPeso, const char *nombArchivo);

ElColaPeso obtenerDatos(int codigo, char* fecha, double peso);

void procesoClasificacion(PilaClas *pilaClas1, PilaClas *pilaClas2, ColaPeso *colaPeso);

void segundoProcesoClasificacion(PilaClas *pilaClas1, PilaClas *pilaClas2);

char* asignarTipo(double peso);

void procesoEmpaquetado(PilaClas *pilaClas2, ColaEmpqt *colaEmpqtTuttus, 
        ColaEmpqt *colaEmpqtMorkys, ColaEmpqt *colaEmpqtDonTico);

ElColaEmpqt casteoDatoPila(ElPilaClas dato);

void crearReporte(ColaEmpqt *colaEmpqtTuttus, ColaEmpqt *colaEmpqtMorkys, 
        ColaEmpqt *colaEmpqtDonTico, const char *nombRep);

void imprimeLineas(FILE *archReporte, char c, int max);

#endif /* FUNCIONESPOLLERIA_H */
