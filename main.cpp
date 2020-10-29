#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "TDA.h"
#include "ListaSucursales.h"
#include "generalidades.h"

using namespace std;

/*  Se pide elaborar:

    ● Un listado con el orden de las sucursales que más facturaron a nivel nacional y en
    cada provincia, (incluir los totales por provincia).

    ● Un ranking con las sucursales que mayor cantidad de artículos vendieron a nivel
    nacional y por provincia.

    ● Un ranking de rendimiento donde se busca las sucursales que mejores rendimientos
    por metro cuadrado tienen, ordenando por el cociente de facturación/metros
    cuadrados del local.
*/

int main()
{
    int opcion;

    Listaenc* miLista = crearLista();
    //Listaenc* provincial = crearLista();

    do
    {
        cout<<"Bienvenido al administrador de sucursales\n";
        cout<<"Elija un numero de opcion:\n\n" ;
        cout<<"1. Listar por facturacion.\n";
        cout<<"2. Ranking cantidad articulos vendidos.\n";
        cout<<"3. Rendimiento.\n";
        cout<<"4. Mostrar sucursales.\n";
        cout<<"6. Cargar datos del txt.\n\n";
        cout<<"0. Salir\n\n";

        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:

            cout<<endl<<"1. Nacional"<<endl;
            cout<<"2. Provincial"<<endl;

            cout<<endl<<"Opcion: ";
            cin>>opcion;

            if(opcion==1)
            {
                ordenarNacionalFacturacion(miLista);
                break;
            }
            else if(opcion==2)
            {
                ordenarProvinciaFacturacion(miLista);
                break;
            }
            else
            {
                system("cls");
                break;
            }
        case 2:

            cout<<endl<<"1. Nacional"<<endl;
            cout<<"2. Provincial"<<endl;

            cout<<endl<<"Opcion: ";
            cin>>opcion;

            if(opcion==1)
            {
                ordenarNacionalCantArt(miLista);
                break;
            }
            else if(opcion==2)
            {
                ordenarProvinciaCantArt(miLista);
                break;
            }
            else
            {
                system("cls");
                break;
            }
        case 3:
            ordenarPorRendimiento(miLista);
            break;
        case 4:
            imprimir(miLista);
            break;
        case 6:
            cargarDatos(miLista);
            break;

        case 0:
            //exit;
            system("cls");
            cout<<"\Hasta luego!!\n";
            liberarLista(miLista);
            break;

        default:
            cout<<endl<<"Opcion no encontrada \n"<<endl;
            system ("pause");
            system("cls");
        }
    }
    while(opcion!=0);

    return 0;
}
