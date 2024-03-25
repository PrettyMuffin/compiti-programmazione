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
  int n_convertitio = potenza(10, fattore_primo(n, BASE));
  int inizioCilco = fattore_primo(n, BASE);
  for (int i = inizioCilco - 1; i > 0; i--) {
    n /= 2;
    if (n % BASE != 0) {
      int operatore = potenza(10, i);
      n_convertitio += operatore;
    }
  }
  return n_convertitio;
}

// importata dall'eserccizio del fattore primo ma modificata un po'
int fattore_primo(int n, int f) {
  int e = 0;

  while (n > 1) {
    e++;
    n /= f;
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
