#include <iostream>
#include <conio.h>
#include <string.h>
#include "TDA.h"

using namespace std;

struct EstructuraSucursales;

/*******************************************************************/
/**  Implementacion de Primitivas      */
/**-----------------------------------*/


void nuevoSucursal(EstructuraSucursales *sucursal,char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados, char casaMatriz[5])
{
    strcpy(sucursal->codigo,codigo);
    strcpy(sucursal->provincia,provincia);
    sucursal->cantidad_articulos = articulos;
    sucursal->monto_mensual = montoMensual;
    sucursal->m_cuadrados = mCuadrados;
    strcpy(sucursal->casa_matriz,casaMatriz);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void destruirSucursal(EstructuraSucursales* sucursal)
{
    delete sucursal;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
char *getCodigo (EstructuraSucursales* sucursal)
{
   return sucursal->codigo;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setCodigo (EstructuraSucursales* sucursal, char NewCodigo[5])
{
    strcpy(sucursal->codigo,NewCodigo);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
char *getProvincia (EstructuraSucursales* sucursal)
{
    return sucursal->provincia;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setProvincia(EstructuraSucursales* sucursal,char NewProvincia[20])
{
    strcpy(sucursal->provincia,NewProvincia);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
int getCantidadArticulos(EstructuraSucursales* sucursal)
{
    return sucursal->cantidad_articulos;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setCantidadArticulos(EstructuraSucursales* sucursal, int NewCantidad)
{
    sucursal->cantidad_articulos=NewCantidad;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
float getMontoMensual(EstructuraSucursales* sucursal)
{
    return sucursal->monto_mensual;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setMontoMensual (EstructuraSucursales* sucursal, float NewMontoMensual)
{
    sucursal->monto_mensual=NewMontoMensual;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
float getMCuadrados(EstructuraSucursales* sucursal)
{
    return sucursal->m_cuadrados;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setMCuadrados (EstructuraSucursales* sucursal,float NewMetros)
{
    sucursal->m_cuadrados=NewMetros;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
char *getCasaMatriz(EstructuraSucursales* sucursal)
{
    return sucursal->casa_matriz;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setCasaMatriz(EstructuraSucursales* sucursal, char NewCasaMatriz[5])
{
    strcpy(sucursal->casa_matriz,NewCasaMatriz);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void mostrarSucursal (EstructuraSucursales* sucursal)
{
    cout<<"\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";
    cout<<"Codigo sucursal: "<<sucursal->codigo<<endl;
    cout<<"Provincia: "<<sucursal->provincia<<endl;
    cout<<"Cantidad de Articulos Vendidos: "<<sucursal->cantidad_articulos<<endl;
    cout<<"Monto Mensual: "<<sucursal->monto_mensual<<endl;
    cout<<"M2 del Local: "<<sucursal->m_cuadrados<<endl;
    cout<<"Casa Matriz: "<<sucursal->casa_matriz<<endl;
    cout<<"\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

