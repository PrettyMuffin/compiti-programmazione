#include <stdio.h>
#include <stdlib.h>
#include "test_board.c"

int main(int argc, char *argv[]) {

    printf("--Start Tests--\n\n");
    test_mossa_ammissibile();
    test_board_vincente();
    test_partita_terminata();

    printf("\nTutti i test passati con successo!\n");
    printf("\n--End Tests--\n");

}