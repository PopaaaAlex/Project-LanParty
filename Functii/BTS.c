#include "../header/BTSandAVL.h"

BTS *newNode(Echipa echipa) {
    BTS * node = (BTS*) malloc ( sizeof (BTS ));
    node->val = echipa;
    node->inaltime = 0;
    node->stanga = node->dreapta = NULL ;
    return node;
}

BTS* insert ( BTS * node , Echipa Echipa) {
    if (node == NULL) return newNode(Echipa);
    if (node->val.punc_e > Echipa.punc_e)
        node ->stanga = insert (node ->stanga, Echipa );
    else if (node->val.punc_e < Echipa.punc_e)
        node->dreapta = insert (node ->dreapta , Echipa );
        else if (node->val.punc_e == Echipa.punc_e)
            {
                if((strcmp(node->val.nume_echipa, Echipa.nume_echipa)) < 0)
                    node->dreapta = insert (node->dreapta, Echipa);
                    else
                        node->stanga = insert (node->stanga, Echipa);
            }

    node->inaltime = 1 + maximum(inaltime(node->stanga), inaltime(node->dreapta));
    return node ;
    }

void reverseInordine(BTS * node, FILE* fisier) {
   
    if( node != NULL)
    {
        reverseInordine(node->dreapta, fisier);
        fprintf(fisier, "%-34s-  %.2f\n", node->val.nume_echipa, node->val.punc_e);
        reverseInordine(node->stanga, fisier);
    }
}

int maximum( int node_s, int node_d) {   
    if(node_s > node_d)
        return node_s;

    return node_d;
}

int inaltime(BTS *node) {
    if(node == NULL) 
        return 0;
    return node->inaltime;

}

void preorder ( BTS * root ) {
    if ( root ) {
        printf ("%s %d \n",root ->val.nume_echipa,root->inaltime);
        preorder (root ->stanga);
        preorder (root ->dreapta);
    }
}
