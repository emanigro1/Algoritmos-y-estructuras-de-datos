#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "TDA.h"
#include "ListaSucursales.h"
#include <fstream>

const char *provincias[23]= {"Buenos Aires","Catamarca","Jujuy","San Luis","Misiones","San Juan","Chaco","Chubut","Cordoba","Corriente","Entre Rios","Formosa","La Pampa", "La Rioja", "Mendoza","Neuquen","Rio Negro","Salta","Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra de Fuego", "Tucuman"};

void ordenarNacionalFacturacion(Listaenc* miLista);
void ordenarProvinciaFacturacion(Listaenc* miLista);
void ordenarNacionalCantArt(Listaenc* miLista);
void ordenarProvinciaCantArt(Listaenc* miLista);
void ordenarPorRendimiento(Listaenc* miLista);
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
        cout<<"Bienvenido al administrador de sucursales"<<endl;
        cout<<"Elija un numero de opcion:"<<endl<<endl ;
        cout<<"1. Listar por facturacion."<<endl;
        cout<<"2. Ranking de cantidad de articulos vendidos."<<endl;
        cout<<"3. Ranking de rendimiento."<<endl<<endl;
        cout<<"4. Mostrar sucursales."<<endl;
        cout<<"6. Cargar datos del txt."<<endl<<endl;
        cout<<"0. Salir"<<endl<<endl;

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
    if(estaVacia(miLista))
    {
        ifstream archivo;
        string texto;
        int cont = 0;
        int contSucursales = 0;
        ///Tipos de datos del nodo
        int articulos,numeroCasaMatriz,n;
        float montoMensual,metrosCuadrados;
        char provincia[20],codigo[5];
        char CasaAux[50],CodAux[50];
        int a = 0;
        ///


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
                strcpy(codigo,texto.c_str());
                break;

            case 1:
                strcpy(provincia,texto.c_str());
                break;

            case 2:
                articulos = atoi(texto.c_str());
                break;

            case 3:
                montoMensual = atof(texto.c_str());
                break;

            case 4:
                metrosCuadrados = atof(texto.c_str());
                break;

            case 5:
                numeroCasaMatriz= atoi(texto.c_str());
                break;
            }
            if(cont == 5)
            {
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
    if(estaVacia(miLista))
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
        cout<<"Facturacion nacional"<<endl;
        cout<<"__________________________"<<endl;
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
    if(estaVacia(miLista))
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
        int encontrado;

        cout<<"Facturacion por provincias"<<endl;
        cout<<"__________________________"<<endl;
        for(i=0; i<23; i++)
        {
            encontrado=0;
            totalProvincias=0;
            for(j=0; j<tamanioLista; j++)
            {
                if(strcmp(provincias[i], sucursal[j]->provincia)==0)
                {
                    mostrarSucursal(sucursal[j]);
                    totalProvincias+=sucursal[j]->monto_mensual;
                    encontrado=1;
                }
            }
            if(encontrado)
            {
                cout<<endl<<"Total en "<<provincias[i]<<": "<<totalProvincias;
                cout<<endl<<"___________________________________________"<<endl;

            }

        }
    }
    system ("pause");
    system("cls");
}

void ordenarNacionalCantArt(Listaenc* miLista)
{
    if(estaVacia(miLista))
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
        cout<<"Cantidad de articulos vendidos nivel nacional"<<endl;
        cout<<"_____________________________________________"<<endl;
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
    if(estaVacia(miLista))
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
        int encontrado;
        float totalProvincias;

        cout<<"Cantidad de articulos vendidos por provincias"<<endl;
        cout<<"_____________________________________________"<<endl;
        for(i=0; i<23; i++)
        {
            encontrado=0;
            for(j=0; j<tamanioLista; j++)
            {
                if(strcmp(provincias[i], sucursal[j]->provincia)==0)
                {
                    mostrarSucursal(sucursal[j]);
                    encontrado=1;
                }
            }
            if(encontrado)
            {
                cout<<endl<<"Sucursales de "<<provincias[i];
                cout<<endl<<"___________________________________________"<<endl;
            }

        }
    }
    system ("pause");
    system("cls");
}

typedef struct
{
    char codSuc[5]="nada";
    int casaMatriz=9999999;
    float rendimiento=0;
} Rendimiento;

void ordenarPorRendimiento(Listaenc* miLista)
{
    if(estaVacia(miLista))
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
        Rendimiento rendimientoFranquicia[tamanioLista],aux;
        int cant=0,encontrado=0;
        for(i=0; i<tamanioLista; i++)
        {
            obtenerElemento(miLista,&sucursal[i],i);
        }
        cout<<"Rendimiento por metros cuadrados"<<endl;
        cout<<"________________________________"<<endl;

        for(i=0; i<10000; i++)
        {
            encontrado=0;
            for(j=0; j<tamanioLista; j++)
            {
                if(sucursal[j]->casa_matriz==i)
                {
                    if(i==0)
                    {
                        strcpy(rendimientoFranquicia[cant].codSuc,sucursal[j]->codigo);
                        rendimientoFranquicia[cant].rendimiento=sucursal[j]->monto_mensual/sucursal[j]->m_cuadrados;
                        cant++;
                    }
                    else
                    {
                        rendimientoFranquicia[cant].casaMatriz=i;
                        rendimientoFranquicia[cant].rendimiento+=sucursal[j]->monto_mensual/sucursal[j]->m_cuadrados;
                        encontrado=1;
                    }
                }
            }
            if(encontrado)cant++;
        }
        for(i=0; i<cant; i++)
        {
            for(j=0; j<cant; j++)
            {
                if(rendimientoFranquicia[i].rendimiento>rendimientoFranquicia[j].rendimiento)
                {
                    aux=rendimientoFranquicia[i];
                    rendimientoFranquicia[i]=rendimientoFranquicia[j];
                    rendimientoFranquicia[j]=aux;
                }
            }
        }
        for(i=0; i<cant; i++)
        {
            for(j=0; j<tamanioLista; j++)
            {
                if(strcmp(rendimientoFranquicia[i].codSuc, sucursal[j]->codigo)==0||rendimientoFranquicia[i].casaMatriz==sucursal[j]->casa_matriz && sucursal[j]->casa_matriz!=0)
                {
                    mostrarSucursal(sucursal[j]);

                }

            }
            cout<<endl<<"Rendimiento: "<<rendimientoFranquicia[i].rendimiento;
            cout<<endl<<"___________________________________________"<<endl;
        }

    }
    system ("pause");
    system("cls");
}
