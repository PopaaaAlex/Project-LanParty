#include "./header/liste.h"
#include "./header/coada.h"
#include "./header/BTSandAVL.h"
#include "main.h"

//Functii Task[1]
void citire(FILE *fisier, Echipa **echipe, int *Nr_echipe) {
    Jucator *jucatori = NULL;
    int nr_participanti = 0, punctaj = 0;
    char nume_echipa[50], nume[20], prenume[30], space;
    fscanf(fisier, "%d\n", Nr_echipe);
    for (int i = 0; i < *Nr_echipe; i++) {
        fscanf(fisier, "%d%c", &nr_participanti, &space);
        fgets(nume_echipa, sizeof(nume_echipa), fisier);
       
        nume_echipa[strlen(nume_echipa) - 1] = '\0';
        if (nume_echipa[strlen(nume_echipa) - 2] < '0') {
            nume_echipa[strlen(nume_echipa) - 1] = '\0';
        }
        
        jucatori = (Jucator *)calloc(nr_participanti, sizeof(Jucator));
        
        float punctaj_e = 0;        
        for (int j = 0; j < nr_participanti; j++) {
            fscanf(fisier, "%s%c", nume, &space);
            fscanf(fisier, " %s%c", prenume, &space);
            fscanf(fisier, "%d\n", &punctaj);

            jucatori[j].Nume = (char *)calloc(strlen(nume) + 1, sizeof(char));
            strcpy(jucatori[j].Nume, nume);

            jucatori[j].Prenume = (char *)calloc(strlen(prenume) + 1, sizeof(char));
            strcpy(jucatori[j].Prenume, prenume);

            jucatori[j].punctaj = punctaj;
            punctaj_e += punctaj;
        }
        punctaj_e /= nr_participanti;
        
        addAtBeginning(echipe, nume_echipa, nr_participanti, jucatori, punctaj_e);

        for (int j = 0; j < nr_participanti; j++) {
            free(jucatori[j].Nume);
            free(jucatori[j].Prenume);
        }
        free(jucatori);
    }
}

void scriere(Echipa *head, char *argv) {
    FILE *fisier = fopen(argv, "w");
    while (head != NULL) {
        head->nume_echipa[strlen(head->nume_echipa) - 1] = '\0';
        fprintf(fisier, "%s\n", head->nume_echipa);
        head = head->next;
    }

    fclose(fisier);
}

// functii task[2]

int echipe_ramase(int *nr_echipe) {
    int x = 1;

    while ((x * 2) <= *nr_echipe)
        x = x * 2;

    return x;
}

void eliminare(Echipa **echipa, int *Nr_echipe) {
    float x = 0.0;
    int nr_ramas = 0;
    nr_ramas = echipe_ramase(Nr_echipe);
    while (nr_ramas < *Nr_echipe){
        x = minim(*echipa);
        deleteNode(echipa, x);
        (*Nr_echipe)--;
    }
}

float minim(Echipa *echipa) {
    float x = INT_MAX;
    while (echipa != NULL) {
        if (echipa->punc_e < x)
            x = echipa->punc_e;
        echipa = echipa->next;
    }

    return x;
}

//Task[3]

void citire_coada(Echipa *echipe, coada **queue, int nr_echipe) {
    for(int i = 0; i < nr_echipe; i++) {
        enQueue((*queue), echipe);
        echipe = echipe->next;
    }
}

stiva* meciuri(coada* queue, int *nr_echipe, FILE* fisier) {
   
    stiva *castigatori = NULL, *pierzatori = NULL;

    for(int i = 0; i < *nr_echipe; i += 2) {
    
        Echipa *echipa_1 = NULL, *echipa_2 = NULL;
        echipa_1 = deQueue(queue);
        echipa_2 = deQueue(queue);
        
        if (echipa_1 != NULL && echipa_2 != NULL) {
            fprintf(fisier, "%-33s-%33s\n", echipa_1->nume_echipa, echipa_2->nume_echipa);
            if(echipa_1->punc_e > echipa_2->punc_e) {
                echipa_1->punc_e++;
                push(&castigatori, echipa_1);
                push(&pierzatori, echipa_2);
            }
            else if(echipa_2->punc_e >= echipa_1->punc_e) {
                        echipa_2->punc_e++;
                        push(&castigatori, echipa_2);
                        push(&pierzatori, echipa_1);
                    }       
        } else {
            printf ("Opps, something went wrong with the teams\n");
        }

    }
    fprintf(fisier,"\n");
    deleteStack(&pierzatori);
    return castigatori;
}

void final(coada *queue, int *nr_echipe, char* argv, Echipa **top8) {
    FILE *fisier;
    stiva *castigatori, *aux = NULL, *aux_2;
    fisier = fopen(argv,"at");
    int nr_runda = 1, val = 0;
    while((*nr_echipe) > 1) {
        fprintf(fisier, "--- ROUND NO:%d\n", nr_runda);
        castigatori = meciuri(queue, nr_echipe, fisier);

        aux = castigatori;
        aux_2 = castigatori;
        if(*nr_echipe == 16) {   
                while(val < 8) {
               addAtBeginning(top8, aux_2->val.nume_echipa, 0, NULL, aux_2->val.punc_e); 
                aux_2 = aux_2->next;
                val++;
               }
        }

        while(castigatori != NULL) {
            enQueueStiva(queue, castigatori);
            castigatori = castigatori->next;
        }
        fprintf(fisier, "WINNERS OF ROUND NO:%d\n", nr_runda);
        printStack(aux, fisier);
        
        nr_runda++;
        (*nr_echipe) /= 2;
    }
    free(aux);
    fclose(fisier);
}

//Task[4]

void top8_tree(Echipa* top8, BTS **node, char *argv) {
    FILE* fisier = fopen(argv, "at");
    fprintf(fisier, "\n");
    BTS *aux_1;
    fprintf(fisier, "TOP 8 TEAMS:\n");
    Echipa echipa, *aux = top8;
    while( top8 != NULL) {
        echipa.nume_echipa= (char*)calloc(strlen(top8->nume_echipa) + 1, sizeof(char));
        strcpy(echipa.nume_echipa, top8->nume_echipa);
        echipa.punc_e = top8->punc_e;
        *node = insert(*node, echipa);
        top8 = top8->next;
    }   
    aux_1 = *node;
    reverseInordine(*node, fisier);
    *node = aux_1;
    top8 = aux;
    free(aux);
    fclose(fisier);
}

//Task[5]

void top8_treeAVL(Echipa* top8, BTS **node) {
    Echipa echipa, *aux = top8;
    while( top8 != NULL) {
        echipa.nume_echipa= (char*)calloc(strlen(top8->nume_echipa) + 1, sizeof(char));
        strcpy(echipa.nume_echipa, top8->nume_echipa);
        echipa.punc_e = top8->punc_e;
        *node = iAVL(*node, echipa);
        top8 = top8->next;
    }   
    
    top8 = aux;
    free(aux);
}

void afisareAVL(BTS *AVL, FILE *fisier, int inaltime) {
    if (AVL == NULL)
        return;    
    
    afisareAVL(AVL->dreapta, fisier, inaltime);

    if(AVL->inaltime == inaltime)
        fprintf(fisier,"%s\n",AVL->val.nume_echipa);
    
    afisareAVL(AVL->stanga, fisier, inaltime);
}