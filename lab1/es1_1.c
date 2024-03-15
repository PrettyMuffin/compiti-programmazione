#include <stdio.h>

int main() {
  int x = 15, y = 7, z = 18;
  printf("Il minore dei tre valori è:\n");
  if (x < y) {
    if (x < z)
      printf("x");
    else
      printf("z");
  } else {
    if (y < z)
      printf("y");
    else
      printf("z");
  }
}
