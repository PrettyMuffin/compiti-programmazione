#include "../studente_corso.h"
#include <stdio.h>

float percentuale_superamento_test(Corso s, int n_studenti, int esame){
    int n_passed = 0, n_total = 0;
    for(int i=0; i<n_studenti; i++){
        int voto_studente = (s+i)->voti[esame];
        if(voto_studente>=0 && voto_studente<=30){
            n_total += 1;
            if(voto_studente>=18){
                n_passed += 1;
            }
        }
    }
    return n_total>0?n_passed/(float) n_total: 0.0;
}

Studente miglior_studente(Corso s, int n_studenti){

    int studente_migliore = 0;
    int miglior_voto = calcola_media(s[0]);
    for(int i=1; i< n_studenti; i++){
        int media = calcola_media(s[i]);
        if(media>miglior_voto){
            studente_migliore = i;
            miglior_voto = media;
        }
    }
    return s[studente_migliore];
}

void ordina_studenti(Corso s, int n_studenti){
    if(n_studenti<=0){
        return;
    }
    Studente pivot = s[n_studenti-1];
    int i = 0;
    for(int current = 0; current<n_studenti; current++){
        if(calcola_media(s[current])<=calcola_media(pivot)){
            //scambia i con current
            Studente temp = s[i];
            s[i] = s[current];
            s[current] = temp;
            i++;
        }
    }
    ordina_studenti(s, i-1);
    ordina_studenti(s+i, n_studenti-i);
}