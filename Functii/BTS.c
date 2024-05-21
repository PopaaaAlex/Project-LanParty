#include "../header/BTSandAVL.h"

BTS *newNode(Echipa echipa)
{
    BTS * node = (BTS*) malloc ( sizeof (BTS ));
    node->val = echipa;
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

        node->inaltime = 1 + maximum(node->stanga, node->dreapta);
    return node ;
    }

void reverseInordine(BTS * node, FILE* fisier)
{
   
    if( node != NULL)
    {
        reverseInordine(node->dreapta, fisier);
        fprintf(fisier, "%-34s-  %.2f\n", node->val.nume_echipa, node->val.punc_e);
        reverseInordine(node->stanga, fisier);
    }
}

int maximum( BTS *node_s, BTS *node_d)
{   
    if(inaltime(node_s) > inaltime(node_d))
        return inaltime(node_s);
    
    return inaltime(node_d);
}

int inaltime(BTS *node)
{
    if(node == NULL) return 0;

    return node->inaltime;

}