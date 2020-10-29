#ifndef LISTAENSUCURSALES_H_INCLUDED
#define LISTAENSUCURSALES_H_INCLUDED
#include "TDA.h"

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


void liberarLista(Listaenc* lista);
bool estaInicializado(Listaenc* lista);
bool estaInicializado(ListaSucursales* sucursal);
bool estaVacia(Listaenc* lista);

ListaSucursales* crearSucur(EstructuraSucursales * sucursal,ListaSucursales* proximo);

void insertarInicio(Listaenc* lista,EstructuraSucursales * sucursal);
void insertar(Listaenc* nacional,EstructuraSucursales * sucursal, int pos);
//int insertarProvincia(Listaenc* provincial,EstructuraSucursales * sucursal, int pos);

void removerInicio(Listaenc* lista, EstructuraSucursales * sucursal);
void remover(Listaenc* lista, EstructuraSucursales * sucursal, int pos);

void obtenerElemento(Listaenc* lista, EstructuraSucursales** sucursal, int pos);
void obtenerTamanio(Listaenc* lista, int* tam);

void imprimir(Listaenc* lista);

#endif // LISTAENSUCURSALES_H_INCLUDED
