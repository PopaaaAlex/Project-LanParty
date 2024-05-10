#include "../main.h"
#include "../header/coada.h"

coada* createQueue ()
{
	coada *q;
	q = (coada*)calloc(1, sizeof (coada));
	if (q == NULL ) return NULL ;
	q->fata = q->spate = NULL ;
	return q;
}

void enQueue ( coada *q, Echipa *v)
{
	Echipa * newNode =( Echipa *) malloc ( sizeof ( Echipa ));
	newNode->punc_e = v->punc_e;
	newNode->nume_echipa= (char*)calloc(strlen(v->nume_echipa)+1,sizeof(char));
	strcpy(newNode->nume_echipa, v->nume_echipa);
	newNode->next = NULL ;

	if (q->spate == NULL ) 
		q->spate = newNode ;
			else 
			{
				(q->spate)->next = newNode ;
				(q->spate) = newNode ;
			}

if (q->fata == NULL ) q->fata = q-> spate ;
}

Echipa *deQueue(coada *q) {  
	coada aux; 
	Echipa *e = (Echipa*)calloc(1,sizeof(Echipa));
	if (isEmpty(q)) exit(1);
	
	aux.fata = q->fata; 
	e->punc_e = aux.fata->punc_e;
	e->nume_echipa=(char*)calloc(strlen(aux.fata->nume_echipa)+1, sizeof(char));
	strcpy(e->nume_echipa,aux.fata->nume_echipa);
	q->fata=(q->fata)->next;
	free(aux.fata);
	return e;  	
} 