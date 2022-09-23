
/* 
 * File:   ColaEmpaquetado.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:45 PM
 */

#ifndef COLAEMPAQUETADO_H
#define COLAEMPAQUETADO_H

typedef struct polloEmpaquetado{
    int codigo;
    char fecha[10];
    double peso;
    char tipo[20];
}PolloEmpaquetado;

typedef PolloEmpaquetado ElColaEmpqt;

typedef struct nodoColaEmpqt{
    ElColaEmpqt elemento;
    struct nodoColaEmpqt *sig;
}NodoColaEmpqt;

typedef struct colaEmpqt{
    NodoColaEmpqt *cabeza;
    NodoColaEmpqt *cola;
}ColaEmpqt;




#endif /* COLAEMPAQUETADO_H */

