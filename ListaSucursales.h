#ifndef LISTAENSUCURSALES_H_INCLUDED
#define LISTAENSUCURSALES_H_INCLUDED
#include "TDA.h"

#define TRUE 1
#define FALSE 0

#define OK 1
#define ESTRUCTURA_NO_INICIALIZADA -1
#define ESTRUCTURA_VACIA -2
#define INDICE_INVALIDO -3
#define PARAMETRO_INVALIDO -4

struct ListaSucursales
{
    struct EstructuraSucursales * sucursales; ///Esto funciona asi debido a que apunta al tipo de estructura que deseo conseguir el dato
    ListaSucursales * siguiente;
};

struct Listaenc{
    ListaSucursales * inicio;
    int tam;
};

//Añadir a la lista
Listaenc* crearLista();

int liberarLista(Listaenc* lista);
int estaVacia(Listaenc* lista);

int insertarInicio(Listaenc* lista,EstructuraSucursales * sucursal);
int insertar(Listaenc* lista,EstructuraSucursales * sucursal, int pos);

int removerInicio(Listaenc* lista, EstructuraSucursales * sucursal);
int remover(Listaenc* lista, EstructuraSucursales * sucursal, int pos);

int obtenerTamanio(Listaenc* lista, int* tam);
int obtenerElemento(Listaenc* lista, EstructuraSucursales** sucursal, int pos);

void imprimir(Listaenc* lista);

#endif // LISTAENSUCURSALES_H_INCLUDED
