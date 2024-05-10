#include "header/liste.h"
#include "main.h"

int main(int argc, char *argv[])
{
    FILE *fisier1, *fisier2, *fisier3;
    Echipa *echipa = NULL;
    int nr_echipe;
    int cerinte[5]= {0};
    
    //fisier1 = fopen("date/t1/c.in","rt");
    //fisier2 = fopen("date/t1/d.in","rt");
    fisier1 = fopen(argv[1],"rt");
    fisier2 = fopen(argv[2],"rt");
    if(fisier1 == NULL)
        {
            printf("nu s-a putut deschide1 %s\n", argv[1]);
            exit(1);
        }
    
    for(int i = 0; i < 5; i++){
        fscanf(fisier1,"%d", &cerinte[i]);
    }
   
    if(cerinte[0] == 1 ){
    citire(fisier2, &echipa, &nr_echipe);
    scriere(echipa, argv[3]);
    }
    fclose(fisier1); 

    free(echipa); 
    return 0;
}