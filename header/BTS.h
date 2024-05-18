#include "stiva.h"
#include "../main.h"

struct BTS
{
    Echipa val;
    struct BTS *stanga, *dreapta;
    int inaltime;    
};

typedef struct BTS BTS;

BTS *newNode(Echipa echipa);
BTS* insert ( BTS * node , Echipa Echipa);
void top8_tree(Echipa*, BTS*, char*);
void reverseInordine(BTS * node, FILE* fisier);
int maximum(BTS*, BTS*);
int inaltime(BTS*);