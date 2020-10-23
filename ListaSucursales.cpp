#include "ListaSucursales.h"
#include "TDA.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int cont = 0;

Listaenc* crearLista()
{
    Listaenc * lista = new Listaenc();
    if(lista == NULL)
        return NULL;
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

int liberarLista(Listaenc* lista)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    while(!estaVacia(lista))
        remover(lista, NULL, 0);
    delete(lista);
    lista = NULL;
}

int estaVacia(Listaenc* lista)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (lista->inicio == NULL)
        return TRUE;
    return FALSE;
}

ListaSucursales* crearSucur(EstructuraSucursales * sucursal,ListaSucursales* proximo)
{
    ListaSucursales* nueva_Sucursal = new ListaSucursales;
    if (nueva_Sucursal == NULL) return NULL;

    nueva_Sucursal->sucursales = sucursal;
    nueva_Sucursal->siguiente = proximo;
    return nueva_Sucursal;
}

int insertarInicio(Listaenc* lista,EstructuraSucursales * sucursal)
{
    if(lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    ListaSucursales *nuevoNodo = crearSucur(sucursal,lista->inicio);
    if(nuevoNodo == NULL)
        ESTRUCTURA_NO_INICIALIZADA;
    lista->inicio = nuevoNodo;
    lista->tam++;
    return OK;
}

int insertar(Listaenc* lista,EstructuraSucursales * sucursal, int pos)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (pos < 0 || pos > lista->tam)
        return INDICE_INVALIDO;

    ListaSucursales *novoNo;
    if (pos == 0)
    {
        return insertarInicio(lista, sucursal);
    }
    else
    {
        // prepara para inserir
        ListaSucursales *aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++)
        {
            aux = aux->siguiente;
        }

        // adiciona o nó
        novoNo = novoNo = crearSucur(sucursal, aux->siguiente);
        if (novoNo == NULL)
            return ESTRUCTURA_NO_INICIALIZADA;
        aux->siguiente = novoNo;
    }
    lista->tam++;
    return OK;
}

int removerInicio(Listaenc* lista, EstructuraSucursales * sucursal)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;
    ListaSucursales *aux = lista->inicio;
    if (sucursal != NULL)
        sucursal = aux->sucursales;
    lista->inicio = aux->siguiente;
    delete aux;
    aux = NULL;
    lista->tam--;
    return OK;

}

int remover(Listaenc* lista, EstructuraSucursales * sucursal, int pos)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    ListaSucursales *ant, *atual;
    if (pos == 0)
    {
        return removerInicio(lista, sucursal);
    }
    else
    {
        // prepara para remover
        ant = NULL;
        atual = lista->inicio;
        for(int i = 0; i < pos; i++)
        {
            ant = atual;
            atual = atual->siguiente;
        }

        // remove o nó atual
        ant->siguiente = atual->siguiente;
        if (sucursal != NULL)
            sucursal = atual->sucursales;
        delete atual;
        atual = NULL;
    }
    lista->tam--;
    return OK;
}

int obtenerElemento(Listaenc* lista, EstructuraSucursales** sucursal, int pos)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;

    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    if (sucursal== NULL)
        return PARAMETRO_INVALIDO;


    ListaSucursales *aux;
    aux = lista->inicio;
    for(int i = 0; i < pos; i++)
    {
        aux = aux->siguiente;
    }
    *sucursal = aux->sucursales;

    return OK;
}

int obtenerTamanio(Listaenc* lista, int* tam)
{
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (tam == NULL)
        return PARAMETRO_INVALIDO;
    *tam = lista->tam;
    return OK;
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

