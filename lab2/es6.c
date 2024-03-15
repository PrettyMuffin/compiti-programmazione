#include <stdio.h>

#define ALTEZZA 13

int main() {
  for (int i = 1; i <= ALTEZZA; i++) {
    for (int j = 1; j <= i; j++) {
      printf("#");
    }
    printf("\n");
  }
}
