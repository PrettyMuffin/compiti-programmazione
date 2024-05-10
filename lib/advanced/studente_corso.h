#define N_VOTI 5

typedef struct studente {
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
} Studente;

//----studente.h---//
//PRE: s è uno studente valido (voti compresi tra 0 e 30 oppure uguali a -1)
float calcola_media(Studente s);
//POST calcolare la media dei voti conseguiti (esami svolti)

//PRE: s è uno studente valido
int sufficienza_studente(Studente s);
//POST: restituisce 1 se la media dei voti conseguiti è >= 18, 0 altrimenti

void print_studente(Studente s);
//Funzione di utilità per stampare a schermo tutti i dati dello studente. Seguire l'esempio riportato di seguito.
/* Esempio di stampa
 * Nome: Michele 
 * Cognome: Poggi
 * Voti: [1,2,3,4,5]
 */

//----corso.c----//
//Il tipo Corso è un alias di Studente*, puntatore ad array di studenti allocato nello heap
typedef Studente *Corso;

//PRE: esame compreso tra 0 e N_VOTI
float percentuale_superamento_test(Corso s, int n_studenti, int esame);
//POST: calcola la percentuale di superamento dell'esame (solo guardando gli studenti che hanno conseguito un voto, chi non ha fatto l'esame non è contato)

//PRE: s è un corso non vuoto
Studente miglior_studente(Corso s, int n_studenti);
//POST: restituisce lo studente con la media più alta

void ordina_studenti(Corso s, int n_studenti);
//POST: ordina gli studenti a seconda della loro media
//NOTA: l'algoritmo di ordinamento da utilizzare è a vostra discrezione. E' consentito riadattare l'esercizio sul quicksort se volete