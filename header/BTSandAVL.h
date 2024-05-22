#include "stiva.h"
#include "../main.h"


struct BTS
{
    Echipa val;
    struct BTS *stanga, *dreapta;
    int inaltime;    
};

typedef struct BTS BTS;

//BTS
BTS *newNode(Echipa echipa);
BTS* insert ( BTS * node , Echipa Echipa);
void top8_tree(Echipa*, BTS**, char*);
void reverseInordine(BTS * node, FILE* fisier);
int maximum(int, int);
int inaltime(BTS*);
void preorder(BTS*);
void printTree(BTS* root, int space);

//AVL
BTS * RightRotation ( BTS *);
BTS * LeftRotation ( BTS *);
BTS * LRRotation ( BTS *Z);
BTS * RLRotation ( BTS *Z);
BTS *iAVL( BTS * node , Echipa Echipa);
void afisareAVL(BTS *, FILE *, int);
void top8_treeAVL(Echipa* top8, BTS **node);
void BST_AVL(BTS** , BTS *);
