#ifndef GENERALIDADES_H_INCLUDED
#define GENERALIDADES_H_INCLUDED

#include "ListaSucursales.h"
#include "TDA.h"


/**
 Definicion del Tipo de Dato para manejo del Rendimiento
 Atributos:
 * codSuc
 * casaMatriz
 * rendimiento

 Axiomas:
 * codSuc tiene que poseer 4 chars
 * casaMatriz tiene que poseer 4 chars
 * rendimiento > 0
 */

 /*******************************************************************/
/**  Definiciones de Tipos de Datos   */
/**-----------------------------------*/

/** Tipo de Estructura del Rendimiento */
typedef struct
{
    char codSuc[5];
    char casaMatriz[4];
    float rendimiento=0;
} Rendimiento;

/*******************************************************************/
/**  Definicion de Primitivas         */
/**-----------------------------------*/
/**
    PRE : La lista debe haber sido creada.
    POST: La lista queda creada y cargada con los datos del txt ingresado
    lista: Instancia sobre la cual se invoca la primitiva
*/
void cargarDatos(Listaenc* miLista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : La lista debe haber sido creada y debe haber sido cargada con cargarDatos()
    POST: Devuelve una lista ordenada de Nacional mayor a menor en base al campo MontoMensual
    lista: Instancia sobre la cual se invoca la primitiva
*/
void ordenarNacionalFacturacion(Listaenc* miLista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : La lista debe haber sido creada y debe haber sido cargada con cargarDatos()
    POST: Devuelve una lista ordenada de Provincial mayor a menor en base al campo MontoMensual
    lista: Instancia sobre la cual se invoca la primitiva
*/
void ordenarProvinciaFacturacion(Listaenc* miLista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : La lista debe haber sido creada y debe haber sido cargada con cargarDatos()
    POST: Devuelve una lista ordenada de Nacional mayor a menor en base al campo Cantidad de Articulos
    lista: Instancia sobre la cual se invoca la primitiva
*/
void ordenarNacionalCantArt(Listaenc* miLista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : La lista debe haber sido creada y debe haber sido cargada con cargarDatos()
    POST: Devuelve una lista ordenada de Provincial mayor a menor en base al campo Cantidad de Articulos
    lista: Instancia sobre la cual se invoca la primitiva
*/
void ordenarProvinciaCantArt(Listaenc* miLista);
/*------------------------------------------------------------------------------------*/
/**
    PRE : La lista debe haber sido creada y debe haber sido cargada con cargarDatos()
    POST: Devuelve una lista ordenada mayor a menor en base al Rendimiento de las casa matrices
    lista: Instancia sobre la cual se invoca la primitiva
*/
void ordenarPorRendimiento(Listaenc* miLista);
/*------------------------------------------------------------------------------------*/

#endif // GENERALIDADES_H_INCLUDED
