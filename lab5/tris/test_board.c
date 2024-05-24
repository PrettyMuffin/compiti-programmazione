#include <stdio.h>
#include <assert.h>
#include "board.h"

void test_mossa_ammissibile()
{
    printf("\tTest Mossa Ammissibile\n");
    char board[BOARD_SIZE];
    reset_board(board); // inizializzo la board a tutte caselle vuote
    effettua_mossa(board, 1, 1, SIMB_X);
    effettua_mossa(board, 1, 1, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_X);
    effettua_mossa(board, 3, 3, SIMB_X);
    effettua_mossa(board, 1, 3, SIMB_O);
    effettua_mossa(board, 3, 1, SIMB_O);
    effettua_mossa(board, 4, 1, SIMB_O);
    print_board(board);
}

void test_board_vincente()
{
    printf("\tTest Board Vincente\n");
    char board[BOARD_SIZE];
    reset_board(board);

    // diagonale sinistra
    effettua_mossa(board, 1, 1, SIMB_X);
    effettua_mossa(board, 2, 2, SIMB_X);
    effettua_mossa(board, 3, 3, SIMB_X);
    assert(board_vincente(board) == 1);
    reset_board(board);

    effettua_mossa(board, 1, 1, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_X);
    effettua_mossa(board, 3, 3, SIMB_O);
    assert(board_vincente(board) == 0);
    reset_board(board);

    // colonna
    effettua_mossa(board, 2, 1, SIMB_X);
    effettua_mossa(board, 2, 2, SIMB_X);
    effettua_mossa(board, 2, 3, SIMB_X);
    assert(board_vincente(board) == 1);
    reset_board(board);

    effettua_mossa(board, 2, 1, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_O);
    effettua_mossa(board, 2, 3, SIMB_X);
    assert(board_vincente(board) == 0);
    reset_board(board);

    // riga
    effettua_mossa(board, 1, 2, SIMB_X);
    effettua_mossa(board, 2, 2, SIMB_X);
    effettua_mossa(board, 3, 2, SIMB_X);
    assert(board_vincente(board) == 1);
    reset_board(board);

    effettua_mossa(board, 1, 2, SIMB_X);
    effettua_mossa(board, 2, 2, SIMB_O);
    effettua_mossa(board, 3, 2, SIMB_O);
    assert(board_vincente(board) == 0);
    reset_board(board);

    // colonna destra
    effettua_mossa(board, 1, 3, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_O);
    effettua_mossa(board, 3, 1, SIMB_O);
    assert(board_vincente(board) == 1);
    reset_board(board);

    effettua_mossa(board, 1, 3, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_O);
    effettua_mossa(board, 3, 1, SIMB_X);
    assert(board_vincente(board) == 0);
    reset_board(board);

    // input sparsi
    effettua_mossa(board, 1, 2, SIMB_O);
    effettua_mossa(board, 2, 1, SIMB_X);
    effettua_mossa(board, 3, 2, SIMB_O);
    assert(board_vincente(board) == 0);
    reset_board(board);
}

void test_partita_terminata()
{
    char board[BOARD_SIZE];
    reset_board(board);

    // mosse a caso con campo non ancora completato (presumibilmente durante la partita)
    effettua_mossa(board, 1, 2, SIMB_O);
    effettua_mossa(board, 2, 1, SIMB_X);
    effettua_mossa(board, 3, 2, SIMB_O);
    assert(partita_terminata(board) == 0);
    reset_board(board);

    // fine per vittoria
    effettua_mossa(board, 1, 3, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_O);
    effettua_mossa(board, 3, 1, SIMB_O);
    assert(partita_terminata(board) == 1);
    reset_board(board);

    // fine per pareggio
    effettua_mossa(board, 1, 1, SIMB_X);
    effettua_mossa(board, 1, 2, SIMB_O);
    effettua_mossa(board, 1, 3, SIMB_O);
    effettua_mossa(board, 2, 1, SIMB_O);
    effettua_mossa(board, 2, 2, SIMB_O);
    effettua_mossa(board, 2, 3, SIMB_X);
    effettua_mossa(board, 3, 1, SIMB_X);
    effettua_mossa(board, 3, 2, SIMB_X);
    effettua_mossa(board, 3, 3, SIMB_O);
    assert(partita_terminata(board) == 1);
    reset_board(board);
}
