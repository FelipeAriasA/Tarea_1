#ifndef Funciones_h
#define Funciones_h
#include "List.h"

typedef struct{
    char Titulo[30];
    char artista[30];
    char genero[30];
    int anho; 
    char listaReproduccion[9];
}Cancion;

typedef struct{
    char nombreLista[9];
    List * listaCanciones;
}ListaReproduccion;

void importarArchivo(List* listaUsuario);

void exportarArchivo(List listaUsuario);

void agregarCancion(List* listaUsuario);

void buscarNombre(List* listaUsuario);

void buscarArtista(List* listaUsuario);

void buscarGenero(List* listaUsuario);

void eliminarCancion(List* listaUsuario);

void mostrarListas(List* listaUsuario);

void cancionesLista(List* listaUsuario);

void mostrarCanciones(List* lsitaUsuario);

#endif