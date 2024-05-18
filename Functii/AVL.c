#include "BTS.h"

BTS * dreaptaRotation ( BTS *z) {
    BTS *y = z-> stanga ;
    BTS *T3 = y-> dreapta ;

    y-> dreapta = z;
    z-> stanga = T3;

    z-> inaltime = max(inaltime(z->stanga), inaltime(z->dreapta))+1;

    y-> inaltime = max( inaltime (y-> stanga ) ,
    inaltime(y-> dreapta ))+1;
    
    return y;
}

BTS * LeftRotation ( BTS *z) {
    BTS *y = z->dreapta ;
    BTS *T2 = y->stanga ;

    y->stanga = z;
    z->dreapta = T2;
   
    z->inaltime = maximum( inaltime (z->stanga ) ,
    inaltime (z->dreapta ))+1;
   
    y->inaltime = maximum( inaltime (y->stanga ) ,
    inaltime (y->dreapta ))+1;
   
    return y;
}

BTS * LRRotation ( BTS *Z) {
    Z->stanga = leftRotation (Z->stanga );
    return rightRotation (Z);
}
BTS * RLRotation ( BTS *Z) {
    Z->dreapta = rightRotation (Z->dreapta );
    return leftRotation (Z);
}