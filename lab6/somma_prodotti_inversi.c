#include <stdio.h>
#include <basic/array.h>

/*
    Scrivere una funzione che, dato un array A di dim interi, calcoli la somma dei prodotti tra il primo e l'ultimo elemento dell'array, tra il secondo ed il penultimo ecc...
    Per esempio, dato l'array [1,2,3,4,5,6] la funzione calcola 1*6+2*5+3*4. Se l'array è dispari, l'elemento centrale va moltiplicato con sè stesso.
    Il tipo restituito dalla funzione è void, però deve essere possibile stampare nel main la somma calcolata.
*/

// PRE: dim >= 0
void somma_prodotti_inversi(int array[], int dim, int *somma)
{
    *somma = 0;
    if (dim == 0)
    {
        return;
    }
    int opposite_index = dim - 1;
    for (int i = 0; i <= opposite_index; i++)
    {
        *somma += array[i] * array[opposite_index];
        opposite_index -= 1;
    }
}

int main(void)
{

    /* Per velocizzare i vostri test potete usare le seguenti istruzioni*/

    // int dim = 7;
    // int A[] = {1, 2, 3, 4, 5, 6, 7};

    /* Da commentare se si usano le istruzioni precedenti, necessarie per
       la consegna su Moodle*/

    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);

    int somma;

    // inserire la chiamata di funzione e la stampa di somma
    somma_prodotti_inversi(A, dim, &somma);
    printf("%d", somma);
}