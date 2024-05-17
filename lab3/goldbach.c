#include <stdio.h>

/*
    Dato un N, controllare se la congettura di Golbach è verificata per ogni n<=N.
*/

/*
    PRE: n>2 e pari
    POST: restituisce 0 se la congettura di Goldbach vale per ogni i. 2<i<=n
                      k se la congettura di Goldbach non è verificata per k
*/
int golbach_sequenza(int n);

/*
    PRE:
    POST: restituisce 1 se n è primo, 0 altrimenti
*/
int verifica_primo(int n);

/*
    PRE: n>2 e pari,
         a e b devono essere puntatori inizializzati a variabili. Il cui scopo
         è quello di contenere i valori dei due
         numeri primi la cui somma è n.
    POST: Restituisce   1 se esiste (x,y).x+y=n, x e y sono primi;
                        0 altrimenti
*/
int goldbach_singolo(int n, int *a, int *b); // COMPLETATE VOI LA LISTA DEI PARAMETRI

/*
    PRE:
    POST restituisce 1 se n > 2 e pari
                     0 altrimenti
*/
int verifica_input(int n);

int main()
{

    int N, res;

    scanf("%d", &N);
    if (!verifica_input(N))
        printf("Errore: la congettura di Goldbach è definita per interi pari e maggiori di 2, ricevuto %d\n", N);

    res = golbach_sequenza(N);
    if (res == 0)
        printf("Congettura di Goldbach verificata fino a %d\n", N);
    else
        printf("Congettura di Goldbach non verificata per %d\n", res);
}

int verifica_input(int n)
{
    return n > 2 && n % 2 == 0;
}

int golbach_sequenza(int n)
{
    for (int i = 4; i <= n; i += 2)
    {
        int a = 0, b = 0;
        if (!goldbach_singolo(i, &a, &b))
            return i;
        else
            printf("%d=%d+%d\n", i, a, b);
    }
    return 0;
}

int goldbach_singolo(int n, int *a, int *b)
{
    for (int i = 2; i < n / 2; i++)
    {
        int secondo_primo = n - i;
        if (verifica_primo(i) && verifica_primo(secondo_primo))
        {
            *a = i;
            *b = secondo_primo;
            return 1;
        }
    }
    return 0;
}

int verifica_primo(int n)
{
    int primo = 1;

    if (n <= 1)
        return primo;

    int f = 2;
    while (f < n && primo)
    {
        if (n % f == 0)
            primo = 0;
        f++;
    }

    return primo;
}