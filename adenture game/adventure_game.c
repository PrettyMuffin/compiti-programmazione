#include <stdio.h>

/*
  Implementare un semplice adventure game testuale giocabile da terminale.
*/

/*
Questo esercizio chiede di implementare una semplice avventura testuale che può
essere giocata direttamente nel terminale. Il mondo dell'avventura è diviso in
stanze, il giocatore può muoversi da una stanza all'altra e compiere azioni
usando la tastiera. Per ogni stanza il gioco stampa sul terminale: 1) il nome
della stanza, per esempio Stanza 1, 2, 3 oppure qualche nome più creativo 2) una
descrizione della stanza: questa deve venire aggiornata in base alle azioni del
giocatore 3) una lista di azioni disponibili in quella stanza (per esempio:
"premi e per andare verso est")

Il loop che implementa il gioco può essere costruito in questo modo:

while (!vittoria) {
  stampa_stanza();
  char azione = leggi_input();
  agisci(azione);
}

Il gioco tiene traccia del suo stato di evoluzione (per esempio: in che stanza
si trova il giocatore?) con delle variabili globali.

La funzione stampa_stanza legge lo stato del gioco (le variabili globali) e
stampa le informazioni relative ("ti trovi nella stanza x e puoi fare y, z"). La
funzione leggi_input legge un singolo carattere da tastiera e lo restituisce. La
funzione agisci riceve in inputl'azione scelta dal giocatore, verifica se
l'azione scelta dal giocatore può essere compiuta nella stanza attuale e
modifica le variabili globali che rappresentano lo stato del gioco di
conseguenza.

Per esempio: il giocatore potrebbe avere bisogno di una chiave. Il fatto che
possegga o meno la chiave sarà deciso da una variabile globale int ha_chiave
(uguale a 1 se ha la chiave, 0 altrimenti). La funzione stampa_stanza leggerà la
variabile ha_chiave per decidere che opzioni mostrare al giocatore (per esempio
la possibilità di aprire la porta chiusa a chiave viene mostrata solo se il
giocatore ha la chiave). La funzione agisci potrà modificare il valore della
variabile ha_chiave, per esempio impostandolo a 1 quando il giocatore trova e
raccoglie la chiave.

Questo è uno spunto per una prima semplice versione del gioco, che potete
ampliare a piacimento: Il giocatore è intrappolato in una prigione, per uscire
deve sbloccare una porta chiusa a chiave.

Stanza 1:
Questa stanza ha una uscita verso OVEST che porta alla Stanza 2 e una uscita
verso EST che porta alla Stanza 3. Se il giocatore ha la CHIAVE, allora può
sbloccare la porta a SUD che conduce alla vittoria.

Stanza 2:
Questa stanza contiene un tavolo, con sopra una SPADA, che il giocatore può
raccogliere premendo "r". (Nota: se la spada è già stata raccolta la descrizione
della stanza lo deve notificare). L'uscita verso EST riporta alla Stanza 1.

Stanza 3:
Questa stanza contiene una uscita verso NORD che è però ostruita da fitte
ragnatele. Se il giocatore ha la SPADA (premendo "a") può tagliare le ragnatele
e liberare il passaggio. (Nota: una volta tagliate le ragnatele la descrizione
della stanza deve cambiare di conseguenza). L'uscita verso OVEST riporta alla
Stanza 1.

Stanza 4:
Questa stanza contiene la CHIAVE che può essere raccolta ("r"). (Nota: la
descrizione della stanza deve cambiare dopo aver raccolto la chiave). L'uscita
verso SUD riporta alla Stanza 3.

*/

// Variabili globali che definiscono lo STATO del gioco

int stanza = 1; // stanza in cui il giocatore si trova al momento
int ha_chiave =
    0; // 1 se il giocatore ha raccolto la chiave nella Stanza 4, 0 altrimenti
int ha_spada =
    0;             // 1 se il giocatore ha raccolto la spada nella Stanza 2, 0 altrimenti
int ragnatele = 1; // 1 se il giocatore NON HA ANCORA TAGLIATO le ragnatele
// nella Stanza 3, 0 altrimenti
int vittoria =
    0; // 1 se il giocatore ha aperto la porta nella Stanza 1, 0 altrimenti

