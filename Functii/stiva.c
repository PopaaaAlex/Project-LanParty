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

int pop(Echipa**top) {
	if (isEmpty(*top)) return INT_MIN; 
	Echipa *temp=(*top);  		
	int aux=temp->val;			
	*top=(*top)->next;      		
	free(temp);
	return aux;
}

void push(Echipa**top, int v) {
	Echipa* newNode=(Echipa*)Echipa(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

/*int top(Echipa *top){
	if (isEmpty(top)) return INT_MIN;
	return top->val;
}*/

void printStack(Echipa* stack){
	while (!isEmpty(stack))
		printf("%d ", pop(&stack));
}


