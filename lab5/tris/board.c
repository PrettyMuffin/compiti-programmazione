#include <stdio.h>
#include "board.h"

int board_vincente(char board[])
{
    return controllo_colonna_vincente(board) || controllo_riga_vincente(board) || controllo_diagonale_vincente(board);
}

int controllo_colonna_vincente(char board[])
{
    int vincente = 0;
    int c = 1;
    for (int i = 0; i < BOARD_LATO && !vincente; i++)
    {
        for (int j = 0; j < BOARD_LATO - 1; j++)
        {
            if (board[j * BOARD_LATO + i] != CASELLA_VUOTA && board[j * BOARD_LATO + i] == board[(j + 1) * BOARD_LATO + i])
                c += 1;
        }
        if (c == 3)
            vincente = 1;
        c = 1;
    }
    return vincente;
}

int controllo_riga_vincente(char board[])
{
    int c = 1;
    for (int i = 0; i < BOARD_LATO; i++)
    {
        for (int j = 0; j < BOARD_LATO - 1; j++)
        {
            if (board[i * BOARD_LATO + j] != CASELLA_VUOTA && board[i * BOARD_LATO + j] == board[i * BOARD_LATO + (j + 1)])
                c += 1;
        }
        if (c == 3)
            return 1;
        c = 1;
    }
    return 0;
}

int controllo_diagonale_vincente(char board[])
{
    int c = 1;
    // diagonale sinistra
    for (int i = 0, j = 0; i < BOARD_LATO - 1 && j < BOARD_LATO - 1; i++, j++)
    {
        if (board[i * BOARD_LATO + j] != CASELLA_VUOTA && board[i * BOARD_LATO + j] == board[(i + 1) * BOARD_LATO + (j + 1)])
            c += 1;
        // primo_controllo = 0;
    }
    if (c == 3)
        return 1;

    c = 1;
    // diagonale destra
    for (int i = 0, j = BOARD_LATO - 1; i < BOARD_LATO - 1 && j > 0; i++, j--)
    {
        if (board[j * BOARD_LATO + i] != CASELLA_VUOTA && board[j * BOARD_LATO + i] == board[(j - 1) * BOARD_LATO + (i + 1)])
            c += 1;
    }
    return c == 3;
}

void effettua_mossa(char board[], int x, int y, char simbolo_giocatore)
{
    // inserisco delle coordinate non valide
    if (x < 1 || x > BOARD_LATO || y < 1 || y > BOARD_LATO)
        return;

    // tolgo 1 così da poter partire a contare da 0,
    // così non mi incasino con il conto delle posizioni dentro l'array
    x--;
    y--;

    // controllo che non sia già stata selezionata la casella scelta
    if (board[y * BOARD_LATO + x] != CASELLA_VUOTA)
        return;

    board[y * BOARD_LATO + x] = simbolo_giocatore;
}

int mosse_disponibili(char board[])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == CASELLA_VUOTA)
            return 1;
    }
    return 0;
}

int partita_terminata(char board[])
{
    if (!board_vincente(board) && mosse_disponibili(board))
        return 0;

    return 1;
}

void print_board(char board[])
{
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);

    printf("     |     |     \n\n");
}

void reset_board(char board[])
{
    /*
     * PRE: board ha dimensione BOARD_SIZE
     * POST per ogni i tale che 0<=i<BOARD_SIZE si ha board[i]=CASELLA_VUOTA
     */
    for (int i = 0; i < BOARD_SIZE; i += 1)
        board[i] = CASELLA_VUOTA;
}
