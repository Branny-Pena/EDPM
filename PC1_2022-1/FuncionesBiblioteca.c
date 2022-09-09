
/* 
 * File:   FuncionesBiblioteca.c
 * Author: Adalberto Branny Peña Alejandro
 *         20200750
 *
 * Created on September 6, 2022, 12:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesBiblioteca.h"
#include "lse.h"

FILE *abrirArchivo(const char *nombre,const char*modo){
    FILE *arch;
    arch=fopen(nombre,modo);
    if (arch==NULL){
        printf("Error: El archivo %s no se puede abrir\n",nombre);
        exit(1);
    }
    return arch;
}

void leerCadena(char *cadena,int tope, FILE *Archivo){
    int numcar;
    fgets(cadena,tope,Archivo);
    numcar=strlen(cadena);
    if (cadena[numcar-1]=='\n') cadena[numcar-1]=0;
}

char *leeCadenaExacta(FILE *arch){
    char buffer[500];
    char *cadena;
    int longitud;
    leerCadena(buffer,500,arch);
    if (feof(arch)) return NULL;
    longitud=strlen(buffer);
    cadena=(char *)malloc(sizeof(char)*(longitud+1));
    strcpy(cadena,buffer);
    return cadena;
}

void sacaPalabras(char *cadena,char **palabras,int *num_pal,char carSep){
    int i=0;
    char buffer[100];
    int ncar=0;
    char *ptr;
    *num_pal=0;
    while(1){
        while (cadena[i]==carSep)i++;
        if (cadena[i]==0) break;
        ncar=0;
        while(cadena[i]!=carSep && cadena[i]!=0){
            buffer[ncar]=cadena[i];
            ncar++;
            i++;        
        }
        buffer[ncar]=0;
        ptr=(char *)malloc(sizeof(char)*(ncar+1));
        strcpy(ptr,buffer);
        palabras[*num_pal]=ptr;
        (*num_pal)++;
    }
}

void leerBiblioteca(){
    FILE* archBiblio = abrirArchivo("biblioteca.txt", "r");
    Lista pLista;
    int cantCategorias, cantCanciones;
    char *nombre;
    int duracionM, duracionS;
    ElementoLista cancion;
    fscanf(archBiblio, "%d", &cantCategorias);
    for(int i = 0; i < cantCategorias; i++){
        crearLista(&pLista);
        fscanf(archBiblio, "%d\n", &cantCanciones);
        nombre = leeCadenaExacta(archBiblio);
        pLista.longitud = 0;
        pLista.nombre = (char*)malloc(sizeof(char)*99);
        strcpy(pLista.nombre, nombre);
        free(nombre);
        for(int j = 0; j < cantCanciones; j++){
            cancion = obtenerCancion(archBiblio);
            //insertarComienzo(&pLista, cancion);
            insertar_en_orden(&pLista, cancion);
        }
        mostrarLista(pLista);
        destruirLista(&pLista);
    }
    fclose(archBiblio);
}

ElementoLista obtenerCancion(FILE* archBiblio){
    ElementoLista cancion;
    char *titulo, *autor;
    int duracionM, duracionS;
    titulo = leeCadenaExacta(archBiblio);
    autor = leeCadenaExacta(archBiblio);
    fscanf(archBiblio, "%d:%d\n", &duracionM, &duracionS);
    cancion.autor = (char*)malloc(sizeof(char)*51);
    strcpy(cancion.autor, autor);
    free(autor);
    cancion.titulo = (char*)malloc(sizeof(char)*51);
    strcpy(cancion.titulo, titulo);
    free(titulo);
    cancion.duracionM = duracionM;
    cancion.duracionS = duracionS;
    return cancion;
}

