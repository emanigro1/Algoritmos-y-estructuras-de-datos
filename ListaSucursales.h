#ifndef LISTAENSUCURSALES_H_INCLUDED
#define LISTAENSUCURSALES_H_INCLUDED
#include "TDA.h"

/**
 Definicion del Tipo de Dato para manejo de Listas Sucursales:
 Atributos:
 * EstructuraSucursales *sucursales,
 * ListaSucursales *siguiente.

 Axiomas:
 * Sucursal != NULL
 * siguiente = NULL
 */

/**
 Definicion del Tipo de Dato para manejo de Listas Sucursales:
 Atributos:
 * ListaSucursales *inicio
 * tamanio

 Axiomas:
 * ListaSucursales *inicio != NULL
 * tamanio > -1
 */


/** Tipo de Estructura Lista de Sucursales */
struct ListaSucursales
{
    struct EstructuraSucursales * sucursales;
    ListaSucursales * siguiente;
};
/** Tipo de Estructura Lista Encadenada */
struct Listaenc{
    ListaSucursales * inicio;
    int tam;
};

/*******************************************************************/
/**  Definicion de Primitivas         */
/**-----------------------------------*/
/**
    PRE : La lista no debe haber sido creada.
    POST: La lista queda creada y lista para ser usada.
    lista: Instancia sobre la cual se invoca la primitiva
*/
Listaenc* crearLista();
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista()
    POST: La lista es vaciada si posee contenidos
    lista: Instancia sobre la cual se invoca la primitiva
*/
void liberarLista(Listaenc* lista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista() y datos cargados
    POST: Da verdadero o falso dependiendo de la inicializacion de esta
    lista: Instancia sobre la cual se invoca la primitiva
*/
bool estaInicializado(Listaenc* lista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista() y datos cargados
    POST: Da verdadero o falso dependiendo de la inicializacion de esta
    sucursal: Instancia sobre la cual se invoca la primitiva
*/
bool estaInicializado(ListaSucursales* sucursal);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista()
    POST:  Da verdadero o falso dependiendo de si la lista posee elementos o no
    lista: Instancia sobre la cual se invoca la primitiva
*/
bool estaVacia(Listaenc* lista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista()
    POST: Devuelve una Nueva Sucursal del tipo ListaSucursal
    sucursal: Instancia sobre la cual se invoca la primitiva
    proximo: Puntero que apunta hacia la proxima locacion la cual seria nula
*/
ListaSucursales* crearSucur(EstructuraSucursales * sucursal,ListaSucursales* proximo);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista()
    POST: Devuelve una lista con un elemento insertado en el principio.
    lista: Instancia sobre la cual se invoca la primitiva
    proximo: Puntero que apunta hacia la proxima locacion la cual seria nula
*/
void insertarInicio(Listaenc* lista,EstructuraSucursales * sucursal);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tiene que tener una lista inicializada con crearLista() y una posicion elegida
    POST: Devuelve una lista con un elemento insertado en la posicion deseada
    sucursal: Instancia sobre la cual se invoca la primitiva
    nacional: Instancia sobre la cual se invoca la primitiva
*/
void insertar(Listaenc* nacional,EstructuraSucursales * sucursal, int pos);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Debe poseer una Lista creada con crearLista() y datos ingresados con insertar()
    POST: Devuelve la lista con el elemento en la posicion inicial eliminado
    lista: Instancia sobre la cual se invoca la primitiva
    sucursal: Instancia sobre la cual se invoca la primitiva
*/
void removerInicio(Listaenc* lista, EstructuraSucursales * sucursal);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Debe poseer una Lista creada con crearLista() y datos ingresados con insertar()
    POST: Devuelve la lista con el elemento en aquella posicion eliminado
    lista: Instancia sobre la cual se invoca la primitiva
    sucursal: Instancia sobre la cual se invoca la primitiva
*/
void remover(Listaenc* lista, EstructuraSucursales * sucursal, int pos);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Debe poseer una Lista creada con crearLista() y datos ingresados
    POST: Devuelve el elemento que se encuentra en esa posicion
    lista: Instancia sobre la cual se invoca la primitiva
*/
void obtenerElemento(Listaenc* lista, EstructuraSucursales** sucursal, int pos);
/*------------------------------------------------------------------------------------*/
/**
    PRE : Tener una lista creada con crearLista();
    POST: Devuelve el dato del campo tamanio de la lista
    lista: Instancia sobre la cual se invoca la primitiva
*/
void obtenerTamanio(Listaenc* lista, int* tam);
/*------------------------------------------------------------------------------------*/
/**
    PRE : La Lista creada con crearLista() y con elementos insertados con insertar()
    POST: Se pasa a mostrar todos los nodos que contiene la Lista
    lista: Instancia sobre la cual se invoca la primitiva
*/
void imprimir(Listaenc* lista);
/*------------------------------------------------------------------------------------*/
#endif // LISTAENSUCURSALES_H_INCLUDED
