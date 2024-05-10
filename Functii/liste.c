#include "../main.h"
#include "../header/liste.h"

void addAtBeginning(Echipa **head, char *nume_echipa, int index, Jucator *citit, float puntaj_e )
{
	Echipa *newEchipa = (Echipa*)malloc(sizeof(Echipa));
	newEchipa->punc_e = puntaj_e;
	newEchipa->nume_echipa = (char*)calloc(strlen(nume_echipa) + 1, sizeof(char));
    strcpy(newEchipa->nume_echipa, nume_echipa);
    
	newEchipa->nr_participanti = index;
	newEchipa->Jucator=calloc(index, sizeof(Jucator));
	for(int i = 0; i < index; i++){  
		newEchipa->Jucator[i].Nume = (char*)calloc(strlen(citit[i].Nume) + 1, sizeof(char));
		strcpy(newEchipa->Jucator[i].Nume, citit[i].Nume);

		newEchipa->Jucator[i].Prenume = (char*)calloc(strlen(citit[i].Prenume) + 1, sizeof(char));
		strcpy(newEchipa->Jucator[i].Prenume, citit[i].Prenume);

		newEchipa->Jucator[i].punctaj = citit[i].punctaj;
	}
	if (head == NULL) {
		head = &newEchipa;
		newEchipa->next = NULL;
	} else {
		newEchipa->next = *head;
		*head = newEchipa;
	}
}


void deleteNode(Echipa **head, float v){	
	if (*head==NULL) return; 
	Echipa *headcopy = *head;
	if (headcopy->punc_e==v){
		*head = (*head)->next;
		free(headcopy);
		return; 
	}
	Echipa *prev = *head;
	while (headcopy!=NULL){
		if(headcopy->punc_e != v){
			prev = headcopy;
			headcopy = headcopy->next;
		}else{
			prev->next = headcopy->next;
			free(headcopy); 
			return; 
		} 
	}
}

void removeEchipa(Echipa **head) {
	if (head == NULL) return;
	if (*head == NULL) return;

	Echipa *headCopy = *head;
	*head = (*head)->next;

	free(headCopy->nume_echipa);
	int nr_part = headCopy->nr_participanti;
	Jucator *jucatori = headCopy->Jucator;
	for (int i = 0; i < nr_part; i++) {
		free (jucatori[i].Nume);
		free(jucatori[i].Prenume);
	}
	free(jucatori);
	free(headCopy);
}
