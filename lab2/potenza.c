#include <stdio.h>

int potenza(int base, int esponente);

int main() {
  int base, esp;

  scanf("%d %d", &base, &esp);

  printf("%d\n", potenza(base, esp));
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
