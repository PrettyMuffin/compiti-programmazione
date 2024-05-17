#include <stdio.h>
#include <basic/array.h>

/*
 * Scrivete un programma che dato un array di interi positivi, calcoli quante
 * sono le occorrenze di ogni valore presente nell'array.
 * Notate che i valori dell'array, purché positivi,
 * possono essere grandi a piacere.
 * Il programma deve poi stampare quanto trovato, utilizzando il comando:
 * printf("il valore %d appare %d volte\n", A[i], freq[i]);
 *
 * Per esempio se l'array è [1,1,2,3,1,2] si ottiene il seguente output:
 * il valore 1 appare 3 volte
 * il valore 2 appare 2 volte
 * il valore 3 appare 1 volte
 *
 */

// Tutti gli elementi dell'array devono essere positivi
void occorrenze_array(int arr[], int dim, int ris[])
{
    if (dim == 1)
    {
        ris[0] = 1;
        return;
    }
    for (int i = 0; i < dim - 1; i++)
    {
        if (arr[i] > 0)
        {
            int counter = 1;
            for (int j = i + 1; j < dim; j++)
            {
                if (arr[i] == arr[j])
                {
                    counter += 1;
                    arr[j] = 0;
                }
            }
            ris[i] = counter;
        }
    }
}

int main()
{
    // Per testare più velocemente il vostro algoritmo potete
    // usare gli array sotto (modificandoli secondo le vostre necessità)
    // invece di leggerli da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.

    // int dim = 6;
    // int A[6] = {1, 2, 3, 1, 1, 3};

    // leggi array e dimensioni
    int dim;
    scanf("%d", &dim);

    int A[dim];
    // funzione libreria
    leggi_array(A, dim);

    // prosegui
    int freq[dim];
    occorrenze_array(A, dim, freq);

    for (int i = 0; i < dim; i++)
    {
        if (A[i] != 0)
            printf("il valore %d appare %d volte\n", A[i], freq[i]);
    }
}