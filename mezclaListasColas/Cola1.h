
/* 
 * File:   Cola1.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 21, 2022, 6:55 PM
 */

#ifndef COLA1_H
#define COLA1_H

typedef struct pizzaCola1{
    double peso;
    char ingredientes[20];
}PizzaCola1;

typedef PizzaCola1 ElementoCola1;

typedef struct nodoCola1{
    ElementoCola1 elemento;
    struct nodoCola1 *sig;
}NodoCola1;

typedef struct cola1{
    NodoCola1 *cabeza;
    NodoCola1 *cola;
}Cola1;

#endif /* COLA1_H */

