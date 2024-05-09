#include <stdio.h>

/*
    Funzione che inverte i valori di un array
 */

/*
    PRE: L'array A ha dimensione dim
    POST: array invertito
*/
void inverti(int *A, int dim);
void stampa_array(int *A, int dim);
void leggi_array(int *X, int dim);

/*
    PRE: x, y puntatori a variabili da scambiare
    POST: y = x, x = y
*/
void scambia(int *x, int *y);

int main(void)
{

    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);

    inverti(A, dim);
    stampa_array(A, dim);
}

void inverti(int *A, int dim)
{
    int ultimo_indice = dim - 1;
    for (int i = 0; i < dim / 2; i++)
    {
        scambia(&A[i], &A[ultimo_indice - i]);
    }
}

void scambia(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void stampa_array(int *A, int dim)
{

    printf("[");
    for (int i = 0; i < dim; i += 1)
        printf(" %d", A[i]);
    printf(" ]\n");
}

void leggi_array(int *X, int dim)
{
    for (int i = 0; i < dim; i += 1)
        scanf("%d", &X[i]);
}