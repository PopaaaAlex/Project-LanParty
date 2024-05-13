#include "./header/liste.h"
#include "./header/coada.h"
#include "main.h"

void citire(FILE *fisier, Echipa **echipe, int *Nr_echipe)
{
    Jucator *jucatori = NULL;
    Echipa *cap_echipa = NULL;
    int nr_participanti = 0, punctaj = 0;
    char nume_echipa[50], nume[20], prenume[30], space;
    fscanf(fisier, "%d\n", Nr_echipe);
    for (int i = 0; i < *Nr_echipe; i++)
    {
        fscanf(fisier, "%d%c", &nr_participanti, &space);
        fgets(nume_echipa, sizeof(nume_echipa), fisier);
        jucatori = (Jucator *)calloc(nr_participanti, sizeof(Jucator));
        
         float punctaj_e = 0;        
        for (int j = 0; j < nr_participanti; j++)
        {
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

        for (int j = 0; j < nr_participanti; j++)
        {
            free(jucatori[j].Nume);
            free(jucatori[j].Prenume);
        }
        free(jucatori);
    }
}

void scriere(Echipa *head, char *argv)
{
    FILE *fisier = fopen(argv, "w");
    while (head != NULL)
    {
        head->nume_echipa[strlen(head->nume_echipa) - 1] = '\0';
        fprintf(fisier, "%s\n", head->nume_echipa);
        head = head->next;
    }

    fclose(fisier);
}

// functii task[2]

int echipe_ramase(int *nr_echipe)
{
    int x = 1;

    while ((x * 2) < *nr_echipe)
        x = x * 2;

    return x;
}

void eliminare(Echipa **echipa, int *Nr_echipe)
{
    float x = 0.0;
    int nr_ramas = 0;
    nr_ramas = echipe_ramase(Nr_echipe);
    while (nr_ramas < *Nr_echipe)
    {
        x = minim(*echipa);
        deleteNode(echipa, x);
        (*Nr_echipe)--;
    }
}

float minim(Echipa *echipa)
{
    float x = INT_MAX;
    while (echipa != NULL)
    {
        if (echipa->punc_e < x)
            x = echipa->punc_e;
        echipa = echipa->next;
    }

    return x;
}

void afisare(Echipa *echipa)
{
    while(echipa != NULL)
    {
        //printf("%s", echipa->nume_echipa);
        echipa = echipa->next;
    }
}
//Task[3]

void citire_coada(Echipa *echipe, coada **queue, int nr_echipe)
{
    for(int i = 0; i < nr_echipe; i++)
    {
        enQueue((*queue), echipe);
        echipe = echipe->next;
    }
}

void meciuri(coada* queue, int *nr_echipe, char *argv){
   
    stiva *castigatori = NULL, *pierzatori = NULL;
    FILE *fisier;
    fisier = fopen(argv,"at");
    
    for(int i = 0; i < *nr_echipe; i += 2) {
    
        Echipa *echipa_1 = NULL, *echipa_2 = NULL;//loop infinit;

        echipa_1 = deQueue(queue);
        echipa_2 = deQueue(queue);

        echipa_1->nume_echipa[strlen(echipa_1->nume_echipa) - 1] = ' ';
        echipa_2->nume_echipa[strlen(echipa_2->nume_echipa)- 1] = '\0';
        
        if (echipa_1 != NULL && echipa_2 != NULL) {
            fprintf(fisier, "%-33s-%33s\n", echipa_1->nume_echipa, echipa_2->nume_echipa);
            if(echipa_1->punc_e >= echipa_2->punc_e)
            {
                echipa_1->punc_e++;
                push(&castigatori, echipa_1);
                push(&pierzatori, echipa_2);
            }
            else if(echipa_2->punc_e > echipa_1->punc_e)
                    {
                        echipa_2->punc_e++;
                        push(&castigatori, echipa_2);
                        push(&pierzatori, echipa_1);
                    }            
        } else {
            printf ("Opps, something went wrong with the teams\n");
        }
        
        
        

    }
}//in coada iau bine informatiile 
