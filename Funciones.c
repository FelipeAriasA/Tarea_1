#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"
#include "Funciones.h"

//Funcion para leer el contenido de un archivo csv
const char *get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }


    return NULL;
}

void agregarCancion(List* listaUsuario, char* nombre, char* artista, char* generos, int ano, char* reproduccion){
    Cancion * new = (Cancion *) malloc (sizeof(Cancion));
    printf("Ingrese los datos de la cancion\n");
    //hola
    gets(new->Titulo);
    gets(new->artista);
    gets(new->genero);
    scanf("%d",new->anho);
    gets(new->reproduccion);
    
    ListaReproduccion * aux = firstList(listaUsuario);
    while(aux != NULL){
        if(strcmp(new->reproduccion,aux->nombreLista) == 0){
            break;
        }
        aux = nextList(listaUsuario);
    }
    if(aux == NULL){
        aux = (ListaReproduccion * )malloc(sizeof(ListaReproduccion));
        strcpy(aux->nombreLista,new->reproduccion);
        aux->listaCanciones = createList();
        pushBack(aux->listaCanciones,new);
        pushBack(listaUsuario,aux);
    }
    else{
        Cancion * aux2 = firstList(aux->listaCanciones);
        while(aux2 != NULL){
            if(strcmp(new->Titulo,aux2->Titulo) == 0){
                break;
            }
            aux2 = nextList(aux->listaCanciones);
        }
        if(aux2 == NULL){
            pushBack(aux->listaCanciones,new);
        }
        else{
            //hola
        }
    }
}

void buscarPorNombre(List * listaUsuario){
    char tituloBuscado[30];
    gets(tituloBuscado);

    int flag = 0;
    ListaReproduccion * aux = firstList(listaUsuario);
    while(aux != NULL){
        Cancion * aux2 = firstList(aux->listaCanciones);
        while(aux2 != NULL){
            if(strcmp(tituloBuscado,aux2->Titulo) == 0){
                flag = 1;
                break;
            }
            aux2 = nextList(aux->listaCanciones);
        }
        if(aux2 != NULL){
            printf("Titulo: %s\n",aux2->Titulo);
            
        }
        aux = nextList(listaUsuario);
    }
    if(flag == 0){
        printf("no esta");
    }
}