#ifndef _LINK_
#define _LINK_

#include "item.h"

typedef struct node *link;
extern link head;
extern Item highest;
struct node { 
	Item item;
	struct node *l;
	struct node *r;
	int height;
};

void init();
void insertST(Item item);
Item search(Key v);
int count(link head);
void deleteST(Key k);
void traverse(link h);
void traverse2(link h);
void freeST(link head);

#endif 
