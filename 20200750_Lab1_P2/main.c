
/* 
 * File:   main.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 * Created on September 8, 2022, 11:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListaSimEnlazada.h"
#include "FuncionesListas.h" 
#include "Funciones.h"

int main(int argc, char** argv) {
    Lista lista;
    crearLista(&lista);
    leerClientes("Clientes.txt", &lista);
    realizarModificaciones("Modificaciones.txt", &lista);
    mostrarReporte("Reporte.txt", lista);
    return (EXIT_SUCCESS);
}

