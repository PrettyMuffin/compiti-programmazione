#ifndef BOARD_H
#define BOARD_H

/*
 * Funzioni di stampa e gestione del board del gioco tris.
 */

// BOARD_SIZE indica il numero totale di caselle del gioco
#define BOARD_SIZE 9
#define BOARD_LATO 3
#define SIMB_X 'X'
#define SIMB_O 'O'
#define CASELLA_VUOTA ' '

int board_vincente(char board[]);
/*
    POST Restituisce
            1 se uno dei due giocatori ha vinto (si hanno 3 simboli uguali su una riga, una colonna o su una diagonale)
            0 altrimenti
*/

void reset_board(char board[]);
/*
 * PRE: board ha dimensione BOARD_SIZE
 * POST per ogni i tale che 0<=i<BOARD_SIZE si ha board[i]=CASELLA_VUOTA
 */

int controllo_colonna_vincente(char board[]);
/*
 * PRE: board ha dimensione BOARD_SIZE
 * POST: ritorna 1 se c'è una colonna con tutti i simboli uguali e diversi dal carattere vuoto
 *       ritorna 0 altrimenti
 */

int controllo_riga_vincente(char board[]);
/*
 * PRE: board ha dimensione BOARD_SIZE
 * POST: ritorna 1 se c'è una riga con tutti i simboli uguali e diversi dal carattere vuoto
 *       ritorna 0 altrimenti
 */

int controllo_diagonale_vincente(char board[]);
/*
 * PRE: board ha dimensione BOARD_SIZE
 * POST: ritorna 1 se c'è una diagonale con tutti i simboli uguali e diversi dal carattere vuoto
 *       ritorna 0 altrimenti
 */

void effettua_mossa(char board[], int x, int y, char simbolo_giocatore);
/*
    POST board cambiata aggiungendo la mossa (x,y) se ammissibile.
*/

/*
    L'utente inserisce le coordinate bidimensionali x,y della mossa,
    board[] è un vettore unidimensionale.
    Una mossa è ammissibile se le coordinate sono all'interno
    delle dimensioni della board (BOARD_LATO x BOARD_LATO) e
    la casella non è già stata selezionata da un altro giocatore.
*/

int mosse_disponibili(char board[]);
/*
 * PRE: board ha dimensione BOARD_SIZE
 * POST: Ritorna 1 se ci sono mosse dispobibili nella board, altrimenti ritorna 0
 */

/*  Una partita termina se uno dei due giocatori ha vinto oppure se
    non sono possibili ulteriori mosse */
int partita_terminata(char board[]);
/*
 * POST restituisce
            1 se la partita è terminata
            0 altrimenti
 */

void print_board(char board[]);
/*
 * PRE: board ha dimensione BOARD_SIZE
 * POST Stampata a video la schermata del gioco tris in accordo con i valori specificati in board
 */

#endif
