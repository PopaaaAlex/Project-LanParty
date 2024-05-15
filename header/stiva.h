#ifndef stiva_h
#define stiva_h

#include "../header/liste.h"
#include "../main.h"

struct stiva{
    Echipa val;
    struct stiva *next;
};
typedef struct stiva stiva;

int isEmpty(stiva*);
void deleteStack(stiva**);
void push(stiva**, Echipa*);
void printStack(stiva*, FILE*);
//Echipa pop(stiva**);

#endif