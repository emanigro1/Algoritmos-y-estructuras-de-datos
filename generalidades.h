#ifndef GENERALIDADES_H_INCLUDED
#define GENERALIDADES_H_INCLUDED

#include "ListaSucursales.h"
#include "TDA.h"

typedef struct
{
    char codSuc[5];
    char casaMatriz[4];
    float rendimiento=0;
} Rendimiento;

void cargarDatos(Listaenc* miLista);
void ordenarNacionalFacturacion(Listaenc* miLista);
void ordenarProvinciaFacturacion(Listaenc* miLista);
void ordenarNacionalCantArt(Listaenc* miLista);
void ordenarProvinciaCantArt(Listaenc* miLista);
void ordenarPorRendimiento(Listaenc* miLista);

#endif // GENERALIDADES_H_INCLUDED
