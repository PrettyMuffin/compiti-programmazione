/*
 * Implementare l'algoritmo di quick sort per ordinare un array di interi.
 * Quick Sort è un algoritmo divide-et-impera che divide iterativamente
 * l'array di input in due sottoarray rispetto ad un elemento detto pivot.
 * Tale procedura ricorsiva viene chiamata partition: scelto il pivot si pongono a sinistra
 * tutti gli elementi minori e a destra tutti i maggiori formando così i due sottoarray.
 * L'operazione viene reiterata ricorsivamente sui sottoarray fino all'ordinamento completo.
 *
 * Potete trovare una spiegazione più dettagliata al seguente link: https://ifif.altervista.org/quicksort-come-funziona-esempio/
 *
 * Stampare l'array ordinato usando la funzione stampa_array in libreria.
 */

#include <stdio.h>
#include <stdlib.h>
// #include "basic/array.h"

void stampa_array(int *A, int dim)
{
    printf("[");
    if (A != NULL & dim > 0)
    {
        printf("%d", A[0]);
    }
    for (int i = 1; i < dim; i++)
    {
        printf(",%d", A[i]);
    }
    printf("]");
}

void leggi_array(int *A, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", A + i);
    }
}

void scambia(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partizione_array(int array[], int start, int pivot)
{
    int el_pivot = array[pivot];
    int index_new_pivot = start;
    for (int i = start + 1; i < pivot - 1; i++)
    {
        if (array[i] <= el_pivot)
        {
            scambia(&array[i], &array[index_new_pivot]);
            index_new_pivot += 1;
        }
    }
    scambia(&array[index_new_pivot], &array[pivot]);
    return index_new_pivot;
}

int partizione_array_random(int array[], int start, int pivot)
{
    int random_index = rand() % pivot + start; // random da start a pivot
    scambia(&array[random_index], &array[pivot]);
    return partizione_array(array, start, pivot);
}

void random_quick_sort(int a[], int start, int pivot)
{
    if (start < pivot)
    {
        int new_pivot = partizione_array(a, start, pivot);
        random_quick_sort(a, start, new_pivot - 1);
        random_quick_sort(a, new_pivot + 1, pivot);
    }
}

int main(void)
{

    /* Per velocizzare i vostri test potete usare le seguenti istruzioni*/
    int size = 8;
    int A[8] = {5, 8, 7, 2, 4, 0, 9, 6};

    /* Da commentare se si usano le istruzioni precedenti, necessarie per
       la consegna su Moodle*/
    // int size;
    // scanf("%d", &size);
    // int A[size];
    // leggi_array(A, size);

    // ordina array
    random_quick_sort(A, 0, size - 1);
    // stampa array
    stampa_array(A, size);
}