#include <stdio.h>
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

//! pop in testa
// void pop(Lista **lista)
// {
//     if (is_empty(lista))
//     {
//         printf("Lista vuota, non c'è nulla da togliere\n");
//         return;
//     }
//     Lista *temp = (*lista)->nextNode;
//     free(*lista);
//     *lista = temp;
// }

//! pop in coda
void pop(Lista **lista)
{
    if (is_empty(lista))
    {
        printf("Lista vuota, non c'è nulla da togliere\n");
        return;
    }
    while ((*lista)->nextNode != NULL)
    {
        lista = &((*lista)->nextNode);
    }
    // Lista *temp = (*lista)->nextNode;
    free(*lista);
    // *lista = temp;
    *lista = NULL;
}

int main()
{
    Lista *mia_lista;
    init_list(&mia_lista);
    // pre_insert(&mia_lista, 34);
    suff_insert(&mia_lista, 14);
    suff_insert(&mia_lista, 18);
    suff_insert(&mia_lista, 34);
    pop(&mia_lista);
    pop(&mia_lista);
    pop(&mia_lista);
    stampa_lista(mia_lista);
}