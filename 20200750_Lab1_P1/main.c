
/* 
 * File:   main.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 * Created on September 8, 2022, 4:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesListas.h"

int main(int argc, char** argv) {
    Lista l;
    crearLista(&l);
    mostrarLista(l);
    Cliente elemento1, elemento2, elemento3, elemento4, elemento5, elemento6;
    
    //cargar datos de prueba, el ultimo es para la actualizacion
    cargarElementos(&elemento1, &elemento2, &elemento3, &elemento4, &elemento5, 
            &elemento6, l);
    
    insertarClienteOrden(&l, elemento1);
    mostrarLista(l);
   
    insertarClienteOrden(&l, elemento2);
    mostrarLista(l);
    
    insertarClienteOrden(&l, elemento3);
    mostrarLista(l);
    
    insertarClienteOrden(&l, elemento4);
    mostrarLista(l);
    
    insertarClienteOrden(&l, elemento5);
    mostrarLista(l);

    insertarClienteOrden(&l, elemento6);
    mostrarLista(l);
    
    actualizarElementos(&elemento1, &elemento2, &elemento3, &elemento4, &elemento5, 
            &elemento6, l);
    actualizacion(&l, elemento6);
    mostrarLista(l);

    actualizacion(&l, elemento4);
    mostrarLista(l);
    return (EXIT_SUCCESS);
}

