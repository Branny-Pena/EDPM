
/* 
 * File:   Pila1.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 21, 2022, 7:01 PM
 */

#ifndef PILA1_H
#define PILA1_H

typedef struct pizzaPila1{
    double peso;
    char ingredientes[20];
    char sabor[20];
}PizzaPila1;

typedef PizzaPila1 ElementoPila1;

typedef struct nodoPila1{
    ElementoPila1 elemento;
    struct nodoPila1 *sig;
}NodoPila1;

typedef struct pila1{
    NodoPila1 *cima;
}Pila1;

#endif /* PILA1_H */

