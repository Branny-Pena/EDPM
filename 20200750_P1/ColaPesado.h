
/* 
 * File:   ColaPesado.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:31 PM
 */

#ifndef COLAPESADO_H
#define COLAPESADO_H

typedef struct polloPeso{
    int codigo;
    char fecha[10];
    double peso;
}PolloPeso;

typedef PolloPeso ElColaPeso;

typedef struct nodoColaPeso{
    ElColaPeso elemento;
    struct nodoColaPeso *sig;
}NodoColaPeso;

typedef struct colaPeso{
    NodoColaPeso *cabeza;
    NodoColaPeso *cola;
}ColaPeso;

#endif /* COLAPESADO_H */

