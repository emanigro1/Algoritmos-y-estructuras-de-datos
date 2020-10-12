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
int insertarFin(Listaenc* lista, EstructuraSucursales * sucursal);

int removerInicio(Listaenc* lista, EstructuraSucursales * sucursal);
int remover(Listaenc* lista, EstructuraSucursales * sucursal, int pos);
int removerFin(Listaenc* lista, EstructuraSucursales * sucursal);

int obtenerTamanio(Listaenc* lista, int* tam);
int obtenerElemento(Listaenc* lista, EstructuraSucursales** sucursal, int pos);

void imprimir(Listaenc* lista);

ListaSucursales* crearSucur(EstructuraSucursales * sucursal,ListaSucursales* proximo);
void agregarLista(ListaSucursales *&lista,EstructuraSucursales * sucursales);  ///Los parametros dicen que necesito un puntero a una lista y otro a una estructura
void mostrarLista(ListaSucursales *lista);




#endif // LISTAENSUCURSALES_H_INCLUDED
