#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "TDA.h"
#include "ListaSucursales.h"
#include <fstream>

const char *provincias[23]= {"Misiones","Buenos Aires","Catamarca","Jujuy","San Luis","San Juan","Chaco","Chubut","Cordoba","Corriente","Entre Rios","Formosa","La Pampa", "La Rioja", "Mendoza","Neuquen","Rio Negro","Salta","Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra de Fuego", "Tucuman"};

void ordenarNacionalFacturacion(Listaenc* miLista);
void ordenarProvinciaFacturacion(Listaenc* miLista);
void ordenarNacionalCantArt(Listaenc* miLista);
void ordenarProvinciaCantArt(Listaenc* miLista);
void cargarDatos(Listaenc* miLista);

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

    do
    {
        cout<<"Bienvenido al administrador de sucursales\n";
        cout<<"Elija un numero de opcion:\n\n" ;
        cout<<"1. Listar por facturacion.\n";
        cout<<"2. Ranking cantidad articulos vendidos.\n";
        cout<<"3. Mostrar sucursales.\n";
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
            {  system("cls");
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
            {  system("cls");
                break;
            }

        case 3:

            imprimir(miLista);
            break;

        case 6:
            cargarDatos(miLista);
            break;

        case 0:
            exit;
            break;

        default:
            cout<<endl<<"Opcion no encontrada \n"<<endl;
            system ("pause");
            system("cls");
        }
    }
    while(opcion!=0);
    if(opcion==0)
    {
        system("cls");
        cout<<"\nHasta luego!!\n";
    }
    liberarLista(miLista);
    return 0;
}

void cargarDatos(Listaenc* miLista)
{
    if(miLista->inicio==NULL)
    {
        ifstream archivo;
        string texto;
        int cont = 0;
        int contSucursales = 0;
        ///Tipos de datos del nodo
        int articulos,n;
        float montoMensual,metrosCuadrados;
        char provincia[20],numeroCasaMatriz[5],codigo[5];
        char CasaAux[50],CodAux[50];
        int a = 0;
        ///
        //Listaenc* miLista1 = crearLista();

        archivo.open("ejemplo-sucursales.txt",ios::in);

        if(archivo.fail())
        {
            cout<<endl<<"No se puede abrir el archivo"<<endl<<endl;
            exit(1);
        }
        while(archivo >> ws,getline(archivo,texto,'-'))
        {

            switch(cont)
            {
            case 0:
                //texto.resize(4);
                strcpy(codigo,texto.c_str());
                //strcpy(CodAux,aux);
                break;

            case 1:
                strcpy(provincia,texto.c_str());
                //strcpy(provincia,aux);
                //strcpy("",aux);
                //cout<<provincia<<endl;
                break;

            case 2:
                articulos = atoi(texto.c_str());
                //cout<<articulos<<endl;
                break;

            case 3:
                montoMensual = atof(texto.c_str());
                //cout<<montoMensual<<endl;
                break;

            case 4:
                metrosCuadrados = atof(texto.c_str());
                //cout<<metrosCuadrados<<endl;
                break;

            case 5: //strcpy(CodAux,texto.c_str());
                strcpy(numeroCasaMatriz,texto.c_str());
                //cout<<numeroCasaMatriz<<endl;
                break;
            }
            if(cont == 5)
            {
                //insertarNodoCnStruct(contSucursales,codigo,provincia,articulos,montoMensual,metrosCuadrados,numeroCasaMatriz);
                EstructuraSucursales* Sucursal = new EstructuraSucursales(codigo,provincia,articulos,montoMensual,metrosCuadrados,numeroCasaMatriz);
                insertar(miLista,Sucursal,a);
                contSucursales++;
                a++;
                cont = -1;
            }
            cont++;
        }
        archivo.close();
        cout<<endl<<"Archivo cargado con exito"<<endl<<endl;
    }
    else
    {
        cout<<endl<<"El archivo ya se encuentra cargado"<<endl<<endl;
    }
    system ("pause");
    system("cls");

}

