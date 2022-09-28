
/* 
 * File:   PilaClasificacion.h
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 22, 2022, 5:41 PM
 */

#ifndef PILACLASIFICACION_H
#define PILACLASIFICACION_H

typedef struct polloClasificacion{
    int codigo;
    char fecha[10];
    double peso;
    char tipo[20];
}PolloClasificacion;

typedef PolloClasificacion ElPilaClas;

typedef struct nodoPilaClas{
    ElPilaClas elemento;
    struct nodoPilaClas *sig;
}NodoPilaClas;

typedef struct pilaClas{
    NodoPilaClas *cima;
}PilaClas;




#endif /* PILACLASIFICACION_H */

