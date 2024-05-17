#include <stdio.h>

#define ALTEZZA 9

int main() {
  for (int i = 0; i <= ALTEZZA; i++) {
    for (int j = 0; j <= (2 * ALTEZZA) - 1; j++) {
      if (j <= ((2 * ALTEZZA) - 2) - i && j >= i)
        printf("#");
      else
        printf(" ");
    }
    printf("\n");
  }
}
