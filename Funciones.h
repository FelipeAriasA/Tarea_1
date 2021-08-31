#ifndef Funciones_h
#define Funciones_h
#include "List.h"

void importarArchivo(List* listaUsuario, char* archivo);

void exportarArchivo(List listaUsuario, char* archivo);

void agregarCancion(List* listaUsuario, char* nombre, char* artista, char* generos, int ano, char* ListaReproduccion);

void buscarNombre(List* listaUsuario, char* nombre);

void buscarArtista(List* listaUsuario, char* artista);

void buscarGenero(List* listaUsuario, char* genero);

void eliminarCancion(List* listaUsuario, char* nombre);

void mostrarListas(List* listaUsuario);

void cancionesLista(List* listaUsuario, char* listaReproduccion);

void mostrarCanciones(List* lsitaUsuario);

#endif