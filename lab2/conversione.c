#include <stdio.h>

/*
    Conversione da decimale a base k di numeri positivi.
 */

#define BASE 2

int fattore_primo(int n, int f);
/*
    PRE:
    POST: restituisce un numero x le cui cifre rappresentano la codifica in base
   k di n
*/
unsigned int dec2base_k(unsigned int n);
int potenza(int base, int esponente);

int main() {
  unsigned int n;
  scanf("%ud", &n);

  printf("%u corrisponde a %u in base %d\n", n, dec2base_k(n), BASE);
}

unsigned int dec2base_k(unsigned int n) {
  unsigned int n_covertito = 0;
  for (int i = 0; n_covertito > 0; i++) {
    n_covertito += (n % BASE) * potenza(10, i);
    n /= BASE;
  }
  return n_covertito;
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
