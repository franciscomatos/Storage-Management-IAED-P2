#include "link.h"

void init()
{
	head = NULL;
	highest = NULL;
}

link NEW(Item item, link l, link r)
{
	link x = (link)malloc(sizeof(struct node));
	x->item = item;
	x->l = l;
	x->r = r;
	x->height=1;
	return x;
}

int height(link h)
{
	if (h==NULL) return 0;
	return h->height;
}

link rotL(link h)
{
	int height_left, height_right;
	link x = h->r;
	h->r = x->l;
	x->l = h;
	
	height_left = height(h->l); height_right = height(h->r);
	h->height = height_left > height_right ? height_left + 1 :
	height_right + 1;
	
	height_left = height(x->l); height_right = height(x->r);
	x->height = height_left > height_right ? height_left + 1 :
	height_right + 1;
	
	return x;
}

link rotR(link h)
{
	int height_left, height_right;
	link x = h->l;
	h->l = x->r;
	x->r = h;
	
	height_left = height(h->l); height_right = height(h->r);
	h->height = height_left > height_right ? height_left + 1 :
	height_right + 1;
	
	height_left = height(x->l); height_right = height(x->r);
	x->height = height_left > height_right ? height_left + 1 :
	height_right + 1;
	
	return x;
}

link rotLR(link h) /*rotação dupla esquerda direita*/
{
	if (h==NULL) return h;
	h->l=rotL(h->l);
	return rotR(h);
}

link rotRL(link h) /*rotação dupla direita esquerda*/
{
	if (h==NULL) return h;
	h->r=rotR(h->r);
	return rotL(h);
}

int Balance(link h) /*Balance factor*/
{
	if(h == NULL) return 0;
	return height(h->l)-height(h->r);
}

link AVLbalance(link h) {
	int balanceFactor;
	if (h==NULL) return h;
	balanceFactor= Balance(h);
	if(balanceFactor>1)
	{
		if (Balance(h->l)>=0)
			h=rotR(h);
		else
			h=rotLR(h);
	}
	else if(balanceFactor<-1)
	{
		if (Balance(h->r)<=0)
			h = rotL(h);
		else
			h = rotRL(h);
	}
	else
	{
		int height_left = height(h->l); int height_right = height(h->r);
		h->height = height_left > height_right ? height_left + 1 :
		height_right + 1;
	}
	return h;
}

link insertAux(link h, Item item) 
{
	if (h == NULL)
		return NEW(item, NULL, NULL);
	if (less(key(item), key(h->item)))
		h->l = insertAux(h->l, item);
	else
		h->r = insertAux(h->r, item);
	h=AVLbalance(h);
	return h;
}

void insertST(Item item)
{
	head = insertAux(head,item);
}

Item searchAux(link h, Key v)
{
	if (h == NULL)
		return NULL;
	if (eq(v, key(h->item)))
		return h->item;
	if (less(v, key(h->item)))
		return searchAux(h->l, v);
	else
		return searchAux(h->r, v);
}

Item search(Key v)
{
	return searchAux(head, v);
}

link max(link h) 
{
	while(h!=NULL && h->r!=NULL)
		h=h->r;
	return h;
}

link deleteAux(link h, Key k)
{
	if (h==NULL) 
		return h;
	else if (less(k, key(h->item))) 
		h->l=deleteAux(h->l,k);
	else if (less(key(h->item), k)) 
		h->r=deleteAux(h->r,k) ;
	else 
	{
		if (h->l !=NULL && h->r !=NULL) /*caso seja um no interno*/
		{
			link aux=max(h->l);
			{Item x; x=h->item; h->item=aux->item; aux->item=x;}
			h->l= deleteAux(h->l, key(aux->item));
	}
		else /*caso o no nao tenha filhos ou tenha um unico filho*/
		{ 
			link aux=h;
			if ( h->l == NULL && h->r == NULL ) 
				h=NULL;
			else if (h->l==NULL) 
				h=h->r;
			else 
				h=h->l;
			deleteItem(aux->item);
			free(aux);
		}
	}
	h=AVLbalance(h);
	return h;
}

int countAux(link h){
	if (h==NULL) 
		return 0;
	else 
		return countAux(h->r)+countAux(h->l)+1;
}

int count(link head)
{
	return countAux(head);
}

void deleteST(Key k)
{
	head = deleteAux(head,k);
}

void traverse(link h)
{
	if (h == NULL)
		return;
	traverse(h->l);
	showItem(h->item);
	traverse(h->r);
}

void traverse2(link h)
{
	if (h == NULL)
		return;
	if(quant(h->item)>quant(highest))
			highest=h->item;
	else if(quant(h->item)==quant(highest))
		if(less(key(h->item),key(highest)))
			highest=h->item;
	traverse2(h->l);
	traverse2(h->r);
}

link freeAux(link h)
{
	if (h==NULL)
		return h;
	h->l=freeAux(h->l);
	h->r=freeAux(h->r);
	return deleteAux(h,key(h->item));
}

void freeST(link head)
{
	head=freeAux(head);
}
