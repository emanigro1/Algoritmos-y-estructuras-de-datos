#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  Definicion del Tipo de Dato para manejo de las Sucursales
  Atributos:
 * codigo,
 * provincia,
 * cantidad de articulos,
 * monto mensual,
 * metros cuadrados,
 * casa matriz

 Axiomas:
 * codigo: tiene que poseer 4 chars
 * provincia: tiene que ingresarse una provincia valida
 * cantidad_articulos > 0
 * monto_mensual > 0
 * m_cuadrados > 0
 * casa_matriz: tiene que poseer 4 chars
 */

/*******************************************************************/
/**  Definiciones de Tipos de Datos   */
/**-----------------------------------*/

/** Tipo de Estructura de la Sucursal */
struct EstructuraSucursales
{
    char codigo[5];
    char provincia[20];
    int cantidad_articulos;
    float monto_mensual;
    float m_cuadrados;
    char casa_matriz[5];

    EstructuraSucursales(char codigoInput[5],char provinciaInput[20],int articulosInput, float montoMensualInput, float mCuadradosInput, char casa_matrizInput[5]){
        strcpy(codigo,codigoInput);
        strcpy(provincia,provinciaInput);
        cantidad_articulos = articulosInput;
        monto_mensual = montoMensualInput;
        m_cuadrados = mCuadradosInput;
        strcpy(casa_matriz,casa_matrizInput);
    }
};

/*******************************************************************/
/**  Definicion de Primitivas         */
/**-----------------------------------*/

/**
    PRE : La sucursal no debe haber sido creada.
    POST: La sucursal queda creada y lista para ser usada.
    todos los parametros son ingresados por el usuario.
*/
void nuevoSucursal(EstructuraSucursales *sucursal,char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados, char casaMatriz[5]);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: La Sucursal es eliminada.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void destruirSucursal(EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Devuelve el dato contenido en el campo codigo.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
char *getCodigo (EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: El campo codigo pasa a contener el dato ingresado.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void setCodigo (EstructuraSucursales* sucursal, char NewCodigo[5]);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Devuelve el dato contenido en el campo provincia.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
char *getProvincia(EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: El campo provincia pasa a contener el dato ingresado.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void setProvincia(EstructuraSucursales* sucursal,char NewProvincia[20]);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Devuelve el dato contenido en el campo CantidadArticulos.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
int getCantidadArticulos(EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: El campo CantidadArticulos pasa a contener el dato ingresado.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void setCantidadArticulos(EstructuraSucursales* sucursal, int NewCantidad);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Devuelve el dato contenido en el campo MontoMensual.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
float getMontoMensual(EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: El campo MontoMensual pasa a contener el dato ingresado.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void setMontoMensual (EstructuraSucursales* sucursal, float NewMontoMensual);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Devuelve el dato contenido en el campo MCuadrados.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
float getMCuadrados(EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: El campo MCuadrados pasa a contener el dato ingresado.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void setMCuadrados (EstructuraSucursales* sucursal,float NewMetros);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Devuelve el dato contenido en el campo CasaMatriz.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
char *getCasaMatriz(EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: El campo CasaMatriz pasa a contener el dato ingresado.
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void setCasaMatriz(EstructuraSucursales* sucursal, char NewCasaMatriz[5]);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
    PRE : Sucursal creada con EstructuraSucursal().
    POST: Se pasa a mostrar todos los campos que contiene la Sucursal
    Sucursal : Instancia sobre la cual se invoca la primitiva
*/
void mostrarSucursal (EstructuraSucursales* sucursal);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

#endif // TDA_H_INCLUDED
