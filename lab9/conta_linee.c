#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

/* FORMATO FILE STUDENTI:
 * File testuale, una riga per ogni studente nel formato seguente:
 * nome cognome voto1 voto2 voto3 voto4 voto5
 * Il numero di linee del file corrisponde quindi al numero di studenti
 */

// int main(void)
// {
//     FILE *fp;
//     fp = fopen("studenti.txt", "r");
//     if (fp == NULL)
//     {
//         printf("Il file non può essere aperto\n");
//     }
//     else
//     {
//         int n_stud = conta_linee(fp);
//         Studente s[n_stud];

//         for (int i = 0; i < n_stud; i++)
//         {
//             leggi_studente(fp, s + i);
//         }

//         fclose(fp);
//         printf("Trovati %d studenti\n", n_stud);

//         for (int i = 0; i < n_stud; i++)
//         {
//             printf("%d) %s %s\n", i + 1, s[i].nome, s[i].cognome);
//         }
//     }

//     return 0;
// }
