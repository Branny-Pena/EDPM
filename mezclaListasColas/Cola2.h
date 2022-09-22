
/* 
 * File:   Cola2.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 21, 2022, 7:37 PM
 */

#ifndef COLA2_H
#define COLA2_H

typedef struct pizzaCola2{
    double peso;
    char *ingredientes[5];
    char *sabor;
    int hora;
}PizzaCola2;

typedef PizzaCola2 ElementoCola2;

typedef struct nodoCola2{
    ElementoCola2 elemento;
    struct nodoCola2 *sig;
}NodoCola2;

typedef struct cola2{
    NodoCola1 *cabeza;
    NodoCola1 *cola;
}Cola2;


#endif /* COLA2_H */

