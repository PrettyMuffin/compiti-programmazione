#include <stdio.h>

/*
Scrivere un programma che, dato un intero n >= 0 e un numero primo p > 1,
restituisca il numero n diviso per p^e (p elevato alla potenza e) dove e è la
potenza con cui p compare nella scomposizione in fattori primi di n. Se p non
compare nella scomposizione in fattori primi di n allora restituire n / (p^0) =
n

Esempi:
- se n = (2^3) * 5 = 40 e p = 2, il programma deve restituire 5
- se n = (2^3) * 5 = 40 e p = 5, il programma deve restituire 8
- se n = (2^3) * 5 = 40 e p = 7, il programma deve restituire 40
*/

// Pre: n intero >= 0, p intero primo > 1
// Post: restituisce l'esponente e massimo per cui p^e divide n. Se p non divide
// n ritorna 0.
int fattore_primo(int n, int p);

// PRE: n>= 0, p > 1
// POST: ritorna l'esponente di un numero primo all'intero di un numero
int esponente_fattore_primo(int n, int p);

// da es 1 lab 2
int potenza(int base, int esponente);

int main(void) {
  int n;
  int p;
  scanf("%d %d", &n, &p);

  // INSERITE QUI SOTTO IL VOSTRO CODICE (non modificate le righe sopra)
  int res = esponente_fattore_primo(n, p);

  // INSERITE QUI SOPRA IL VOSTRO CODICE (non modificate le righe sotto)

  printf("%d\n", res);
}

int esponente_fattore_primo(int n, int p) {
  int e = fattore_primo(n, p);
  return n / potenza(p, e);
}

int fattore_primo(int n, int p) {
  int e = 0;

  while (n % p == 0 && n != 1) {
    e++;
    n /= p;
  }

  return e;
}

int potenza(int base, int esponente) {
  if (esponente == 0) {
    return 1;
  }
  if (esponente == 1) {
    return base;
  }

  int res = base;

  while (esponente > 1) {
    res *= base;
    esponente--;
  }

  return res;
}
