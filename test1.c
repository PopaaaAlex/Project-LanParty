#include "./header/liste.h"
#include "main.h"

void citire(FILE *fisier, Echipa **echipa)
{
    Jucator *jucatori;
    int Nr_echipe, nr_participanti = 0, punctaj = 0;
    char nume_echipa[50], nume[20], prenume[30], space;
    fscanf(fisier, "%d%c", &Nr_echipe, &space);
    
    for(int i = 0; i < Nr_echipe; i++)
    {
        fscanf(fisier,"%d%c", &nr_participanti, &space);
        fscanf(fisier,"%s%c",nume_echipa,&space);
        jucatori=calloc(nr_participanti,sizeof(Jucator));

        for(int j = 0; j < nr_participanti; j++)
        {
            fscanf(fisier,"%s%c",nume, &space);
            fscanf(fisier," %s%c",prenume,&space);
            fscanf(fisier,"%d",&punctaj);
            
            jucatori[j].Nume=(char*)calloc(strlen(nume)+1, sizeof(char));
            
            strcpy(jucatori[j].Nume, nume);

            jucatori[j].Prenume=(char*)calloc(strlen(prenume)+1, sizeof(char));
            strcpy(jucatori[j].Prenume, prenume);
            
            jucatori[j].punctaj = punctaj;
            if(echipa[i]==NULL)
                addAtBeginning(echipa,nume_echipa, nr_participanti, jucatori[j]);
                else printf("eroare");
        }
        for(int j=0; j < nr_participanti; j++){
            free(jucatori[j].Nume);
            free(jucatori[j].Prenume);
        }
        free(jucatori);
    }
}

void scriere(Echipa *head)
{

}