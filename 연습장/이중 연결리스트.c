#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	struct ListNode* llink;//����(����) ��忡 ���� ��ũ
	char data[4];
	struct ListNode* rlink;//������(����) ��忡 ���� ��ũ
}listNode;

//����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
}h;
//���� ���� ���� ����Ʈ�� �����ϴ� ����
h* createLinkedList_h(void) {
	h* DL;
	DL = (h*)malloc(sizeof(h));//��� ��� �Ҵ�
	DL->head = NULL;//���� ����Ʈ�̹Ƿ� NULL�� ����
	return DL;
}
//���� ���� ����Ʈ�� ������� ����ϴ� ����
void printList(h* DL) {
	listNode* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL)printf(", ");
	}
	printf(") \n");
}
//pre �ڿ� ��带 �����ϴ� ����
void insertNode(h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)//���� �ڸ��� ���� ��尡 �ִ� ���
			newNode->rlink->llink = newNode;
	}
}
//���� ���� ����Ʈ���� old��带 �����ϴ� ����
void deleteNode(h* DL, listNode* old) {
	if (DL->head == NULL)return;//���鸮��Ʈ�� ��� ���� ���� �ߴ�
	else if (old == NULL)return;//������ ��尡 ���� ��� �������� �ߴ�
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);//���� ����� �޸� ����
	}
}
//����Ʈ���� x��带 Ž���ϴ� ����
listNode* searchNode(h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)return temp;
		else temp = temp->rlink;
	}
	return temp;
}

int main() {
	h* DL;
	listNode* p;
	DL = createLinkedList_h();//���鸮��Ʈ ����
	printf("(1) ���� ���� ����Ʈ �����ϱ� \n");
	printList(DL); getchar();

	printf("(2) ���� ���� ����Ʈ�� [��]��� �����ϱ�\n");
	insertNode(DL, NULL, "��");
	printList(DL); getchar();

	printf("(3) ���� ���� ����Ʈ�� [��]��� �ڿ� [��]��� �����ϱ�!\n");
	p = searchNode(DL, "��"); insertNode(DL, p, "��");
	printList(DL); getchar();

	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�!\n");
	p = searchNode(DL, "��"); insertNode(DL, p, "��");
	printList(DL); getchar();

	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ� \n");
	p = searchNode(DL, "��"); deleteNode(DL, p);
	return 0;
}