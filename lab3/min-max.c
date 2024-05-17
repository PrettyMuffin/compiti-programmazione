#include <stdio.h>
#include <assert.h>

/*
    Scrivete una funzione che trovi il minimo ed il massimo
    di una lista di interi non vuota.
*/

void min_max(int *A, int dim, int *i, int *j);
void consegna_moodle();
void test_min_max();

int main(void)
{

    // test_min_max();
    consegna_moodle();
}

void min_max(int *A, int dim, int *i, int *j)
{
    if (dim <= 0)
    {
        *i = -1;
        *j = -1;
        return;
    }

    int min = A[0];
    int max = A[0];
    *i = 0;
    *j = 0;

    for (int k = 0; k < dim; k++)
    {
        if (A[k] < min)
        {
            *i = k;
            min = A[k];
        }
        else if (A[k] >= max)
        {
            *j = k;
            max = A[k];
        }
    }
}

void consegna_moodle()
{

    int N;
    scanf("%d", &N);
    int array[N];
    for (int i = 0; i < N; i += 1)
    {
        scanf("%d", array + i);
    }

    int min_indice, max_indice;

    // INVOCATE DI SEG == 3UITO LA FUNZIONE min_max() CORRETTAMENTE
    min_max(array, N, &min_indice, &max_indice);

    printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]);
    printf("valore massimo: array[%d] -> %d\n", max_indice, array[max_indice]);
}

void test_min_max()
{

    int i, j;
    int a[] = {3, 5, 1, 7, 0, 9, 4, 6, 2, 8};
    min_max(a, 10, &i, &j);
    assert((i == 4) && (j == 5));

    int b[] = {3, 5, 1, 0, 3, 1, 0, 9, 2, 8};
    min_max(b, 10, &i, &j);
    assert((i == 3) && (j == 7));

    int c[] = {3, 5, 1, 0, 3, 9, 3, 9, 2, 8};
    min_max(c, 10, &i, &j);
    assert((i == 3) && (j == 7));

    int d[] = {1, 2, 3, 4, 5, 6, 7};
    min_max(d, 7, &i, &j);
    assert((i == 0) && (j == 6));

    int e[] = {};
    min_max(e, 0, &i, &j);
    assert((i == -1) && (j == -1));

    int f[] = {7, 6, 5, 4, 3};
    min_max(f, 5, &i, &j);
    assert((i == 4) && (j == 0));

    int g[] = {3, 3, 3, 3};
    min_max(g, 4, &i, &j);
    assert((i == 0) && (j == 3));

    int h[] = {1};
    min_max(g, 1, &i, &j);
    assert((i == 0) && (j == 0));

    printf("min_max: tutti i test passati con successo\n");
}