#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

//����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
}h;

//���� ���� ���� ����Ʈ�� �����ϴ� ����
h* createLinkedList_h(void) {
	h* CL;
	CL = (h*)malloc(sizeof(h));
	CL->head = NULL;//���� ����Ʈ �̹Ƿ� NULL�� ����
	return CL;
}

//���Ḯ��Ʈ�� ������� ����ϴ� ����
void printList(h* CL) {
	listNode* p;
	printf(" CL = (");
	p = CL->head;
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head)printf(", ");
	} while (p != CL->head);
	printf(")\n");
}

//ù ��° ��� ���� ����
void insertFirstNode(h* CL, char* x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head = NULL) {//���� ���Ḯ��Ʈ�� ������ ���
		CL->head = newNode;//�� ��带 ����Ʈ�� ���� ���� ����
		newNode->link = newNode;
	}
	else {// ���� ���Ḯ��Ʈ�� ������ �ƴ� ���
		temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;//������ ��带 ù ��° ����� new�� ���� ����
		CL->head = newNode;
	}
}
//pre �ڿ� ��带 �����ϴ� ����
void insertMiddleNode(h* CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}
//���� ���� ����Ʈ�� pre�ڿ� �ִ� ��� old�� �����ϴ� ����
void deleteNode(h* CL, listNode* old) {
	listNode* pre;//������ ����� ������ ��带 ��Ÿ���� ������
	if (CL->head == NULL)return;///���� ����Ʈ�� ��� ���� ���� �ߴ�
	if (CL->head->link == CL->head) {//����Ʈ�� ��尡 �� ���� �ִ� ���
		free(CL->head);//ù��° ����� �޸𸮸� �����ϰ�
		CL->head = NULL;//����Ʈ ���� �����͸� NULL�� ����
		return;
	}
}