#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "TDA.h"
#include "ListaSucursales.h"
#include <fstream>
/*struct nodo
{
    EstructuraSucursales* sucursal=new EstructuraSucursales;
    nodo *siguiente;

}*primero,*ultimo;*/

/*void insertarNodo();
void mostrarLista();
void eliminarSucursal();
void modificarSucursal();
void buscarSucursar();
void cargarDatos();
//void leer(char texto[50],char delimitador,struct nodo *nodos);
void insertarNodoCnStruct(int contarSucursales, char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados, char casaMatriz[5]);
*/
const char *provincias[23]= {"Misiones","Buenos Aires","Catamarca","Jujuy","San Luis","San Juan","Chaco","Chubut","Cordoba","Corriente","Entre Rios","Formosa","La Pampa", "La Rioja", "Mendoza","Neuquen","Rio Negro","Salta","Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra de Fuego", "Tucuman"};

void ordenarNacionalFacturacion(Listaenc* miLista);
void ordenarProvinciaFacturacion(Listaenc* miLista);
void cargarDatos(Listaenc* miLista);
void menu();

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
    // EstructuraSucursales* Sucursal1 = new EstructuraSucursales("0034","Buenos Aires",50, 47.53, 18.5, "0012");
    //mostrarSucursal(Sucursal1);
    /*Nodo* Sucursal = new Nodo();


    insertarLista(Nodo);
    delete Sucursal1;*/

    menu();
    return 0;
}

void menu()
{
    int opcion;

    Listaenc* miLista = crearLista();
    Listaenc* facturacionNacional= crearLista();
    do
    {
        cout<<"Bienvenido al administrador de sucursales\n";
        cout<<"Elija un numero de opcion:\n\n" ;
        cout<<"1. Facturacion Nacional.\n";
        cout<<"2. Facturacion Provincial.\n";
        cout<<"3. Mostrar sucursales.\n";
        cout<<"6. Cargar datos del txt.\n\n";
        cout<<"0. Salir\n\n";

        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            ordenarNacionalFacturacion(miLista);
            break;

        case 2:
            ordenarProvinciaFacturacion(miLista);
            break;
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
            cout<<"Opcion no encontrada \n";
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
}
/*
void insertarNodo()
{
    system("cls");

    nodo*nuevo=new nodo();
    int articulos;
    float montoMensual,metrosCuadrados;
    char provincia[20];
    char codigo[5];
    char numeroCasaMatriz[5];

    cout<<"Ingrese un codigo\n";
    fflush(stdin);
    cin>>codigo;
    cout<<"Ingrese una provincia\n";
    fflush(stdin);
    gets(provincia);
    cout<<"Ingrese cantidad de articulos\n";
    fflush(stdin);
    cin>>articulos;
    cout<<"Ingrese monto mensual\n";
    fflush(stdin);
    cin>>montoMensual;
    cout<<"Ingrese metros cuadrados\n";
    fflush(stdin);
    cin>>metrosCuadrados;
    cout<<"Ingrese numero casa matriz\n";
    fflush(stdin);
    cin>>numeroCasaMatriz;

    nuevoSucursal(nuevo->sucursal,codigo,provincia,articulos,montoMensual,metrosCuadrados,numeroCasaMatriz);

    if(primero==NULL)
    {
        primero=nuevo;
        ultimo=nuevo;
        primero->siguiente=NULL;

    }
    else
    {
        ultimo->siguiente=nuevo;
        nuevo->siguiente=NULL;
        ultimo=nuevo;
    }

    cout<<"\nSucursar cargada.\n";

    system ("pause");
    system("cls");
}

void mostrarLista()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;

    if(actual==NULL)
    {
        cout<<"La lista esta vacia.\n\n";
    }
    else
    {
        while(actual!=NULL)
        {
            mostrarSucursal(actual->sucursal);
            actual=actual->siguiente;
        }
    }
    system ("pause");
    system("cls");
}

void eliminarSucursal()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;
    nodo*anterior=new nodo();
    anterior = NULL;
    int encontrado=0;
    char codigo[4];

    if(actual==NULL)
    {
        cout<<"La lista esta vacia.\n\n";
    }
    else
    {
        cout<<"Ingrese codigo de sucursal a eliminar: ";
        fflush(stdin);
        cin>>codigo;

        while(actual!=NULL && encontrado==0)
        {
            if(strcmp(codigo,getCodigo(actual->sucursal)) == 0)
            {
                destruirSucursal(actual->sucursal);
                if(actual==primero){
                    primero=primero->siguiente;
                }else if(actual==ultimo){
                    anterior->siguiente=NULL;
                    ultimo=anterior;
                }else{
                    anterior->siguiente=actual->siguiente;
                }

                cout<<"\nSucursal ID= "<<codigo<<" eliminada.\n";
                encontrado=1;
            }
            anterior=actual;
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            cout<<"Codigo de sucursal no encontrado.\n";
        }
    }
    system ("pause");
    system("cls");
}

void modificarSucursal()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;
    int opcion;

    if(actual==NULL)
    {
        cout<<"La lista esta vacia\n\n";
    }
    else
    {
        int nuevaCantArt,encontrado=0;
        float nuevoMontoMensual,nuevoMCuadrados;
        char nuevaProvincia[20],nuevoCodigo[4],nuevoCasaMatriz[4],codigo[4];

        cout<<"Ingrese codigo de sucursal a modificar: ";
        fflush(stdin);
        cin>>codigo;

        while(actual!=NULL&&encontrado==0)
        {
            if(strcmp(codigo,getCodigo(actual->sucursal))== 0)
            {  cout<<"\nSucursal elegida:";
                mostrarSucursal(actual->sucursal);
                encontrado=1;

                cout<<"\nIngrese el numero de la opcion elegida a modificar:\n\n";
                cout<<"1. Codigo.\n";
                cout<<"2. Provincia.\n";
                cout<<"3. Cantidad de articulos.\n";
                cout<<"4. Monto Mensual.\n";
                cout<<"5. Metros Cuadrados.\n";
                cout<<"6. Casa Matriz.\n\n";
                cout<<"Opcion: ";
                cin>>opcion;

                switch(opcion)
                {
                case 1:
                    cout<<"\nValor actual: "<<getCodigo(actual->sucursal)<<"\nValor nuevo: ";
                    fflush(stdin);
                    cin>>nuevoCodigo;
                    setCodigo(actual->sucursal,nuevoCodigo);
                    break;

                case 2:
                    cout<<"\nValor actual: "<<getProvincia(actual->sucursal)<<"\nValor nuevo: ";
                    cin>>nuevaProvincia;
                    setProvincia(actual->sucursal,nuevaProvincia);
                    break;

                case 3:
                    cout<<"\nValor actual: "<<getCantidadArticulos(actual->sucursal)<<"\nValor nuevo: ";
                    cin>>nuevaCantArt;
                    setCantidadArticulos(actual->sucursal,nuevaCantArt);
                    break;

                case 4:
                    cout<<"\nValor actual: "<<getMontoMensual(actual->sucursal)<<"\nValor nuevo: ";
                    cin>>nuevoMontoMensual;
                    setMontoMensual(actual->sucursal,nuevoMontoMensual);
                    break;

                case 5:
                    cout<<"\nValor actual: "<<getMCuadrados(actual->sucursal)<<"\nValor nuevo: ";
                    cin>>nuevoMCuadrados;
                    setMCuadrados(actual->sucursal,nuevoMCuadrados);
                    break;

                case 6:
                    cout<<"\nValor actual: "<<getCasaMatriz(actual->sucursal)<<"\nValor nuevo: ";
                    fflush(stdin);
                    cin>>nuevoCasaMatriz;
                    setCasaMatriz(actual->sucursal,nuevoCasaMatriz);
                    break;

                default:
                    cout<<"Opcion no encontrada";

                }
            }
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            cout<<"\nDato no encontrado\n";
        }
    }

    system ("pause");
    system("cls");
}

void buscarSucursar()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;
    int encontrado=0;
    char codigo[4];

    if(actual==NULL)
    {
        cout<<"La lista esta vacia.\n\n";
    }
    else
    {
        cout<<"Ingrese codigo de sucursal a buscar:";
        fflush(stdin);
        cin>>codigo;

        while(actual!=NULL && encontrado==0)
        {
            if(strcmp(codigo,getCodigo(actual->sucursal))== 0)
            {
                mostrarSucursal(actual->sucursal);
                encontrado=1;
            }
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            cout<<"\nDato no encontrado\n";
        }
    }
        system ("pause");
    system("cls");
}
*/
void cargarDatos(Listaenc* miLista)
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
        cout<<"No se puede abrir el archivo";
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
    cout<<"Archivo cargado con exito"<<endl;
    system ("pause");
    system("cls");

}

