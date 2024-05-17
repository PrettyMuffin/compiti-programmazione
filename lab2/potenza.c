#include <stdio.h>

/*
    Conversione da decimale a base k di numeri positivi.
 */

#define BASE 2

/*
    PRE:
    POST: restituisce un numero x le cui cifre rappresentano la codifica in base
   k di n
*/
unsigned int dec2base_k(unsigned int n);

int main() {

  unsigned int n;
  scanf("%ud", &n);

  printf("%u corrisponde a %u in base %d\n", n, dec2base_k(n), BASE);
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

unsigned int dec2base_k(unsigned int n) {
  unsigned int ris = 0;
  for (int i = 0; n > 0; i++) {
    ris += (n % BASE) * potenza(10, i);
    n /= BASE;
  }
  return ris;
}
