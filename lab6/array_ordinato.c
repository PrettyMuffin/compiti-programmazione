#include <stdio.h>
#include <assert.h>
#include "basic/array.h"

unsigned short ordinato(int A[], unsigned int size)
{
    if (size == 1)
        return 1;
    if (A[0] <= A[1])
        return ordinato(A + 1, size - 1);
    if (A[size - 1] <= A[size - 2])
        return ordinato(A + size - 2, size - 1);
    return 0;
}

void test_ordinato()
{

    int A[6] = {2, 2, 2, 3, 5, 8};
    int B[2] = {2, 0};
    int C[6] = {2, 5, 8, 6, 9, 12};
    int D[5] = {2, 2, 2, 2, 2};
    int E[7] = {9, 8, 6, 6, 6, 5, 2};
    int F[7] = {9, 8, 6, 9, 6, 5, 2};

    assert(ordinato(A, 6) == 1);
    assert(ordinato(B, 2) == 1);
    assert(ordinato(C, 6) == 0);
    assert(ordinato(D, 5) == 1);
    assert(ordinato(E, 7) == 1);
    assert(ordinato(F, 7) == 0);

    printf("funzione ordinato(): test passati con successo.\n");
}

void consegna_moodle()
{
    int dim;
    scanf("%d", &dim);
    int A[dim];
    leggi_array(A, dim);
}

int main(void)
{
    consegna_moodle();
    // test_ordinato();
}
