#include <stdio.h>

/*
Scrivere un programma che calcoli il minimo comune multiplo tra tre numeri n1,
n2, n3 > 0. Il minimo comune multiplo può essere ottenuto facendo la
scomposizione in fattori primi dei tre numeri e poi moltiplicando tra loro tutti
i fattori dei tre numeri, sia quelli comuni che quelli non comuni.

Attenzione:
1) Ogni fattore deve essere moltiplicato dopo essere stato elevato al massimo
esponente apparso nella scomposizione in fattori primi. Per esempio: se
n1=6=2*3, n2=12=2*2*3 e n3=24=2*2*2*3 allora il fattore 2 deve essere
moltiplicato elevato alla terza potenza (2*2*2). 2) Ogni fattore comune va
moltiplicato una sola volta, nell'esempio precedente il fattore 2 va prima
elevato alla terza potenza e poi moltiplicato una unica volta per raggiungere il
risultato.

Il programma dovrà leggere i tre numeri n1, n2 e n3 come input da terminale
Per testare il programma inserite i tre valori, separati da spazio, e poi
premete Invio
*/

// Restituisce l'esponente e massimo per cui f^e divide n. Se f non divide n
// ritorna 0 Pre: n >=0, f > 1
int fattore_primo(int n, int f);

// Se il numero n è primo ritorna 1 (true), altrimenti ritorna 0 (false)
// Pre: n > 0
int verifica_primo(int n);

// Restituisce il valore massimo tra n1, n2, n3
int max(int n1, int n2, int n3);

// Restituisce il numero "base" elevato alla potenza indicata da "esponente"
// Pre: esponente >= 0
int potenza(int base, int esponente);

// Restituisce il minimo comune multiplo tra i numeri n1, n2, n3
int mcm(int n1, int n2, int n3);

int main() {
  // Non serve modificare questo main, concentratevi sulla definizione delle
  // funzioni che mancano
  int n1 = 18, n2 = 4, n3 = 9;
  // scanf("%d %d %d", &n1, &n2, &n3);

  int res = mcm(n1, n2, n3);
  printf("%d\n", res);
}

int mcm(int n1, int n2, int n3) {
  int result_mcm = 1;
  for (int i = 2; i <= max(n1, n2, n3); i++) {
    int esp_n1 = fattore_primo(n1, i);
    int esp_n2 = fattore_primo(n2, i);
    int esp_n3 = fattore_primo(n3, i);
    if (verifica_primo(i) && (esp_n1 != 0 || esp_n2 != 0 || esp_n3 != 0)) {
      int max_e = max(esp_n1, esp_n2, esp_n3);
      result_mcm *= potenza(i, max_e);
    }
  }
  return result_mcm;
}

int fattore_primo(int n, int f) {
  int e = 0;
  while (n % f == 0) {
    e++;
    n /= f;
  }
  return e;
}

// Ritorna il massimo tra i due numeri
int max_tra_due_numeri(int n1, int n2) { return n1 > n2 ? n1 : n2; }

int max(int n1, int n2, int n3) {
  int max = max_tra_due_numeri(n1, max_tra_due_numeri(n2, n3));
  return max;
}

int verifica_primo(int n) {
  int primo = 1;

  if (n > 1) {
    int f = 2;
    while (f < n && primo) {
      if (n % f == 0)
        primo = 0;
      f++;
    }
  }

  return primo;
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
