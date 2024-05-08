#include "./header/liste.h"
#include "main.h"

void citire(FILE *fisier, Echipa *echipa, int *Nr_echipe)
{
    Jucator *jucatori;
    int  nr_participanti = 0, punctaj = 0;
    float punctaj_e = 0;
    char nume_echipa[50], nume[20], prenume[30], space;
    fscanf(fisier, "%d", Nr_echipe);
    echipa = (Echipa*)calloc((*Nr_echipe), sizeof(Echipa));
    for(int i = 0; i < (*Nr_echipe); i++)
    {
        fscanf(fisier,"%d%c", &nr_participanti, &space);
        fgets(nume_echipa,sizeof(nume_echipa),fisier);
        jucatori=(Jucator*)calloc(nr_participanti,sizeof(Jucator));       
        
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
            punctaj_e=punctaj_e+punctaj;
                           
        }
        punctaj_e = punctaj_e /nr_participanti;
        addAtBeginning(&echipa,nume_echipa, nr_participanti, jucatori, punctaj_e);
         
        for(int j = 0; j < nr_participanti; j++){
            free(jucatori[j].Nume);
            free(jucatori[j].Prenume);
        }
        free(jucatori);
    }
}

void scriere(Echipa *head, char *argv)
{
    FILE *fisier=fopen(argv, "w");
    while(head!= NULL)
    {
        head->nume_echipa[strlen(head->nume_echipa)-1] = '\0';
        fprintf(fisier,"%s\n", head->nume_echipa);
        //printf("%s\n",head->nume_echipa);
        head=head->next;

    }
    
    fclose(fisier);
}

