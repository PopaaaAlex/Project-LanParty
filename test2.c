#include "./header/liste.h"
#include "main.h"

int echipe_ramase(int *nr_echipe)
{
    int x;
    while((x * 2) < *nr_echipe)
        x=x*2;
    
    return x;
}

void eliminare(Echipa *echipa,int *Nr_echipe)
{
    float x; 
    int nr_ramas;
    nr_ramas  = echipe_ramase(Nr_echipe);
    while(nr_ramas < *Nr_echipe)
    {
        x = minim(echipa);
        deleteNode(&echipa, x);
        (*Nr_echipe)--;  
    }
}

float minim(Echipa *echipa)
{
    float x=INT_MAX;
    while(echipa->next != NULL)
    {
        if(echipa->punc_e < x)
            x = echipa->punc_e;
    echipa = echipa->next;
    }
    return x;
}



