#include "stiva.h"
#include "../main.h"


struct BTS {
    Echipa val;
    struct BTS *stanga, *dreapta;
    int inaltime;    
};
typedef struct BTS BTS;

//BTS
BTS *newNode(Echipa);
BTS* insert ( BTS *  , Echipa);
void top8_tree(Echipa*, BTS**, char*);
void reverseInordine(BTS *, FILE*);
int maximum(int, int);
int inaltime(BTS*);
void preorder(BTS*);
void printTree(BTS* , int);

//AVL
BTS * RightRotation (BTS *);
BTS * LeftRotation (BTS *);
BTS * LRRotation (BTS *);
BTS * RLRotation (BTS *);
BTS *iAVL(BTS * , Echipa);
void afisareAVL(BTS *, FILE *, int);
void top8_treeAVL(Echipa* , BTS **);
void BST_AVL(BTS** , BTS *);
void update_inaltime(BTS *);
void update_inaltime_c(BTS *);
