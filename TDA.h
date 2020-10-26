#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EstructuraSucursales
{
    char codigo[5];
    char provincia[20];
    int cantidad_articulos;
    float monto_mensual;
    float m_cuadrados;
    int casa_matriz;

    EstructuraSucursales(char codigoInput[5],char provinciaInput[20],int articulosInput, float montoMensualInput, float mCuadradosInput, int casa_matrizInput){
        strcpy(codigo,codigoInput);
        strcpy(provincia,provinciaInput);
        cantidad_articulos = articulosInput;
        monto_mensual = montoMensualInput;
        m_cuadrados = mCuadradosInput;
        casa_matriz=casa_matrizInput;
    }
};

void nuevoSucursal(EstructuraSucursales *sucur,char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados,int casa_matriz);

void destruirSucursal(EstructuraSucursales* sucur);

char *getCodigo (EstructuraSucursales* sucur);
void setCodigo (EstructuraSucursales* sucur, char NewCodigo[5]);

char *getProvincia(EstructuraSucursales* sucur);
void setProvincia(EstructuraSucursales* sucur,char NewProvincia[20]);

int getCantidadArticulos(EstructuraSucursales* sucur);
void setCantidadArticulos(EstructuraSucursales* sucur, int NewCantidad);

float getMontoMensual(EstructuraSucursales* sucur);
void setMontoMensual (EstructuraSucursales* sucur, float NewMontoMensual);

float getMCuadrados(EstructuraSucursales* sucur);
void setMCuadrados (EstructuraSucursales* sucur,float NewMetros);

int getCasaMatriz(EstructuraSucursales* sucur);
void setCasaMatriz(EstructuraSucursales* sucur, int NewCasaMatriz);

void mostrarSucursal (EstructuraSucursales* sucur);

#endif // TDA_H_INCLUDED