// ************Funzioni Utili per dimagrire il corpo delle funzioni**********
void controllo_vittoria()
{
  if (!ha_chiave)
  {
    printf("Non hai la chiave per uscire.\n");
    return;
  }
  printf("Complimenti hai vinto!!!!!!\n");
  vittoria = 1;
}

void cambia_stanza(int nuova_stanza) { stanza = nuova_stanza; }

void taglia_ragnatele()
{
  if (ragnatele && ha_spada)
  {
    ragnatele = 0;
  }
}

void raccogli_chiave()
{
  if (!ha_chiave)
  {
    ha_chiave = 1;
  }
}

void prima_stanza(int azione)
{
  if (azione == 'w')
  {
    cambia_stanza(2);
    return;
  }
  else if (azione == 'e')
  {
    cambia_stanza(3);
    return;
  }
  else if (azione == 's')
  {
    controllo_vittoria();
  }
  else
  {
    printf("Azione non disponibile\n");
  }
}

void seconda_stanza(int azione)
{
  if (azione == 'e')
  {
    cambia_stanza(1);
    return;
  }

  if (azione == 'r' && !ha_spada)
    ha_spada = 1;
  else
    printf("Azione non disponibile.\n");
}

void terza_stanza(int azione)
{
  if (azione == 'n' && !ragnatele)
  {
    cambia_stanza(4);
    return;
  }
  else if (azione == 'w')
  {
    cambia_stanza(1);
    return;
  }
  else if (azione == 'a')
  {
    taglia_ragnatele();
  }
  else
  {
    printf("Azione non disponibile.\n");
  }
}

void quarta_stanza(int azione)
{
  if (azione == 'r')
    raccogli_chiave();
  else if (azione == 's')
  {
    cambia_stanza(3);
    return;
  }
  else
    printf("Azione non disponibile.\n");
}

// **************************************************************************

void stampa_testo_stanza()
{
  printf("****** Stanza %d ******\n", stanza);
  if (stanza == 1)
  {
    printf("Da questa stanza partono due corridoi, uno verso OVEST e uno verso "
           "EST.\n La via di uscita, verso SUD è chiusa a chiave\n");
    printf("w. Vai a stanza 2.\n");
    printf("e. Vai a stanza 3.\n");
    if (ha_chiave)
      printf("s. Esci.\n");
  }
  if (stanza == 2)
  {
    if (!ha_spada)
    {
      printf("Questa stanza contiene un tavolo con sopra una SPADA.\n");
      printf("r. Raccogli spada.\n");
    }
    else
    {
      printf("Questa stanza contiene un tavolo vuoto.\n");
    }
    printf("e. Vai a stanza 1.\n");
  }
  if (stanza == 3)
  {
    if (ragnatele)
    {
      printf("La strada verso nord è bloccata ad fitte ragnatele.\n");
      if (ha_spada)
      {
        printf("Le puoi tagliare con la tua spada!\n");
        printf("a. Taglia le ragnatele.\n");
      }
      else
      {
        printf("Ti servirà qualcosa di tagliente.\n");
      }
    }
    else
    {
      printf("La stada verso nord è libera\n");
      printf("n. Vai a stanza 4.\n");
    }
    printf("w. Vai a stanza 1.\n");
  }
  if (stanza == 4)
  {
    if (!ha_chiave)
    {
      printf("In terra al centro della stanza sta una chiave.\n");
      printf("r. Raccogli la chiave.\n");
    }
    else
    {
      printf("La stanza è vuota.\n");
    }
    printf("s. Vai a stanza 3.\n");
  }
}

void agisci(char azione)
{
  if (stanza == 1)
  {
    prima_stanza(azione);
    return;
  }
  if (stanza == 2)
  {
    seconda_stanza(azione);
    return;
  }
  if (stanza == 3)
  {
    terza_stanza(azione);
    return;
  }
  if (stanza == 4)
    quarta_stanza(azione);
}

char leggi_input()
{
  char c;
  scanf(" %c", &c);
  return c;
}

int main()
{
  printf("Ti trovi rinchiuso dentro a una prigione.\nDietro di te, una porta "
         "conduce alla salvezza.\nMa ti serve una chiave.\n");
  while (!vittoria)
  {
    stampa_testo_stanza();
    char azione = leggi_input();
    agisci(azione);
  }
}
