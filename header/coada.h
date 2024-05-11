#include "../main.h"
#include "../header/liste.h"
#include "../header/stiva.h"

struct coada
{
    Echipa *fata, *spate;
};
typedef struct coada coada;

int isEmpty_q(coada*);
coada* createQueue();
void enQueue(coada*, Echipa*);
Echipa *deQueue(coada*);
void citire_coada(Echipa*, coada**, int);
void afisare_coada(coada*, char*);
