#include <stdio.h>

#define NUMERO_CASELLE 8
#define KI 5
#define KJ 7

int main() {
  int scambiaColore = 1; // variabile booleana che scambia colore ad ogni
                         // iterazione, 1 == bianco, 0 == nero

  for (int i = -1; i <= NUMERO_CASELLE; i++) {
    for (int j = -1; j <= NUMERO_CASELLE; j++) {
      if (i == -1 || i == NUMERO_CASELLE)
        printf("-");
      else if (j == -1 || j == NUMERO_CASELLE)
        printf("|");
      else if (i == KI && j == KJ) {
        printf("K");
      } else {
        char casella = scambiaColore ? ' ' : '#';
        printf("%c", casella);
      }
      scambiaColore = !scambiaColore;
    }
    scambiaColore = !scambiaColore;
    printf("\n");
  }
}
