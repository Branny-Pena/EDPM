
/* 
 * File:   main.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 * Created on September 22, 2022, 5:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ColaEmpaquetado.h"
#include "ColaPesado.h"
#include "PilaClasificacion.h"
#include "FuncionesColasPs.h"
#include "FuncionesPilas.h"
#include "FuncionesColasEmpqt.h"
#include "FuncionesPolleria.h"

int main(int argc, char** argv) {
    ColaPeso colaPeso;
    PilaClas pilaClas1, pilaClas2;
    ColaEmpqt colaEmpqtTuttus, colaEmpqtMorkys, colaEmpqtDonTico;
    construirColaPeso(&colaPeso);
    construirPila(&pilaClas1);
    construirPila(&pilaClas2);
    construirColaEmpqt(&colaEmpqtTuttus);
    construirColaEmpqt(&colaEmpqtMorkys);
    construirColaEmpqt(&colaEmpqtDonTico);
    
    procesoPesado(&colaPeso, "Pollos.txt");
    procesoClasificacion(&pilaClas1, &pilaClas2, &colaPeso);
    procesoEmpaquetado(&pilaClas2, &colaEmpqtTuttus, &colaEmpqtMorkys, &colaEmpqtDonTico);
    
    crearReporte(&colaEmpqtTuttus, &colaEmpqtMorkys, &colaEmpqtDonTico, "Reporte.txt");
    return (EXIT_SUCCESS);
}

