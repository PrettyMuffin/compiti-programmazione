#include <stdio.h>

int main() {
  int n1 = 1, n2 = 10;

  for (int i = n1; i <= n2; i++) {
    for (int j = 1; j <= 10; j++) {
      printf("%d ", i * j);
    }
    printf("\n");
  }
}
