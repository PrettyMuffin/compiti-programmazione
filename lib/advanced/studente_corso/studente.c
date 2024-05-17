#include "../studente_corso.h"
#include "../../basic/array.h"
#include <stdio.h>

float calcola_media(Studente s){
    int somma = 0;
    int voti_validi = 0;
    for(int i=0;i<N_VOTI;i++){
        int voto = s.voti[i];
        if(voto>=0 && voto<=30){
            somma += voto;
            voti_validi++;
        }
    }
    return voti_validi>0? somma/(float) voti_validi: 0.0;
}

int sufficienza_studente(Studente s){
    float media = calcola_media(s);
    return media >=18 ? 1 : 0;
}

void print_studente(Studente s){
    printf("Nome: %s\nCognome: %s\nVoti: ", s.nome, s.cognome);
    stampa_array(s.voti, N_VOTI);
    printf("\n");
}
void leggi_array_double(double *A, int dim) {

    for(int i=0; i<dim; i+=1) {
        scanf("%lf", &A[i]);
    }
}