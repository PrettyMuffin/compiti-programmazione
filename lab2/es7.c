#include <stdio.h>

int main() {
  int x = 63;
  int isPrimo = 1;

  for (int i = 2; i < 63; i++) {
    if (x % i == 0) {
      printf("Il numero %d è divisibile per %d\n", x, i);
      isPrimo = 0;
    }
  }
  if (isPrimo)
    printf("Il numero %d è primo\n");
}
