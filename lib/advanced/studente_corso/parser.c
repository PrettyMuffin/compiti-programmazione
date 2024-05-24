#include "../studente_corso.h"
#include "stdio.h"

// spostare qui l'implementazione delle funzioni `conta_linee`, `leggi_studente`, `scrivi_studente`

// PRE: fp punta all'inizio di un file studenti
int conta_linee(FILE *fp)
{
    char nl = getc(fp);
    if (nl == EOF)
        return 0;
    int c = 1;
    while (nl != EOF)
    {
        if ((nl = getc(fp)) == '\n')
            c += 1;
    }
    fflush(fp);
    rewind(fp);
    return c;
}
// POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file

void leggi_studente(FILE *fp, Studente *s)
{
    fscanf(fp, "%s %s", s->nome, s->cognome);
    for (int i = 0; i < N_VOTI - 1; i++)
    {
        fscanf(fp, "%d ", s->voti + i);
    }
    // leggo l'ultimo numero
    fscanf(fp, "%d\n", s->voti + N_VOTI - 1);
}
// POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s

void scrivi_studente(FILE *fp, Studente s)
{
    fprintf(fp, "%s %s ", s.nome, s.cognome);
    for (int i = 0; i < N_VOTI - 1; i++)
    {
        fprintf(fp, "%d ", s.voti[i]);
    }
    fprintf(fp, "%d\n", s.voti[N_VOTI - 1]);
}
// POST: scrive su file i dati di un unico studente