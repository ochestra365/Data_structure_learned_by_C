#include <stdio.h>
//���������� ����� ������ ��带 ����Ű�� �Ѵ�. �׷��߸� ������ ����� ������ ã�ư��� ����.
typedef struct node {
	int data;
	struct node* link;
}Node;
typedef struct {
	Node* head;
}HeadNode;
HeadNode* createHead();
Node* createNode(HeadNode* phead, int data); 
void insertFirstNode(HeadNode* phead, Node* newNode);
void insertLastNode(HeadNode* phead, Node* newNode);
//void printNode(HeadNode* phead);//�����
int main() {
	HeadNode* h = createHead();//��� ����
	Node* A = createNode(h, 10);
	Node* B = createNode(h, 20);
	Node* C = createNode(h, 30);
	Node* D = createNode(h, 40);
	Node* E = createNode(h, 50);//��� ����
	insertFirstNode(h, A);//���� ����(������ ����)
	return 0;
}
HeadNode* createHead() {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));//����� ����ü �������� ������� ����� ��ŭ�̾�� �Ѵ�.
	if (h != NULL)h->head = NULL;
	return h;
}
Node* createNode(HeadNode* phead, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));//�� ������ ����Ʈ ũ�⸸ŭ ������ �� �ִ� ��ŭ �Ҵ�ް�, �� ���� ���� �޴´�.
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����");
		return;
	}
	else {
		newNode->data = data;
		newNode->link = NULL;//������� ���� �� � �͵� ����Ű�� ���� ���輺�� ���� ���̴�.
		return newNode;
	}
}
void insertFirstNode(HeadNode* phead, Node* newNode) {//������ ����
	if (phead->head == NULL) {//���鸮��Ʈ�� ��
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head;
		phead->head = newNode;
		phead->head->link = phead->head;
	}
}
void insertLastNode(HeadNode* phead, Node* newNode) {
	//Node* tempNode = (Node*)malloc(sizeof(Node));
	//tempNode = phead->head;
	if (phead->head == NULL) {//���鸮��Ʈ�� ��
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head;//������ ��带 ����Ű�� curr��带 ���� ���� ������ �ʿ䰡 ����.
		while (phead->head != NULL) {
			//tempNode = tempNode->link;
			phead->head = phead->head->link;//��� ��ũ������ ���������� �ݺ��� �������� ��ȯ�ȴ�.
		}
		//tempNode->link = newNode;
		//newNode->link = phead->head;
		phead->head = newNode;//������ ��尡 ù��° ���
	}
}
//node1 �� ��� ������ �Ѵ�.
//void printNode(HeadNode* phead) {
//
//}