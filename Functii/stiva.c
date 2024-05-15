#include "../header/stiva.h"


int isEmpty(stiva *top){
	return top == NULL;
}
	
void deleteStack(stiva **top){
	stiva  *temp;
	while (!isEmpty(*top)){ 
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}	



void push(stiva**top, Echipa *echipe) {
	stiva* newNode=(stiva*)calloc(1,sizeof(stiva));
	
	newNode->val.nume_echipa = (char*)calloc(strlen(echipe->nume_echipa) + 1, sizeof(char));
	strcpy(newNode->val.nume_echipa, echipe->nume_echipa);
	newNode->val.punc_e = echipe->punc_e;
	newNode->next = *top;
	*top = newNode;
}


void printStack(stiva* stack, FILE* fisier){
	stiva *aux = stack;
	int counter = 0;
	while (!isEmpty(aux)){
		fprintf(fisier,"%-34s-  %.2f\n", aux->val.nume_echipa, aux->val.punc_e);
		aux = aux->next;	
		counter++;
	}
	if (counter > 1) {
		fprintf(fisier, "\n");
	}
}

// Echipa pop(stiva** top)
// {
// 	stiva *temp =(* top );
// 	Echipa aux= temp->val;
// 	*top =(* top)->next;
// 	free ( temp );
// 	return aux;
// }



