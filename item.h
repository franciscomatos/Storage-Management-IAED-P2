#ifndef _ITEM_
#define _ITEM_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define key(a) (a != NULL ? a->chave : "")
#define quant(a) (a != NULL ? a->unidades : 0)
#define less(a,b) (strcmp(a,b)<0)
#define eq(a,b) (strcmp(a,b)==0)

typedef char* Key;
typedef int Quant;

typedef struct produto {
	char *chave;
	int unidades;
}* Item;


Item NewItem(char *chave,int unidades);
void deleteItem(Item a);
void showItem(Item x);
int cmpItem(Item a,Item b);
#endif 
