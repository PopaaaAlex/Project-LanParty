#ifndef stiva_h
#define stiva_h

#include"../main.h"

struct stiva{
    Echipa val;
    struct stiva *next;
};
typedef struct stiva stiva;

int isEmpty(stiva*);
void deleteStack(stiva**);

#endif