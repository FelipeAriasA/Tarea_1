#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

//Estructura para guardar a cada cancion con su titulo, artista, genero, año y lista de reproduccion.
typedef struct{
    char Titulo[30];
    char artista[30];
    char genero[30];
    int anho; 
    char listaReproduccion[9];
}Cancion;

//Estructura para guardar a cada lista de reproduccion en una lista
typedef struct{
    char nombreLista[9];
    List * listaCanciones;
}ListaReproduccion;

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

//Funcion para guardar el contenido leido desde un archivo csv en una lista de canciones
void importarArchivo(List * listaUsuario){
    char csv[50];
    printf("Ingrese el nombre del archivo a importar: ");
    
    getchar;
    scanf("%49[^\n]s",csv);
    FILE *archivo = fopen (csv, "r");

    if(archivo == NULL){

        printf("Archivo no encontrado");

    }else{

    char * linea = (char*)malloc(1024*sizeof(char));
    while(fgets(linea,1023,archivo) != NULL){
        
        Cancion * aux = (Cancion *) malloc (sizeof(Cancion));

        strcpy(aux->Titulo,get_csv_field(linea,0));
        strcpy(aux->artista,get_csv_field(linea,1));
        strcpy(aux->genero,get_csv_field(linea,2));
        aux->anho = atoi(get_csv_field(linea,3));
        strcpy(aux->listaReproduccion,get_csv_field(linea,4));

        ListaReproduccion * aux2 = firstList(listaUsuario);
        while(aux2 != NULL){
            if(strcmp(aux->listaReproduccion,aux2->nombreLista) == 0){
                break;
            }
            aux2 = nextList(listaUsuario);
        }
        if(aux2 == NULL){
            aux2 = (ListaReproduccion * )malloc(sizeof(ListaReproduccion));
            strcpy(aux2->nombreLista,aux->listaReproduccion);
            aux2->listaCanciones = createList();
            pushBack(aux2->listaCanciones,aux);
            pushBack(listaUsuario,aux2);
        }
        else{
            pushBack(aux2->listaCanciones,aux);
        }
    }
    }
    //editar
}

void agregarCancion(List * listaUsuario){
    Cancion * new = (Cancion *) malloc (sizeof(Cancion));
    printf("ingresa el titulo de la cancion\n");
    gets(new->Titulo);
    printf("ingresa el artista de la cancion\n");
    gets(new->artista);
    printf("ingresa el genero de la cancion\n");
    gets(new->genero);
    printf("ingresa el anio de la cancion\n");
    scanf("%d",new->anho);
    printf("ingresa la lista de reproduccion a la que pertenece\n");
    gets(new->listaReproduccion);
    
    ListaReproduccion * aux = firstList(listaUsuario);
    while(aux != NULL){
        if(strcmp(new->listaReproduccion,aux->nombreLista) == 0){
            break;
        }
        aux = nextList(listaUsuario);
    }
    if(aux == NULL){
        aux = (ListaReproduccion * )malloc(sizeof(ListaReproduccion));
        strcpy(aux->nombreLista,new->listaReproduccion);
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
            //editar
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
            //editar
        }
        aux = nextList(listaUsuario);
    }
    if(flag == 0){
        printf("la canción no se encuentra");
    }
}


/*Cancion * a;

for(int i = 0;get_csv_field(a->genero,i) != NULL; i++){

}*/
