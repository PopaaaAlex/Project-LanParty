#include "../main.h"
#include "../header/stiva.h"

int isEmpty(Echipa *top){
	return top==NULL;
}
	
void deleteStack(Echipa **top){
	Echipa  *temp;
	while ((*top)!=NULL){ // !isEmpty(*top)
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}	



void push(Echipa**top, int v) {
	Echipa* newNode=(Echipa*)calloc(1,sizeof(Echipa));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}


void printStack(Echipa* stack){
	while (!isEmpty(stack))
		printf("%d ", pop(&stack));
}


