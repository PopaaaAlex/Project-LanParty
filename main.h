#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jucator
{
    char *Nume;
    char *Prenume;
    int punctaj;
};

typedef struct Jucator Jucator;

struct Echipa
{
    char *nume_echipa;
    int nr_participanti;
    struct Jucator Jucator;
    struct Echipa *next;
};

typedef struct Echipa Echipa;

void citire(FILE *,Echipa **);

#endif
