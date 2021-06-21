#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;//���� ������ �ڷ����� int�� ����
typedef struct stackNode {//������ ��带 ����ü�� ����
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;//������ top��带 �����ϱ� ���� ������ top ����

//������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL)return 1;
	else return 0;
}
//������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));//���α׷� ���� ���߿� ��带 �����ؾ� �ϴϱ�
	temp->data = item;//���� ��带 top�� ���� ����
	temp->link = top;//top ��ġ�� ���� ���� ����
	top = temp;
}
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {//������ ���鸮��Ʈ�� ���
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {//������ ���鸮��Ʈ�� �ƴѰ��
		item = temp->data;
		top = temp->link;//top��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);//������ ����� �޸� ��ȯ
		return item;//������ ���� ��ȯ
	}
}
element peek() {
	if (top == NULL) {//������ ���鸮��Ʈ�� ���
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {//������ ���鸮��Ʈ�� �ƴ� ���
		return(top->data);//���� top�� ���� ��ȯ
	}
}

//������ ���Ҹ� top���� bottom������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	pritnf("\nSTACK[");
	while (p) {
		printf("%d", p->data);
		p = p->link;
	}
	printf("] ");
}
int main()
{
	element item;
	top = NULL;
	pritnf("\n** ���� ���� ���� **\n");
	printStack();
	push(1); printStack();//1����
	push(2); printStack();//2����
	push(3); printStack();//3����

	item = peek(); printStack();//���� top�� ���� ���
	printf("peek=>%d", item);

	item = pop(); printStack();//����
	printf("\t pop=>%d", item);

	item = pop(); printStack();//����
	printf("\t pop => %d", item);

	item = pop(); printStack();//����
	printf("\t pop=> %d", item);

	getchar();
	return 0;
}