void ordenarNacionalFacturacion(Listaenc* miLista)
{
    if(miLista->inicio==NULL)
    {
        cout<<endl<<"No hay datos cargados"<<endl<<endl;

    }
    else
    {
        system("cls");
        int tamanioLista,i,j;
        obtenerTamanio(miLista,&tamanioLista);
        EstructuraSucursales* auxiliar;
        EstructuraSucursales* sucursal[tamanioLista];

        for(i=0; i<tamanioLista; i++)
        {
            obtenerElemento(miLista,&sucursal[i],i);
        }

        for(i=0; i<tamanioLista; i++)
        {
            for(j=0; j<tamanioLista; j++)
            {
                if(sucursal[i]->monto_mensual>sucursal[j]->monto_mensual)
                {
                    auxiliar=sucursal[i];
                    sucursal[i]=sucursal[j];
                    sucursal[j]=auxiliar;
                }
            }
        }
        for(i=0; i<tamanioLista; i++)
        {
            mostrarSucursal(sucursal[i]);
        }
    }
    system ("pause");
    system("cls");
}

void ordenarProvinciaFacturacion(Listaenc* miLista)
{
    if(miLista->inicio==NULL)
    {
        cout<<endl<<"No hay datos cargados"<<endl<<endl;
    }
    else
    {
        system("cls");
        int tamanioLista,i,j;
        obtenerTamanio(miLista,&tamanioLista);
        EstructuraSucursales* auxiliar;
        EstructuraSucursales* sucursal[tamanioLista];

        for(i=0; i<tamanioLista; i++)
        {
            obtenerElemento(miLista,&sucursal[i],i);
        }

        for(i=0; i<tamanioLista; i++)
        {
            for(j=0; j<tamanioLista; j++)
            {
                if(sucursal[i]->monto_mensual>sucursal[j]->monto_mensual)
                {
                    auxiliar=sucursal[i];
                    sucursal[i]=sucursal[j];
                    sucursal[j]=auxiliar;
                }
            }
        }
        float totalProvincias;
        for(i=0; i<23; i++)
        {
            cout<<endl<<provincias[i]<<": "<<endl;
            totalProvincias=0;
            for(j=0; j<tamanioLista; j++)
            {
                if(strcmp(provincias[i], sucursal[j]->provincia)==0)
                {
                    mostrarSucursal(sucursal[j]);
                    totalProvincias+=sucursal[j]->monto_mensual;
                }
            }cout<<endl<<"Total: "<<totalProvincias<<endl<<"___________________________________________"<<endl;
        }
    }
    system ("pause");
    system("cls");
}

void ordenarNacionalCantArt(Listaenc* miLista)
{
    if(miLista->inicio==NULL)
    {
        cout<<endl<<"No hay datos cargados"<<endl<<endl;

    }
    else
    {
        system("cls");
        int tamanioLista,i,j;
        obtenerTamanio(miLista,&tamanioLista);
        EstructuraSucursales* auxiliar;
        EstructuraSucursales* sucursal[tamanioLista];

        for(i=0; i<tamanioLista; i++)
        {
            obtenerElemento(miLista,&sucursal[i],i);
        }

        for(i=0; i<tamanioLista; i++)
        {
            for(j=0; j<tamanioLista; j++)
            {
                if(sucursal[i]->cantidad_articulos>sucursal[j]->cantidad_articulos)
                {
                    auxiliar=sucursal[i];
                    sucursal[i]=sucursal[j];
                    sucursal[j]=auxiliar;
                }
            }
        }
        for(i=0; i<tamanioLista; i++)
        {
            mostrarSucursal(sucursal[i]);
        }
    }
    system ("pause");
    system("cls");
}

void ordenarProvinciaCantArt(Listaenc* miLista)
{
    if(miLista->inicio==NULL)
    {
        cout<<endl<<"No hay datos cargados"<<endl<<endl;
    }
    else
    {
        system("cls");
        int tamanioLista,i,j;
        obtenerTamanio(miLista,&tamanioLista);
        EstructuraSucursales* auxiliar;
        EstructuraSucursales* sucursal[tamanioLista];

        for(i=0; i<tamanioLista; i++)
        {
            obtenerElemento(miLista,&sucursal[i],i);
        }

        for(i=0; i<tamanioLista; i++)
        {
            for(j=0; j<tamanioLista; j++)
            {
                if(sucursal[i]->cantidad_articulos>sucursal[j]->cantidad_articulos)
                {
                    auxiliar=sucursal[i];
                    sucursal[i]=sucursal[j];
                    sucursal[j]=auxiliar;
                }
            }
        }
        float totalProvincias;
        for(i=0; i<23; i++)
        {
            cout<<endl<<provincias[i]<<": "<<endl;

            for(j=0; j<tamanioLista; j++)
            {
                if(strcmp(provincias[i], sucursal[j]->provincia)==0)
                {
                    mostrarSucursal(sucursal[j]);
                }
            }cout<<endl<<"___________________________________________"<<endl;
        }
    }
    system ("pause");
    system("cls");
}

