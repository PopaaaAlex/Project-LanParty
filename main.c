#include "header/liste.h"
#include "main.h"

FILE *fisier1,*fisier2;

int main()
{
    fisier1=fopen("date/t1/d.in","rt");
    fisier2=fopen("out/r.out","w");
    
    if(fisier1 == NULL)
        {
            printf("nu s-a putut deschide");
            exit(1);
        }
    
    citire(fisier1);
    fclose(fisier1);
    
    if(fisier2 == NULL)
        {
            printf("nu s-a putut deschide");
            exit(1);
        }
    fclose(fisier2);

    return 0;
}