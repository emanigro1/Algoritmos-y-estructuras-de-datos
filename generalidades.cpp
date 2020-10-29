#include "generalidades.h"
#include "ListaSucursales.h"
#include "TDA.h"
#include <iostream>
#include <fstream>

using namespace std;

const char *provincias[23]= {"Misiones","Buenos Aires","Catamarca","Jujuy","San Luis","San Juan","Chaco","Chubut","Cordoba","Corriente","Entre Rios","Formosa","La Pampa", "La Rioja", "Mendoza","Neuquen","Rio Negro","Salta","Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra de Fuego", "Tucuman"};


void cargarDatos(Listaenc* miLista)
{
    if(miLista->inicio==NULL)
    {
        ifstream archivo;
        string texto;
        int cont = 0;
        ///Tipos de datos del nodo
        int articulos,n;
        float montoMensual,metrosCuadrados;
        char provincia[20],numeroCasaMatriz[5],codigo[5];
        //char CasaAux[50],CodAux[50];
        int posicion = 0;
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
                strcpy(numeroCasaMatriz,texto.c_str());
                break;
            }
            if(cont == 5)
            {
                EstructuraSucursales* Sucursal = new EstructuraSucursales(codigo,provincia,articulos,montoMensual,metrosCuadrados,numeroCasaMatriz);
                insertar(miLista,Sucursal,posicion);
                posicion++;
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
            }
            cout<<endl<<"Total: "<<totalProvincias<<endl<<"___________________________________________"<<endl;
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
            }
            cout<<endl<<"___________________________________________"<<endl;
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
        int cant=0;
        for(i=0; i<tamanioLista; i++)
        {
            obtenerElemento(miLista,&sucursal[i],i);
        }
        cout<<"Rendimiento por metros cuadrados"<<endl;
        cout<<"________________________________"<<endl;

        bool encontrado;

        for(i=0; i<tamanioLista; i++)
        {
            float rendimiento=0;
            rendimiento=sucursal[i]->monto_mensual/sucursal[i]->m_cuadrados;

            if(strcmp(sucursal[i]->casa_matriz,"0000")==0)
            {
                strcpy(rendimientoFranquicia[i].codSuc,sucursal[i]->codigo);
                rendimientoFranquicia[i].rendimiento=rendimiento;
                cant++;
            }
            else
            {
                encontrado=false;
                for(j=0; j<tamanioLista; j++)
                {
                    if(strcmp(sucursal[i]->casa_matriz,rendimientoFranquicia[j].casaMatriz)==0)
                    {
                        rendimientoFranquicia[j].rendimiento+=rendimiento;
                        encontrado=true;
                    }
                }
                if(!encontrado)
                {
                    strcpy(rendimientoFranquicia[i].casaMatriz,sucursal[i]->casa_matriz);
                    rendimientoFranquicia[i].rendimiento=rendimiento;
                    cant++;
                }
            }
        }
        for(i=0; i<tamanioLista; i++)
        {
            for(j=tamanioLista-1; j>=i; j--)
            {
                if(rendimientoFranquicia[i].rendimiento<rendimientoFranquicia[j].rendimiento)
                {
                    aux=rendimientoFranquicia[i];
                    rendimientoFranquicia[i]=rendimientoFranquicia[j];
                    rendimientoFranquicia[j]=aux;
                }
            }
            for(j=0; j<tamanioLista; j++)
            {
                if(strcmp(rendimientoFranquicia[i].codSuc, sucursal[j]->codigo)==0||strcmp(rendimientoFranquicia[i].casaMatriz,sucursal[j]->casa_matriz)==0 && strcmp(sucursal[j]->casa_matriz,"0000")!=0)
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
