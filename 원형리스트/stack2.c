#include <stdio.h>
#include <stdbool.h>
//LiquidList(연결자료구조)
typedef struct snode {
	int data;
	struct snode* link;
}Snode;

typedef struct {
	Snode* topstk;
}TStack;//상태값을 드러낸다.

TStack* createHead(void) {
	TStack* T = (TStack*)malloc(sizeof(TStack));
	if (T != NULL)T->topstk = NULL;
	return T;
}
int isEmpty(TStack* ptstack) 
{
	if (ptstack->topstk == NULL) return true;
	else return false;
}
void push(TStack* ptstc, int data) {
	Snode* newNode = (Snode*)malloc(sizeof(Snode));
	if (newNode == NULL)return;
	newNode->data = data;
	newNode->link = ptstc->topstk;//윗노드가 아랫노드를 가리키게 해야 한다. 그래야 윗노드를 삭제해도 아무 문제가 없다. 헤드에 있는 필드에 들어가 있는 값을 새로운 노드의 링크에 저장
	//top은 상태를 나타낸다.
	//pop시 아래에서 위를 가리키면 NULL값을 가리키게 된다.
	ptstc->topstk = newNode;
}
int pop(TStack* ptstack) 
{
	int data;
	Snode* temp;
	if (isEmpty(ptstack)) {
		printf("STACK is EMPTY!\n");
		return;
	}
	else {//이거 분석해보기
		data = ptstack->topstk->data;
		temp = ptstack->topstk;
		ptstack->topstk = ptstack->topstk->link;
		free(temp);
		return data;
	}
}
int peek(TStack* ptstack) {
	if (isEmpty(ptstack)) {
		printf("STACK EMPTY!!\n");
		return;
	}
	else {
		return ptstack->topstk->data;
	}
}
void printStack(TStack* ptstack) {
	Snode* curr = ptstack->topstk;
	while (curr != NULL) {
		printf("%d    ", curr->data);
		curr = curr->link;
	}

}
int main() {
	TStack* h = createHead();
	push(h, 10);
	push(h, 20);
	push(h, 30);
	printStack(h);
	return 0;
}