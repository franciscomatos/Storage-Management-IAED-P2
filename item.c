#include "item.h"

Item NewItem(char *chave,int unidades)
{
	Item aux = (Item)malloc(sizeof(struct produto));
	aux->chave = strdup(chave);
	aux->unidades = unidades;
	return aux;
}

void deleteItem(Item a)
{
	free(a->chave);
	free(a);
}

void showItem(Item x)
{
	printf("%s %d\n",key(x),quant(x));
}

int cmpItem(Item a,Item b)
{
	return strcmp(a->chave,a->chave);
}
