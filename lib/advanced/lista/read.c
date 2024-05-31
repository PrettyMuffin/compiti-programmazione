#include "../../lista.h"
#include <assert.h>

int isempty(struct nodo *ptr)
{
    return ptr == NULL ? 1 : 0;
}

void print_list(struct nodo *ptr)
{
    if (isempty(ptr) == 1)
    {
        printf("Vuota\n");
    }
    else
    {
        while (isempty(ptr) == 0)
        {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// PRE:  ptr è un puntatore ad una lista (possibilmente vuota)
int lung(struct nodo *ptr)
{
    int nodeCounter = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        nodeCounter++;
    }
    return nodeCounter;

    // RICORSIVO:
    // return (ptr == NULL) ? 0 : 1 + lung(ptr->next);
}
// POST: return il numero di&&  nodi
// NOTA: è un one-liner se usate la ricorsione

// PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
int get(struct nodo *ptr, int pos)
{
    assert(lung(ptr) >= pos && "Index out of range");
    while (pos > 0)
    {
        ptr = ptr->next;
        pos--;
    }
    return ptr->info;
}
// POST: return del campo info del nodo pos-esimo