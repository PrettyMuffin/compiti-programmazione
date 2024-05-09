#include <stdio.h>

// Scrivere una funzione che stampi la frazione di numeri primi contenuti in un array

/*
Dato un array di interi di lunghezza N >= 0, scrivere un programma che stampi la frazione
di elementi dell'array che sono numeri primi.

Stampate il risultato fino a due valori decimali dopo la virgola usando il comando:
printf("Frazione numeri primi: %.2f\n", frazione);

Esempi:
* Se N = 10 e array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} stampa: "Frazione numeri primi: 0.50"
* Se N = 4 e array = {4, 6, 8, 9} stampa: "Frazione numeri primi: 0.00"
* Se N = 4 e array = {83, 1237, 11, 691} stampa: "Frazione numeri primi: 1.00"
* Se N = 0 e array = {} stampa: "Frazione numeri primi: 0.00" (attenzione a non dividere per 0)

Ricordate che, se volete ottenere un valore frazionario dividendo due interi, dovete prima fare
il casting a float di questi valori, per esempio, se x e y sono valori interi e vogliamo avere
la loro divisione con i valori decimali possiamo usare:

int x = 10;
int y = 3;
float f = (float)x / (float)y;

*/

// PRE: n è un intero >= 1
// POST: restituisce 1 se n è un numero primo, 0 altrimenti
int numeroPrimo(int n);

// PRE: array di interi, e la sua dimensione
// POST: resistuisce la frazione di numeri primi contenuta nell'array
float frazione_primi(int array[], int dim);

int main()
{
    /* Per comodità potete usare il codice sottostante
    invece che leggere gli input da tastiera.

    RICOMMENTATELO PRIMA DI CONSEGNARE
    */

    // const int N = 10;
    // int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* Se usate le istruzioni qui sopra commentate fino a INIZIO SOLUZIONE */

    int N;
    // leggere da input grandezza array
    scanf("%d", &N);

    int array[N];
    // leggere da input dati array
    for (int i = 0; i < N; i++)
    {
        scanf("%d", array + i);
    }

    // NOTA: ricordatevi che per ottenere un valore frazionario
    // quando si dividono interi bisogna prima fare il cast a float
    // dei valori interi, per esempio: f = (float)x / (float)y

    // INIZIO SOLUZIONE
    float frazione = frazione_primi(array, N);
    printf("Frazione numeri primi: %.2f\n", frazione);
}

float frazione_primi(int array[], int dim)
{
    if (dim <= 0)
        return 0;
    int contatore_primi = 0;

    for (int i = 0; i < dim; i++)
    {
        if (numeroPrimo(array[i]))
            contatore_primi += 1;
    }

    return (float)(contatore_primi) / (float)dim;
}

int numeroPrimo(int n)
{
    int primo = 1;

    if (n > 1)
    {
        int f = 2;
        while (f < n && primo)
        {
            if (n % f == 0)
                primo = 0;
            f++;
        }
    }

    return primo;
}