#include "../main.h"
#include "liste.h"
#include "stiva.h"

struct coada
{
    Echipa *fata, *spate;
};
typedef struct coada coada;

int isEmpty_q(coada*);
coada* createQueue();
void enQueue(coada*, Echipa*);
Echipa* deQueue(coada*);
void citire_coada(Echipa*, coada**, int);
void afisare_coada(coada*, char*);
void meciuri(coada*,int*, char*);
