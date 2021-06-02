#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

//����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
}h;

//���� ���� ����Ʈ�� �����ϴ� ����
h* createLinkedList_h(void) {
	h* L;
	L = (h*)malloc(sizeof(h));
	if(L!=NULL)L->head = NULL;//���鸮��Ʈ�̹Ƿ� NULL�� ����. ��������� ���� ���� �񱳴���� ���� �� �߻��Ѵ�.
	return L;
}
//���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedLsit_h(h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
//���Ḯ��Ʈ�� ������� ����ϴ� ����
void printList(h* L) {
	listNode* p;
	printf("L =(");
	p = L->head;
	while (p!=NULL)
	{
		printf("%s", p->data);
		p = p->link;
		if (p != NULL)printf(", ");
	}
	printf(")\n");
}
void insertFirstNode(h* L, char* x) {//��������
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}
void insertMiddleNode(h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}
//������ ���� �����ϴ� ����
void insertLastNode(h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {//���� ����Ʈ�� ������ ���
		L->head = newNode;//�� ��带 ������ ���� ���� ����
		return;
	}
	//���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;
	while (temp->link != NULL)temp = temp->link;//���� ����Ʈ�� ������ ��带 ã��
	temp->link = newNode;//�� ��带 ������ ���(temp)�� ���� ���� ����
}
//����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(h* L, listNode* p) {
	listNode* pre;//������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL)return;//���� ����Ʈ��� ���� ���� �ߴ�.
	if (L->head->link == NULL) {//����Ʈ�� ��尡 �� ���� �ִ� ���
		free(L->head);//ù ��° ��带 �޸𸮿��� �����ϰ�
		L->head = NULL;//����Ʈ ���� �����͸� NULL�� ����
	}
	else if (p == NULL)return;//������ ��尡 ���ٸ� ���� ���� �ߴ�
	else {//������ ��� p�� ������ ��带 ������ pre�� �̿��� ã��
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;//������ ��� p�� ������ ���� ���� ��带 ����
		free(p);//���� ����� �޸� ����
	}
}
//����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)return temp;
		else temp = temp->link;
	}
	return temp;
}
// ����Ʈ�� ��� ������ �������� �ٲٴ� ����
void reverse(h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;//������ p�� ù ��° ��忡 ����
	q = NULL;
	r = NULL;

	//����Ʈ�� ù ���� ������ ��ũ�� ���� ���� ���� �̵��ϸ鼭
	//��� ���� ������ �ٲ�
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}
int main() {
	h* L;
	L = createLinkedList_h();
	printf("(1) ���� ����Ʈ �����ϱ�\n");
	printList(L); getchar();

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�!\n");
	insertFirstNode(L, "��");
	printList(L); getchar();

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ�!\n");
	insertLastNode(L, "��");
	printList(L); getchar();

	printf("(4)����Ʈ�� ù��°�� [��]��� �����ϱ�!\n");
	insertFirstNode(L, "��");
	printList(L); getchar();

	printf("(5)����Ʈ ������ �����Ͽ� ���鸮��Ʈ�� �����\n");
	freeLinkedLsit_h(L);
	printList(L);

	getchar();
	return 0;
}