#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];//������� ������ �߿��ϴ�. �ֳ��ϸ� ������ �ݴ��� ���鸮��Ʈ���� ������ �� ���� �����̴�.
	struct ListNode* link;
}listnode;

//����Ʈ ������ �˸��� ������� ����(���鸮��Ʈ)
typedef struct {
	listnode* head;
}linkedList_h;

//���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {//�Է°��� �翬�� ����. �ֳ��ϸ� �����͸� ���� �־� �� �ʿ䰡 ���� �����̴�.
	//Head�� ù��° ����� ���缺�� Ȯ�ν����� ���̴�.
	linkedList_h* L=(linkedList_h*)malloc(sizeof(listnode));//���鸮��Ʈ�� ����ü �����͸� �������� ����� �ش�.
	if (L != NULL)L->head = NULL;
	return L;//L�� ��ȯ�Ѵ�.
}
//���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinked_h(linkedList_h* L) {//linkedList_h �ʱ� ���鸮��Ʈ�� ��� ������踦 �����ϴ� ����� �� �� �ִ�. �ֳ��ϸ� 
	//link�� ���� ����κи� �����ϸ� ������ �κе� ������ �����ϱ� �����̴�.
	listnode* p;//�̰��� ����Ʈ �����Ͱ� ������ ��Ʈ�̴�.
	while (L->head != NULL) {//!=�� '�����Ѵ�'��� ���� �ǹ��Ѵ�.
		p = L->head;//����ü �����Ϳ� L->head�� �Ҵ��Ѵ�.
		L->head = L->head->link;
		free(p);
		p = NULL;//P���� ����ش�.
	}
}
//���Ḯ��Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
	listnode* p;
	p = L->head;
	while (p != NULL)//p�� ������ ������, ������谡 �����Ҷ�����
	{
		printf("L=(");
		printf("%s", p->data);//p�� �����͸� ���������� ���� 
		p = p->link;//p�� ���� ��ũ �׷� ���� ��带 ����Ű�� �ȴ�.
		if (p != NULL)printf(", ");
		printf(")\n");
	}
}
// ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h* L, char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(listnode));//������ ����� �Ҵ�
	strcpy(newNode->data, x);//�� ����� ������ �ʵ忡 x����
	newNode->link = L->head;
	L->head = newNode;
}

//��带 pre�ڿ� �����ϴ� ����(�̰� ���� �� ��� ��������)-->�߷��� �ǽ��غ���
void insertMiddleNode(linkedList_h *L ,listnode*pre,char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(linkedList_h));
	strcpy(newNode->data, x);
	if (L == NULL) {//���鸮��Ʈ�� ���
		newNode->link = NULL;//�� ��带 ù��°���� ������ ���� ����(�ֳ��ϸ� ������ ����� link���� null�̱� �����̴�.)
		L->head = newNode;//������� ���۵����� ��
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;//������ rpe�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}
//������ ���� �����ϴ� ����(�̰� ������ ��� ��������)-->�߷��� �ǽ��غ���.
void insertLastNode(linkedList_h* L, char* x) {
	listnode* newNode;
	listnode* temp;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link = NULL;//������ ����� link�� �׻� NULL�̴�.
	if (L->head == NULL) {//���� ����Ʈ�� ������ ���.. �³� head�� ������ �ƿ� ������ �ȵǴϱ� ����Ʈ�� ������ ���� �ǹ��ϳ�.
		L->head = newNode;//�� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	//���� ����Ʈ�� ������ �ƴ� ���-->��尡 �ִ� ���
	temp = L->head;
	while (temp->link != NULL)temp = temp->link;//���� ����Ʈ�� ������ ��带 ã��.
	temp->link = newNode;//�� ��带 ������ ����� ���� ���� ����(���� ����?)
}
int main(void) {
	linkedList_h* L = createLinkedList_h();
	printf("(1) ���� ����Ʈ �����ϱ�\n");
	printList(L); //�̰Ŵ� ���ȴ�. ���� ����� ù ���� �����Ͱ��� �ҷ����� �ű⶧���� 

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�\n");
	insertFirstNode(L, "��");
	printList(L); //�̰Ŵ� ���ȴ�. ���� ����� ù ���� �����Ͱ��� �ҷ����� �ű⶧���� 

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ� \n");
	insertLastNode(L, "��");
	printList(L);

	printf("(4) ����Ʈ ù ��°�� [��] ��� �����ϱ� \n");
	insertFirstNode(L, "��");
	printList(L);

	printf("(5) ����Ʈ ������ �����Ͽ� ���鸮��Ʈ�� ����� \n");
	freeLinked_h(L);
	printList(L);
	return 0;
}