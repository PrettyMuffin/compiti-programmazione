#include <stdio.h>

/*
    Trova tutti i numeri perfetti dati due estremi compresi.
*/

int isNumeroPerfetto(int numero);

int main(void) {
  // Le prossime righe di codice implementano il meccanismo di lettura dei
  // limiti da terminale Quando eseguite il programma potete scrivere questi due
  // valori, separati da spazio, e poi premere Invio per eseguire.
  int limite_inferiore, limite_superiore;
  scanf("%d %d", &limite_inferiore, &limite_superiore);

  // INSERITE IL VOSTRO CODICE A PARTIRE DA QUI
  for (int i = limite_inferiore; i <= limite_superiore; i++) {
    if (isNumeroPerfetto(i)) {
      printf("Numero %d perfetto\n", i);
    }
  }
}

/**
 * PRE: numero intero > 0
 * POST: ritorna 1 se è numero perfetto, ritorna 0 se non lo è
 */
int isNumeroPerfetto(int numero) {
  // questo controllo per poter assegnare la somma ad 1 e risparmiare 1
  // iterazione del ciclo for
  if (numero == 1) {
    return 0;
  }
  int sum = 1;
  for (int i = 2; i <= numero / 2; i++) {
    if (numero % i == 0) {
      sum += i;
    }
  }
  return sum == numero;
}
