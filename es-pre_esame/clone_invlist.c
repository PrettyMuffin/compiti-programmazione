#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextNode;
};

typedef struct node Lista;

void stampa_lista(Lista *lista)
{
    while (lista != NULL)
    {
        printf("%d ", lista->value);
        lista = lista->nextNode;
    }
}

void pre_insert(Lista **lista, int value)
{
    Lista *nuovoNodo = *lista;
    *lista = malloc(sizeof(lista));
    (*lista)->value = value;
    (*lista)->nextNode = nuovoNodo;
}

void suff_insert(Lista **lista, int value)
{
    while (*lista != NULL)
    {
        lista = &((*lista)->nextNode);
    }
    pre_insert(lista, value);
}

void init_list(Lista **lista)
{
    *lista = NULL;
}

int is_empty(Lista **lista)
{
    return *lista == NULL;
}

void clone_invlist(Lista *srcLista, Lista **destLista)
{
    if (srcLista == NULL)
        return;
    clone_invlist(srcLista->nextNode, destLista);
    suff_insert(destLista, srcLista->value);
}

void rimuovi_el(int arr[], int pos, int *dim)
{
    for (int i = pos; i < *dim - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *dim -= 1;
}

void rimuovi_triple(int arr[], int *dim)
{
    for (int i = 1; i < *dim - 1; i++)
    {
        if (arr[i - 1] == arr[i] && arr[i] == arr[i + 1])
            rimuovi_el(arr, i, dim);
    }
}

int main(int argc, char const *argv[])
{
    Lista *lista;
    init_list(&lista);
    suff_insert(&lista, 4);
    suff_insert(&lista, 2);
    suff_insert(&lista, 8);
    suff_insert(&lista, 12);
    suff_insert(&lista, 9);
    suff_insert(&lista, 1);

    Lista *invlist;
    init_list(&invlist);
    clone_invlist(lista, &invlist);
    stampa_lista(invlist);

    printf("\n");
    int dim = 6;
    int arr[6] = {1, 1, 1, 2, 6, 5};
    rimuovi_triple(arr, &dim);
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
