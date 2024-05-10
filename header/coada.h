#include "../main.h"
#include "../header/liste.h"

struct coada
{
    Echipa *fata, *spate;
    
};
typedef coada coada;

coada* createQueue();
void enQueue(coada*, Echipa*);
Echipa *deQueue(coada*);
