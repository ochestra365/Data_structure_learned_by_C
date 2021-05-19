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
	if (T != NULL)T->topstk = NULL;//���ø���Ʈ�� �����ϸ�
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
	//�׸��� �׸� �׷����� �� �� �����͸� ���־� �Ʒ��ʵ����͸� Ȯ���ϰų� ���� �� �ִµ�, �̴� �������� ���Ἲ�� ���Ѱ��̴�.
	//pop�� �Ʒ����� ���� ����Ű�� NULL���� ����Ű�� �ȴ�.
	ptstc->topstk = newNode;//���ο� ��带 ���ؼ� ���� ��带 ������ �� �ֵ��� ���°��� ������ ��忡 �Ҵ��Ѵ�.
}
int pop(TStack* ptstack) 
{
	int data;
	Snode* temp;
	if (isEmpty(ptstack)) {
		printf("STACK is EMPTY!\n");
		return;//�Ʒ� ������ �������� �������� �ϸ� return���� �༭ �Լ��ǿ����� �����Ų��.
	}
	else {//�̰� �м��غ���
		data = ptstack->topstk->data;//data ���� �� �� ��� �����Ͱ��� �־��ش�.
		temp = ptstack->topstk;//temp���� �ּҰ��� �ִ´�.-->�̰� ���¸� ��Ÿ����.
		//���� ������ ����Ű�� �ִ� �޸𸮴� ���� ���� �ִ� ��带 �ǹ��Ѵ�.
		ptstack->topstk = ptstack->topstk->link;//�� �� ž ����� ��ũ�� �־��ش�. �������� ž�� ���¸� �������ְ� ������ ž�� �����ع���
		free(temp);//������ ��ȯ�Ѵٴ� ���� �� ���� ��带 �����Ѵٴ� ���̴�.
		//��ǻ�Ϳ����� �޸� �������� �Ҵ�� ������ ���������� ���̱� �����̴�. 
		return data;//data�� �ֹ߽��ѹ���
	}
}
int peek(TStack* ptstack) {
	if (isEmpty(ptstack)) {
		printf("STACK EMPTY!!\n");
		return;
	}
	else {
		return ptstack->topstk->data;//data�� �ִ´�. ���� ��ܿ� �ִ� ����� �����͸� ����Ų��.
	}
}
void printStack(TStack* ptstack) {
	Snode* curr = ptstack->topstk;//�� ���� ��忡�� ��ȸ�ϸ鼭 �Ʒ��� ����.
	while (curr != NULL) {//������ �������� NULL�̴�. �ֳ��ϸ� ����Ű�� �� �ƹ��͵� ���� �����̴�.
		printf("%d\n", curr->data);
		curr = curr->link;
	}

}
int main() {
	TStack* h = createHead();
	push(h, 10);
	push(h, 20);
	push(h, 30);
	push(h, 40);
	printStack(h);
	pop(h);
	printStack(h);
	return 0;
}