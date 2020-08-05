#include <stdio.h>
#include <stdlib.h>
// #include <assert.h>
#include "lista_ligada_lib.h"


void inicializar_lista(Lista* lista) 
{
    lista->inicio = NULL;
}


void insere_lista_final(Lista* lista, Item item) 
{
    PtrNodo iterador = lista->inicio;

    if (lista->inicio == NULL) 
    {
        lista->inicio = (PtrNodo) malloc(sizeof(Nodo));
        lista->inicio->item = item;
        lista->inicio->proximo = NULL;
        return;

    }

    while (iterador->proximo != NULL) 
    {
        iterador = iterador->proximo;
    }

    iterador->proximo = (PtrNodo) malloc(sizeof(Nodo));
    iterador = iterador->proximo;

    iterador->item = item;
    iterador->proximo = NULL;
}


void insere_lista_inicio(Lista* lista, Item item)
{
    PtrNodo novo_nodo;

    if (lista->inicio == NULL) 
    {
        lista->inicio = (PtrNodo) malloc(sizeof(Nodo));
        lista->inicio->item = item;
        lista->inicio->proximo = NULL;
        return;
    }

    novo_nodo = (PtrNodo) malloc(sizeof(Nodo));

    novo_nodo->item = item;
    novo_nodo->proximo = lista->inicio;
    lista->inicio = novo_nodo;
}


void printar_lista(Lista* lista)
{
    PtrNodo iterador = lista->inicio;

    printf("Lista: \'");

    while (iterador != NULL)
    {
        printf(" %d", iterador->item);
        iterador = iterador->proximo;
    }
    
    printf(" \'\n");
}


int remove_lista(Lista* lista, Item item)
{
    PtrNodo nodo_anterior = NULL;
    PtrNodo nodo_a_remover;
    PtrNodo nodo_atual = lista->inicio;

    while (nodo_atual != NULL)
    {
        if (nodo_atual->item == item) 
        {
            if (nodo_anterior == NULL) 
            {
                nodo_a_remover = lista->inicio;
                lista->inicio = lista->inicio->proximo;
            } else
            {
                nodo_a_remover = nodo_atual;
                nodo_anterior->proximo = nodo_atual->proximo;
            }

            free(nodo_a_remover);

            return 1;
        }

        nodo_anterior = nodo_atual;
        nodo_atual = nodo_atual->proximo;
    }

    return 0;    
}


int remove_lista_final(Lista* lista)
{
    PtrNodo nodo_atual = lista->inicio;
    PtrNodo nodo_anterior = NULL;

    if (lista->inicio == NULL)
    {
        return 0;
    }
    
    while (nodo_atual->proximo != NULL)
    {
        nodo_anterior = nodo_atual;
        nodo_atual = nodo_atual->proximo;
    }

    if (nodo_anterior == NULL)
    {
        free(lista->inicio);
        lista->inicio = NULL;
    } else
    {
        free(nodo_atual);
        nodo_anterior->proximo = NULL;
    }

    return 1;
}


int remove_lista_inicio(Lista* lista)
{
    PtrNodo nodo_a_remover;

    if (lista->inicio == NULL)
    {
        return 0;
    }

    nodo_a_remover = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    
    free(nodo_a_remover);

    return 1;
}


int tamanho_lista(Lista* lista)
{
    PtrNodo iterador = lista->inicio;
    int acumulador = 0;

    while (iterador != NULL)
    {
        acumulador += 1;
        iterador = iterador->proximo;
    }
    
    return acumulador;
}

int lista_vazia(Lista* lista)
{
    return (lista->inicio == NULL);
}


int busca_lista_elem(Lista* lista, Item item)
{
    PtrNodo iterador = lista->inicio;

    while (iterador != NULL)
    {
        if (iterador->item == item)
        {
            return 1;
        }

        iterador = iterador->proximo;
    }

    return 0;
}


int busca_lista_pos(Lista* lista, Item item)
{
    PtrNodo iterador = lista->inicio;
    int indice = 0;

    while (iterador != NULL)
    {
        if (iterador->item == item)
        {
            return indice;
        }

        iterador = iterador->proximo;
        indice += 1;
    }

    return -1;
}