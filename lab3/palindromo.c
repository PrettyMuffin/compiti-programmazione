#include <stdio.h>

/*
 * Dato un array di interi di lunghezza N, scrivere un programma che stampa
 * "Array palindromo" se l'array è palindromo o "Array non palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 *
 * Per questa l'implementazione ci rifaremo letteralmente alla
 * definizione data sopra: creeremo una funzione che
 * inverte un array ed una che confronta due array.
 * Realizzate le due funzioni secondo i prototipi forniti
 * ed infine usatele all'interno di una funzione
 * palindromo che realizzi la consegna.
 */

int confronta_array(int *X, int *Y, int dim);
void inverti(int *A, int dim);
void leggi_array(int *X, int dim);
int palindromo(int array[], int n);

int main()
{
    int N;
    // leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    // leggere da input dati array
    leggi_array(array, N);

    if (palindromo(array, N) == 1)
    {
        printf("Array palindromo\n");
    }
    else
        printf("Array non palindromo\n");
}

int palindromo(int array[], int n)
{
    int copia_array[n];
    for (int i = 0; i < n; i++)
    {
        copia_array[i] = array[i];
    }
    inverti(copia_array, n);
    return confronta_array(array, copia_array, n);
}

void inverti(int *A, int dim)
{
    int ultimo_indice = dim - 1;
    for (int i = 0; i < dim / 2; i++)
    {
        int temp = A[i];
        A[i] = A[ultimo_indice - i];
        A[ultimo_indice - i] = temp;
    }
}

int confronta_array(int *x, int *y, int dim)
{
    if (dim <= 0)
        return 1;

    for (int i = 0; i <= dim / 2; i++)
    {
        if (x[i] != y[i] || x[(dim - 1) - i] != y[(dim - 1) - i])
            return 0;
    }
    return 1;
}

void leggi_array(int *X, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", X + i);
    }
}