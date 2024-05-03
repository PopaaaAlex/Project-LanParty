#include "./header/liste.h"
#include "main.h"

void citire(FILE *fisier)
{
    char date[256];
    int Nr_echipe;
    
    while(feof(fisier) == 0)
    {
        fgets(date, sizeof(date), fisier);
    }

}