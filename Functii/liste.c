#include "../main.h"
#include "../header/liste.h"

void addAtBeginning(Echipa **head, char *nume_echipa, int index,Jucator citit  )
{
	Echipa *newEchipa = (Echipa *)malloc(sizeof(Echipa));

    newEchipa->nr_participanti = index;

    newEchipa->nume_echipa = (char *)calloc(strlen(nume_echipa) + 1, sizeof(char));
    strcpy(newEchipa->nume_echipa, nume_echipa);

    newEchipa->Jucator.Nume = (char *)calloc(strlen(citit.Nume) + 1, sizeof(char));
    strcpy(newEchipa->Jucator.Nume, citit.Nume);

    newEchipa->Jucator.Prenume = (char *)calloc(strlen(citit.Prenume) + 1, sizeof(char));
    strcpy(newEchipa->Jucator.Prenume, citit.Prenume);

    newEchipa->Jucator.punctaj = citit.punctaj;

    newEchipa->next = *head;
    *head = newEchipa;
}

/*void addAtEnd(Node** head, int v){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->punctaj = v; 
	if (*head == NULL) addAtBeginning(head, v);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}

void deleteNode(Node **head, int v){	
	if (*head==NULL) return; 
	Node *headcopy = *head;
	if (headcopy->punctaj==v){
		*head = (*head)->next;
		free(headcopy);
		return; 
	}
	Node *prev = *head;
	while (headcopy!=NULL){
		if(headcopy->punctaj!=v){
			prev = headcopy;
			headcopy = headcopy->next;
		}else{
			prev->next = headcopy->next;
			free(headcopy); 
			return; 
		} 
	}
}*/
