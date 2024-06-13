#include "lib/lista.h"
#include <stdlib.h>
#include <stdio.h>

/*In questo esercizio lavoreremo su liste normali e liste doppiamente linkate. A differenza delle liste su cui avete lavorato fino ad adesso,
che hanno solo un puntatore al nodo successivo, le liste doppiamente linkate hanno anche un puntatore al nodo precendente.
Vi viene data la struttura nodoD che corrisponde ad un nodo di una lista doppiamente linkata e una funzione insert_dlist per inserire un dopo
in una posizione generica di una lista doppiamente linkata.

Vi chiediamo di scrivere 3 funzioni per le liste doppiamente linkate:
1- reverse_dlist, che inverte la posizione dei nodi della lista originale
2- print_forward, per stampare la lista dal primo nodo all'ultimo
3- print_backward, per stampare la lista dall' ultimo nodo al primo

Inoltre, vi chiediamo di scrivere 1 funzione per le liste normali:
1- reverse_list, che inverte la posizione dei nodi della lista originale

Le PRE e POST delle funzioni, così come le loro firme, sono riportate nel codice e devono essere rispettate.
Attenzione: le stampe hanno tutte uno spazio dopo un numero, anche quello finale.*/

// Lista doppiamente linkata: un puntatore al nodo successivo e uno a quello precedente
struct nodoD
{
    int info;
    struct nodoD *prev;
    struct nodoD *next;
};

// PRE: first e last sono riferimenti ai puntatori iniziali e finali di una DList, pos una posizione valida (0..lung -1)
void insert_dlist(struct nodoD **first, struct nodoD **last, int pos, int info)
{
    if (pos == 0)
    {
        struct nodoD *tmp = malloc(sizeof(struct nodoD));
        tmp->info = info;
        tmp->prev = NULL;
        tmp->next = *first;
        if (*first != NULL)
        {
            (*first)->prev = tmp;
        }
        else
            *last = tmp;
        *first = tmp;
    }
    else
    {
        insert_dlist(&((*first)->next), last, pos - 1, info);
        (*first)->next->prev = (*first);
    }
}
// POST: inserisce un nuovo nodo in posizione pos con campo dati == info

// POST: stampa la DList dato il puntatore al nodo iniziale first
void print_forward(struct nodoD *first)
{
    if (first == NULL)
    {
        printf("Vuota\n");
        return;
    }
    struct nodoD *inizioLista = first;
    for (; first != NULL;)
    {
        printf("%d ", first->info);
        first = first->next;
    }
    printf("\n");
}

// POST: stampa la DList al contrario dato il puntatore all'ultimo elemento
void print_backward(struct nodoD *last)
{
    if (last == NULL)
    {
        printf("Vuota\n");
        return;
    }
    struct nodoD *inizioLista = last;
    for (; last != NULL;)
    {
        printf("%d ", last->info);
        last = last->prev;
    }
    printf("\n");
}

// POST: scambia le info dei due nodi
void scambia_dlist(struct nodoD *a, struct nodoD *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

/*double linked vs single linked*/
// PRE: first e last sono riferimenti ai puntatori iniziali e finali di una DList
void reverse_dlist(struct nodoD **first, struct nodoD **last)
{
    if (*first == NULL || *last == NULL)
        return;
    // mi faccio delle strutture d'appoggio così non lavoro direttamente con i puntatori, evitando così di resettare i puntatori di first e last al loro valore iniziale
    struct nodoD *appoggio_first = *first;
    struct nodoD *appoggio_last = *last;

    while (appoggio_first != appoggio_last && appoggio_first->prev != appoggio_last && appoggio_last->next != appoggio_first)
    {
        scambia_dlist(appoggio_first, appoggio_last);
        appoggio_first = appoggio_first->next;
        appoggio_last = appoggio_last->prev;
    }
}
// POST: la DList identificata da first e last è la lista originale ma al contrario
//  ESEMPIO: 1-2-4 diventa 4-2-1

// PRE: ptr è un riferimento al puntatori iniziale della lista normale
void reverse_list(struct nodo **ptr)
{
    if (*ptr == NULL)
        return;
    int last_index = lung(*ptr) - 1;
    for (int i = 0, j = last_index; i <= j; i++, j--)
    {
        int i_value = get(*ptr, i);
        int j_value = get(*ptr, j);
        modifica(ptr, i, j_value);
        modifica(ptr, j, i_value);
    }
}
// POST: l'ordine degli elementi della lista è stato invertito
//  ESEMPIO: 1-2-4 diventa 4-2-1

int main()
{
    struct nodoD *dlist_start = NULL;
    struct nodoD *dlist_end = NULL;

    struct nodo *list = NULL;

    int n_entries;
    scanf("%d", &n_entries);

    for (int i = 0; i < n_entries; i++)
    {
        pre_insert(&list, i);
        insert_dlist(&dlist_start, &dlist_end, 0, i);
    }

    // normale print, da libreria
    printf("Stampa Lista:\n");
    print_list(list);

    // print in un senso e nell'altro
    printf("Stampa DLista in avanti:\n");
    print_forward(dlist_start);
    printf("Stampa DLista all'indietro:\n");
    print_backward(dlist_end);

    // reversing
    reverse_list(&list);
    reverse_dlist(&dlist_start, &dlist_end);

    printf("Stampa Lista reversed:\n");
    print_list(list);

    // print in un senso e nell'altro
    printf("Stampa DLista reversed (entrambi i sensi):\n");
    print_forward(dlist_start);
    print_backward(dlist_end);
}