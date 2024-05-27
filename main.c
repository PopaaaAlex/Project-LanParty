#include "./header/liste.h"
#include "./header/coada.h"
#include "./header/stiva.h"
#include "./header/BTSandAVL.h"
#include "main.h"

int main(int argc, char *argv[]){
    FILE *fisier1, *fisier2, *fisier3;
    Echipa *echipe = NULL, *top8 = NULL;
    coada *queue = createQueue();
    BTS *BTS = NULL, *AVL = NULL;
    int nr_echipe = 0, inaltime = 1;
    int cerinte[5] = {0};
    
    fisier1 = fopen(argv[1],"rt");
    fisier2 = fopen(argv[2],"rt");
    if(fisier1 == NULL){
            printf("nu s-a putut deschide1 %s\n", argv[1]);
            exit(1);
        }
    
    for(int i = 0; i < 5; i++){
        fscanf(fisier1,"%d", &cerinte[i]);
    }
   
    if(cerinte[0] == 1 && cerinte[1] == 0){
        citire(fisier2, &echipe, &nr_echipe);
        scriere(echipe, argv[3]);
    }

    if (cerinte[1] == 1 && cerinte[2] == 0){
        citire(fisier2, &echipe, &nr_echipe);
        eliminare(&echipe, &nr_echipe);
        scriere(echipe, argv[3]);
    }

    if(cerinte[2] == 1 && cerinte[3] == 0){
        citire(fisier2, &echipe, &nr_echipe);
        eliminare(&echipe, &nr_echipe);
        citire_coada(echipe, &queue, nr_echipe); 
        afisare_coada(queue, argv[3]);
        final(queue, &nr_echipe, argv[3], &top8 );     
    }
    
    if(cerinte[3] == 1 && cerinte[4] == 0){
        citire(fisier2, &echipe, &nr_echipe);
        eliminare(&echipe, &nr_echipe);
        citire_coada(echipe, &queue, nr_echipe); 
        afisare_coada(queue, argv[3]);
        final(queue, &nr_echipe, argv[3], &top8);
        top8_tree(top8, &BTS, argv[3]);
    }

    if(cerinte[4] == 1){
        citire(fisier2, &echipe, &nr_echipe);
        eliminare(&echipe, &nr_echipe);
        citire_coada(echipe, &queue, nr_echipe); 
        afisare_coada(queue, argv[3]);
        final(queue, &nr_echipe, argv[3], &top8);
        top8_tree(top8, &BTS, argv[3]);
        BST_AVL(&AVL,BTS);
        FILE* fisier = fopen(argv[3], "at");
        fprintf(fisier,"\n");
        fprintf(fisier,"THE LEVEL 2 TEAMS ARE:\n");
        afisareAVL(AVL, fisier, inaltime);
    }

    fclose(fisier1); 
    fclose(fisier2);

    while (echipe != NULL)
        removeEchipa(&echipe);
    
    return 0;
}