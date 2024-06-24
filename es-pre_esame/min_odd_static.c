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

Lista *first_odd(Lista *lista)
{
    static Lista *min = NULL;
    if (is_empty(&lista))
        return min;
    else if (min == NULL || (lista->value % 2 != 0 && lista->value < min->value))
    {
        min = lista;
        return first_odd(lista->nextNode);
    }
    return first_odd(lista->nextNode);
}

int main()
{
    Lista *lista;
    init_list(&lista);
    suff_insert(&lista, 4);
    suff_insert(&lista, 3);
    suff_insert(&lista, 6);
    suff_insert(&lista, 1);
    suff_insert(&lista, 2);
    Lista *min_node = first_odd(lista);
    printf("Il nodo con il valore minimo è: %d", min_node->value);
}