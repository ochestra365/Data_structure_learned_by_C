#include <stdio.h>
#include <stdbool.h>

typedef struct snode {
	int data;
	struct snode* link;
}Snode;

typedef struct {
	Snode* topstk;
}TStack;
TStack* createHead(void) {
	TStack* T = (TStack*)malloc(sizeof(TStack));
	if (T != NULL)T->topstk = NULL;
	return T;
}
int isEmpty(TStack* ptstack)
{
	if (ptstack->topstk == NULL)return true;
	else return false;
}
void push(TStack* ptstc, int data) {
	Snode* newNode = (Snode*)malloc(sizeof(Snode));
	if (newNode == NULL)return;
	newNode->data = data;
	newNode->link = ptstc->topstk;
}