#include <stdio.h>

/*
Definire una funzione void stampa_piramide(int spazio, int altezza); che stampi
una piramide di altezza uguale ad "altezza" con uno spazio iniziale uguale a
"spazio" (nota: assumiamo "altezza", "spazio" >= 0).

Per esempio l'invocazione stampa_piramide(0, 3) deve stampare:
  #
 ###
#####
invece, l'invocazione stampa_piramide(4, 3) deve stampare:
      #
     ###
    #####

Usare la funzione stampa_piramide per definire una funzione void
stampa_albero_di_natale(int n_piramidi) che stampi un albero di natale composto
da n_piramidi piramidi allineate verticalmente (assumiamo n_piramidi >= 0). La
piramide sulla "punta" dell'albero deve avere altezza 3, la piramide subito
sotto deve avere altezza 4 e così via, aumentando ad ogni passo l'altezza di 1.

Attenzione: le tre piramidi devono essere tutte allineate al centro (cioè la
punta di una piramide deve essere a metà della base della piramide subito
sopra).

Per esempio: un albero di natale con n_piramidi = 3 avrà questo aspetto finale:
    #
   ###
  #####
    #
   ###
  #####
 #######
    #
   ###
  #####
 #######
#########

Per la consegna usare n_piramidi = 5
*/

// PRE: spazio, altezza >= 0
void stampa_piramide(int spazio, int altezza);

// PRE: n_piramidi >= 0
void stampa_albero_di_natale(int n_piramidi);

// PRE: spazio >= 1
void stampa_spazio(int spazio);

#define ALTEZZA_PUNTA_ALBERO 3

int main() { stampa_albero_di_natale(5); }

void stampa_albero_di_natale(int n_piramidi) {
  for (int i = 0; i < n_piramidi; i++) {
    // tolgo 1 allo spazio perché la consegna chiede che lo spazio della
    // piramide corrente sia il numero della piramide corrente - 1
    stampa_piramide(n_piramidi - i - 1, ALTEZZA_PUNTA_ALBERO + i);
  }
}

void stampa_spazio(int spazio) {
  for (int i = 1; i <= spazio; i++) {
    printf(" ");
  }
}

void stampa_piramide(int spazio, int altezza) {
  // comincio da altezza - 1 perché altrimenti stamperebbe una linea vuota,
  // in quanto al condizione di j >= i dentro al secondo for non sarebbe mai
  // vera
  for (int i = altezza - 1; i >= 0; i--) {
    stampa_spazio(spazio);
    for (int j = 0; j <= (2 * altezza) - 1; j++) {
      // if (j <= ((2 * altezza) - 2) - i && j >= i)
      //   printf("#");
      if (j <= ((2 * altezza) - 2) - i && j >= i)
        printf("#");
      else
        printf(" ");
    }
    printf("\n");
  }
}
