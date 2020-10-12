#include <iostream>
#include <conio.h>
#include <string.h>
#include "TDA.h"



using namespace std;

struct EstructuraSucursales;

void crearSucursal (EstructuraSucursales* sucur,char codigo[5], char Provincia[20],int Articulos, float MontoMensual, float mCuadrados, char casa_matriz[5])
{

    //EstructuraSucursales * sucursal = new struct EstructuraSucursales;
    setCodigo(sucur,codigo);
    setProvincia(sucur,Provincia);
    setCantidadArticulos(sucur,Articulos);
    setMontoMensual(sucur,MontoMensual);
    setMCuadrados(sucur,mCuadrados);
    setCasaMatriz(sucur,casa_matriz);
}

/*EstructuraSucursales* crearSucursal(){

    //EstructuraSucursales* sucursal = new EstructuraSucursales("0034","Buenos Aires",50, 47.53, 18.5, "0012");

    char auxCaracter[20]= "";
    int auxNumerico = 0;

    fflush(stdin);
    cout<<"Ingrese el codigo de su empresa: "<<endl;
    gets(auxCaracter);
    strcpy(sucursal->codigo,auxCaracter);

    fflush(stdin);
    cout<<"Ingrese la provincia: "<<endl;
    gets(auxCaracter);
    strcpy(sucursal->provincia,auxCaracter);

    cout<<"ingrese la cantidad de articulos: "<<endl;
    cin>>sucursal->cantidad_articulos;

    cout<<"ingrese el monto mensual: "<<endl;
    cin>>sucursal->monto_mensual;

    cout<<"ingrese los metros cuadrados: "<<endl;
    cin>>sucursal->m_cuadrados;

    cout<<"ingrese la casa matriz: "<<endl;
    cin>>sucursal->casa_matriz;

    return sucursal;

}*/

void nuevoSucursal(EstructuraSucursales *sucur,char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados, char casaMatriz[5])
{
    strcpy(sucur->codigo,codigo);
    strcpy(sucur->provincia,provincia);
    sucur->cantidad_articulos = articulos;
    sucur->monto_mensual = montoMensual;
    sucur->m_cuadrados = mCuadrados;
    strcpy(sucur->casa_matriz,casaMatriz);
}

void destruirSucursal(EstructuraSucursales* sucur)
{
    delete sucur;
}

char *getCodigo (EstructuraSucursales* sucur)
{
   return sucur->codigo;
}
void setCodigo (EstructuraSucursales* sucur, char NewCodigo[5])
{
    strcpy(sucur->codigo,NewCodigo);
}

char *getProvincia (EstructuraSucursales* sucur)
{
    return sucur->provincia;
}
void setProvincia(EstructuraSucursales* sucur,char NewProvincia[20])
{
    strcpy(sucur->provincia,NewProvincia);
}

int getCantidadArticulos(EstructuraSucursales* sucur)
{
    return sucur->cantidad_articulos;
}
void setCantidadArticulos(EstructuraSucursales* sucur, int NewCantidad)
{
    sucur->cantidad_articulos=NewCantidad;
}

float getMontoMensual(EstructuraSucursales* sucur)
{
    return sucur->monto_mensual;
}
void setMontoMensual (EstructuraSucursales* sucur, float NewMontoMensual)
{
    sucur->monto_mensual=NewMontoMensual;
}

float getMCuadrados(EstructuraSucursales* sucur)
{
    return sucur->m_cuadrados;
}
void setMCuadrados (EstructuraSucursales* sucur,float NewMetros)
{
    sucur->m_cuadrados=NewMetros;
}

char *getCasaMatriz(EstructuraSucursales* sucur)
{
    return sucur->casa_matriz;
}
void setCasaMatriz(EstructuraSucursales* sucur, char NewCasaMatriz[5])
{
    strcpy(sucur->casa_matriz,NewCasaMatriz);
}

void mostrarSucursal (EstructuraSucursales* sucur)
{
    cout<<"\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";
    cout<<"Codigo Sucursal: "<<sucur->codigo<<endl;
    cout<<"Provincia: "<<sucur->provincia<<endl;
    cout<<"Cantidad de Articulos Vendidos: "<<sucur->cantidad_articulos<<endl;
    cout<<"Monto Mensual: "<<sucur->monto_mensual<<endl;
    cout<<"M2 del Local: "<<sucur->m_cuadrados<<endl;
    cout<<"Casa Matriz: "<<sucur->casa_matriz<<endl;
    cout<<"\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";
}


