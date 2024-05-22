#include "./../header/BTSandAVL.h"

BTS * RightRotation ( BTS *z) {
    BTS *y = z-> stanga ;
    BTS *T3 = y-> dreapta ;

    y-> dreapta = z;
    z-> stanga = T3;

    z-> inaltime = maximum(inaltime(z->stanga), inaltime(z->dreapta)) + 1;
    y-> inaltime = maximum(inaltime(y->stanga), inaltime(y-> dreapta)) + 1;
    
    return y;
}

BTS * LeftRotation ( BTS *z) {
    // if (z == NULL)
    //     return z;

    BTS *y = z->dreapta ;

    // if (y == NULL)
    //     return z;

    BTS *T2 = y->stanga ;

    y->stanga = z;
    z->dreapta = T2;
   
    if (z != NULL)
        z->inaltime = maximum(inaltime(z->stanga), inaltime(z->dreapta)) + 1;
    
    //if (y != NULL)
        y->inaltime = maximum(inaltime(y->stanga), inaltime(y->dreapta)) + 1;
   
    return y;
}

BTS* LRRotation(BTS *Z) {
    Z->stanga = LeftRotation(Z->stanga );
    return RightRotation(Z);
}

BTS * RLRotation ( BTS *Z) {
    Z->dreapta = RightRotation(Z->dreapta );
    return LeftRotation(Z);
}

BTS* iAVL (BTS * node , Echipa Echipa) {
    if (node == NULL)
        return newNode(Echipa);

    if (node->val.punc_e > Echipa.punc_e)
        node ->stanga = iAVL (node ->stanga, Echipa );

    else if (node->val.punc_e < Echipa.punc_e)
        node->dreapta = iAVL (node ->dreapta , Echipa );

    else if (node->val.punc_e == Echipa.punc_e)
    {
        if((strcmp(node->val.nume_echipa, Echipa.nume_echipa)) < 0)
            node->dreapta = iAVL (node->dreapta, Echipa);
            else
                node->stanga = iAVL (node->stanga, Echipa);
    }

        node->inaltime = 1 + maximum(inaltime(node->stanga), inaltime(node->dreapta));

        int k = (inaltime(node ->stanga) - inaltime(node->dreapta));

        if (k > 1 && Echipa.punc_e < (node->stanga)->val.punc_e){
            return RightRotation(node);
            }
            else 
            {
                if (node->val.punc_e == Echipa.punc_e)
                    if(k > 1 && (strcmp(node->val.nume_echipa, Echipa.nume_echipa)) < 0)
                        return RightRotation(node);
                            else if(k > 1 && (strcmp(node->val.nume_echipa, Echipa.nume_echipa)) > 0)
                                return RightRotation(node);
            }
// && node->dreapta != NULL && node->stanga != NULL && node->dreapta != NULL
        if (k < -1 && Echipa.punc_e > (node->dreapta)->val.punc_e)
            return LeftRotation (node);
            else if (node->val.punc_e == Echipa.punc_e)
                if(k < -1 && (strcmp(node->val.nume_echipa, Echipa.nume_echipa)) > 0)
                    return LeftRotation(node);
                        else if(k < -1 && (strcmp(node->val.nume_echipa, Echipa.nume_echipa)) < 0)
                                return LeftRotation(node);

        if (k > 1  && Echipa.punc_e > (node->stanga)->val.punc_e)
            return LRRotation (node);      
        if (k < -1 && Echipa.punc_e < (node->dreapta)->val.punc_e)
            return RLRotation (node);
    
        return node ;
    }

void BST_AVL(BTS** AVL, BTS *bst)
{
    if(bst != NULL)
    {
        BST_AVL(AVL,bst->dreapta);
        *AVL = iAVL(*AVL,(bst->val));
        BST_AVL(AVL,bst->stanga);
    }
} 