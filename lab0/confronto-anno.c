#include <stdio.h>

int main() {
  int anno1 = 2021, mese1 = 6, giorno1 = 1;
  int anno2 = 2021, mese2 = 6, giorno2 = 7;
  if (anno1 > anno2 && mese1 > mese2 && giorno1 > giorno2) {
    printf("%d/%d/%d > %d/%d/%d", giorno1, mese1, anno1, giorno2, mese2, anno2);
  }
  printf("%d/%d/%d < %d/%d/%d", giorno1, mese1, anno1, giorno2, mese2, anno2);
}
