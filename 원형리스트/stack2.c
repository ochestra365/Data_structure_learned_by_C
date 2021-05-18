#include <stdio.h>
#include <stdbool.h>
//LiquidList(�����ڷᱸ��)
typedef struct snode {
	int data;
	struct snode* link;
}Snode;

typedef struct {
	Snode* topstk;
}TStack;//���°��� �巯����.

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
	newNode->link = ptstc->topstk;//����尡 �Ʒ���带 ����Ű�� �ؾ� �Ѵ�. �׷��� ����带 �����ص� �ƹ� ������ ����. ��忡 �ִ� �ʵ忡 �� �ִ� ���� ���ο� ����� ��ũ�� ����
	//top�� ���¸� ��Ÿ����.
	//pop�� �Ʒ����� ���� ����Ű�� NULL���� ����Ű�� �ȴ�.
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
	else {//�̰� �м��غ���
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