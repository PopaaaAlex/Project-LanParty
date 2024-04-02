#include <stdio.h>
#include <stdlib.h>

FILE *fisier1,*fisier2;

int main()
{
    fisier1=fopen("date/t1/d.in","rt");
    fisier2=fopen("r.out","w");
    
    if(fisier1 == NULL)
        {
            printf("nu s-a putut deschide");
            exit(1);
        }
    char date[256];
    while(feof(fisier1) == 0)
    {
        fgets( date, sizeof(date), fisier1);
    }

    fclose(fisier1);
    
    if(fisier2 == NULL)
        {
            printf("nu s-a putut deschide");
            exit(1);
        }
    fclose(fisier2);

}