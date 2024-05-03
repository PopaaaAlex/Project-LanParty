#include "header/liste.h"
#include "main.h"

FILE *fisier1, *fisier2;

int main()
{
    Echipa *echipa = NULL;
    int nr_echipe;

    fisier1=fopen("date/t1/d.in","rt");
    fisier2=fopen("out/r.out","w");
    
    if(fisier1 == NULL)
        {
            printf("nu s-a putut deschide");
            exit(1);
        }
    fscanf(fisier1, "%d", &nr_echipe);
    echipa = (Echipa*)calloc(nr_echipe, sizeof(Echipa));
    
    citire(fisier1, &echipa);
    fclose(fisier1); 

    if(fisier2 == NULL)
        {
            printf("nu s-a putut deschide");
            exit(1);
        }
    fclose(fisier2);

    free(echipa); 
    return 0;
}