#include "funcionalidades.h"

#define TAMANHO_CHAVE 8

void adiciona()
{	
	Item aux;
	Quant n;
	char chave[TAMANHO_CHAVE+1];
	scanf("%s",chave);
	scanf("%d",&n);
	getchar();
	aux=search(chave);
	if(head==NULL) //caso seja a primeira chave a ser adicionada
	{
		aux=NewItem(chave,n);
		if(aux->unidades<0)
			aux->unidades=0;
		insertST(aux);
		highest=aux;
	}
	else if(aux==NULL) //caso a chave ainda nao exista
	{
		aux=NewItem(chave,n);
		if(aux->unidades<0)
			aux->unidades=0;
		insertST(aux);
		
		if(quant(aux)>quant(highest)) //verifica se o produto introduzido apresenta mais unidades que o highest
			highest=aux;
		else if(quant(aux)==quant(highest) && less(key(aux),key(highest)))
			highest=aux;
	}
	else //caso a chave ja exista
	{
		if(n<0)
		{
			aux->unidades=aux->unidades-abs(n);
			if(aux->unidades<0)
				aux->unidades=0;
		}
		else
			aux->unidades=aux->unidades+n;

		if(aux==highest && n<0) //caso tenham sido removidas unidades ao highest volta-se a realizar a procura do mesmo
			traverse2(head);
		else //verifica se o produto introduzido apresenta mais unidades que o highest
			if(quant(aux)>quant(highest))
				highest=aux;
			else if(quant(aux)==quant(highest) && less(key(aux),key(highest)))
				highest=aux;
	}
}

void lista()
{
	traverse(head);
	getchar();
}

void maior()
{
	if(head!=NULL) //caso nao existam produtos nao ha qualquer output
		showItem(highest);
	getchar();
}

void retira()
{
	char chave[TAMANHO_CHAVE+1];
	scanf("%s",chave);
	if(eq(chave,key(highest)))//se o highest for removido realiza-se outra vez a procura
	{
		deleteST(chave);
		highest = NULL;
		traverse2(head);
	}
	else deleteST(chave);
	getchar();
}

void termina()
{
	int contador=count(head);
	printf("%d\n",contador);
	freeST(head);
}
