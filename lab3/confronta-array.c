#include <stdio.h>
#include <assert.h>

/*
    funzione che controlla se due array con lo stesso numero di elementi sono uguali.
*/

/*
    pre: x e y sono due array di interi con dim elementi
    post: restituisce   1 se per 0<=i<dim. x[i]=y[i]
                        0 altrimenti
*/
int confronta_array(int *x, int *y, int dim);
void consegna_moodle();

/*
    pre: x punta ad un array di dim elementi
    post: x riempito con valori letti da tastiera
*/
void leggi_array(int *x, int dim);
void test_confronta_array();

int main(void)
{
    // test_confronta_array();
    consegna_moodle();
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

void leggi_array(int *x, int dim)
{

    for (int i = 0; i < dim; i += 1)
    {
        scanf("%d", &x[i]);
    }
}

void test_confronta_array()
{

    int x[] = {1, 2, 3, 4};
    int y[] = {1, 2, 3, 4};
    assert(confronta_array(x, y, 4) == 1);

    int y2[] = {1, 3, 2, 4};
    assert(confronta_array(x, y2, 4) == 0);

    int y3[] = {1, 2, 3, 1};
    assert(confronta_array(x, y3, 4) == 0);

    int y4[] = {2, 2, 3, 4};
    assert(confronta_array(x, y4, 4) == 0);

    int x2[] = {};
    int y5[] = {};
    assert(confronta_array(x2, y5, 0) == 1);

    printf("tutti i test superati con successo!\n");
}

void consegna_moodle()
{

    int dim;
    scanf("%d", &dim);
    int a[dim], b[dim];
    leggi_array(a, dim);
    leggi_array(b, dim);

    if (confronta_array(a, b, dim) == 1)
        printf("Gli array sono uguali\n");
    else
        printf("Gli array non sono uguali\n");
}