void ordenarNacionalFacturacion(Listaenc* miLista)
{
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
    system ("pause");
    system("cls");
}

void ordenarProvinciaFacturacion(Listaenc* miLista)
{
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
    for(i=0; i<23; i++)
    {
        cout<<endl<<provincias[i]<<endl;
        for(j=0; j<tamanioLista; j++)
        {
            if(strcmp(provincias[i], sucursal[j]->provincia)==0)
            {
                mostrarSucursal(sucursal[j]);
            }
        }
    }
    system ("pause");
    system("cls");
}

/*
void insertarNodoCnStruct(int contarSucursales, char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados, char casaMatriz[5])
{
    system("cls");

    nodo*nuevo=new nodo();

    crearSucursal(nuevo->sucursal,codigo,provincia,articulos,montoMensual,mCuadrados,casaMatriz);

    if(primero==NULL)
    {
        primero=nuevo;
        ultimo=nuevo;
        primero->siguiente=NULL;

    }
    else
    {
        ultimo->siguiente=nuevo;
        nuevo->siguiente=NULL;
        ultimo=nuevo;
    }

    cout<<"\nSe cargaron "<<contarSucursales+1<<" Sucursales con exito"<<endl;

    system ("pause");
    system("cls");
}
/*
void leer(char texto[50],char delimitador,struct nodo *nodos){
    int posDelimitador = 0,i;
    char aux[50]= "";
    //nodo* nodito = new nodo;

    for(i = 0;i<50;i++)
    {
        if(texto[i] == delimitador)
        {
            posDelimitador = i;
        }
    }

    for(i=0;i<posDelimitador;i++)
    {
        aux[i] = texto[i];//cargo el dato deseado a la variable "Aux"
    }
    int codigoAux = atoi(aux);
    nodos->sucursal->codigo = codigoAux;
    strcpy("",aux);

    for(i=posDelimitador+1;i<50;i++)
    {
        aux[i-posDelimitador-1] = texto[i];
    }
    strcpy(nodos->sucursal->provincia,aux);
    strcpy("",aux);

}*/



