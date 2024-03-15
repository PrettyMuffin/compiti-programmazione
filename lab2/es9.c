#include <stdio.h>

#define LIMITE 56

int main() {
  int n = 1;
  printf("0\n1\n");
  while (n < LIMITE) {
    n = (n - 1) + (n - 2);
    printf("%d", n);
  }
}
