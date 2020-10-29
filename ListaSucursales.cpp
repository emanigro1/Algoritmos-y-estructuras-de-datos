#include "ListaSucursales.h"
#include "TDA.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Listaenc* crearLista()
{
    Listaenc * lista = new Listaenc();
    if(lista == NULL)
        return NULL;
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

void liberarLista(Listaenc* lista)
{
    if(estaInicializado(lista)){
    while(!estaVacia(lista)) remover(lista, NULL, 0);
    delete lista;
    lista = NULL;
    }
    else{
        cout<<"no se encuentra inicializada la lista(Liberarlista)"<<endl;
    }
}

bool estaInicializado(Listaenc* lista){
    bool Inicializado = true;
    if(lista == NULL){
        Inicializado = false;
    }
    return Inicializado;
}

bool estaInicializado(ListaSucursales* sucursal){
    bool Inicializado = true;
    if(sucursal == NULL){
        Inicializado = false;
    }
    return Inicializado;
}

bool estaVacia(Listaenc* lista)
{
    bool estaVacia = true;
    if(estaInicializado(lista)){
    if (!lista->inicio == NULL)
        estaVacia = false;
    return estaVacia;
    }
    estaVacia = false;
    return estaVacia;
}

ListaSucursales* crearSucur(EstructuraSucursales * sucursal,ListaSucursales* proximo)
{
    ListaSucursales* nueva_Sucursal = new ListaSucursales;
    if (nueva_Sucursal == NULL) return NULL;

    nueva_Sucursal->sucursales = sucursal;
    nueva_Sucursal->siguiente = proximo;
    return nueva_Sucursal;
}

void insertarInicio(Listaenc* lista,EstructuraSucursales * sucursal)
{
    if(estaInicializado(lista)){
        ListaSucursales *nuevoNodo = crearSucur(sucursal,lista->inicio);
        if(estaInicializado(nuevoNodo)){
        lista->inicio = nuevoNodo;
        lista->tam++;
        }
        else{
            cout<<"El nodo es nulo"<<endl;
            }
        }
    else{
        cout<<"no se encuentra inicializada la lista(InsertarInicio)"<<endl;
        }
}

void insertar(Listaenc* nacional,EstructuraSucursales * sucursal, int pos)
{
    /*if (pos < 0 || pos > nacional->tam)
        return INDICE_INVALIDO;*/
    if((estaInicializado(nacional)) && (!(pos < 0 || pos > nacional->tam))){
        if (pos == 0)
        {
            insertarInicio(nacional, sucursal);
        }
        else
        {
            // prepara para inserir
            ListaSucursales *nuevoNodo;///Se crea un nuevo nodo que posee un puntero a la estructura sucursales y un puntero hacia la siguiente ubicacion
            ListaSucursales *aux;///Se crea un puntero "auxiliar"
            aux = nacional->inicio;/// el auxiliar es se iguala al inicio que hay actualmente en la lista
            for(int i = 0; i < pos-1; i++)
            {
                aux = aux->siguiente;
            }
            // adiciona o nó
            nuevoNodo = crearSucur(sucursal, aux->siguiente);
            if (estaInicializado(nuevoNodo)){
            aux->siguiente = nuevoNodo;
            nacional->tam++;
            }
        //return OK;
        }
        }
    else{
        cout<<"no se encuentra inicializada la lista(Insertar)"<<endl;
    }
}
/*
int insertarProvincia(Listaenc* provincial,EstructuraSucursales * sucursal, int pos){
    ListaSucursales* nuevoNodo;
    ListaSucursales* aux;
    nuevoNodo = crearSucur(sucursal, aux->siguiente);
    if(strcmp(nuevoNodo->sucursales->provincia,"Buenos Aires" == 0)){
    if(pos == 0){
        insertarInicio(provincial, sucursal);
    }
    aux = provincial->inicio;
    for(int i = 0;i < pos-1;i++){
        aux = aux->siguiente;
    }
        aux->siguiente = nuevoNodo;
        provincial->tam++;
       }
    else{
        cout<<"no es el caso"<<endl;
    }

}
*/
void removerInicio(Listaenc* lista, EstructuraSucursales * sucursal)
{
    if(estaInicializado(lista) && !(estaVacia(lista))){
    ListaSucursales *aux = lista->inicio;
    if (sucursal != NULL)
        sucursal = aux->sucursales;
    lista->inicio = aux->siguiente;
    delete aux;
    aux = NULL;
    lista->tam--;
    }
}

void remover(Listaenc* lista, EstructuraSucursales * sucursal, int pos)
{
    if(estaInicializado(lista) && !(estaVacia(lista)) && !(pos < 0 || pos >= lista->tam)){
    ListaSucursales *anterior, *actual;
    if (pos == 0)
    {
        removerInicio(lista, sucursal);
    }
    else
    {
        // prepara para remover
        anterior = NULL;
        actual = lista->inicio;
        for(int i = 0; i < pos; i++)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        // remove o nó actual
        anterior->siguiente = actual->siguiente;
        if (sucursal != NULL)
            sucursal = actual->sucursales;
        delete actual;
        actual = NULL;
        lista->tam--;
    }
    }
}

void obtenerElemento(Listaenc* lista, EstructuraSucursales** sucursal, int pos)
{
    if(estaInicializado(lista) && (!estaVacia(lista) && (!(pos < 0 || pos >= lista->tam))) && (!(sucursal == NULL))){
    ListaSucursales *aux;
    aux = lista->inicio;
    for(int i = 0; i < pos; i++)
    {
        aux = aux->siguiente;
    }
    *sucursal = aux->sucursales;
    }
    else{
        cout<<"no se encuentra inicializada la lista(obtener Elmento)"<<endl;
    }
}

void obtenerTamanio(Listaenc* lista, int* tam)
{
    if((estaInicializado(lista)) && (!(tam == NULL))){
    *tam = lista->tam;
    }
    else{
        cout<<"no esta inicializado o el tamanio es nulo(Obtener tamanio)"<<endl;
    }
}

void imprimir(Listaenc* lista)
{
    if(lista->inicio==NULL)
    {
        cout<<endl<<"No hay datos cargados"<<endl<<endl;
    }
    else
    {    system("cls");
        int qtdeElementos;
        obtenerTamanio(lista, &qtdeElementos);

        EstructuraSucursales * dato;

        for(int i = 0; i < qtdeElementos; i++)
        {
            obtenerElemento(lista, &dato, i);
            mostrarSucursal(dato);

        }
        cout<<endl;
    }
    system ("pause");
    system("cls");
}
