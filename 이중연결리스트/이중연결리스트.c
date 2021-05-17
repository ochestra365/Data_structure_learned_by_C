#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���߿��Ḯ��Ʈ: ����� �ϳ� �� �����. ������, next, pre
/// ����ü ����
typedef struct node {//��
	int data;
	struct node* next;
	struct node* pre;
}DListNode;


typedef struct head {//��
	DListNode* head;
}HeadNode;
/// �Լ�����
DListNode* createNode(int data);//��
HeadNode* createHead(void);//��
//void insertNode(HeadNode* phead, DListNode preNode, DListNode* next);//��ȣ ��带 ����� �ְ� ������� �ִ� ���̴�.
void insertNode1(HeadNode* phead, DListNode* preNode, DListNode* newNode);//�������� ���� ���
void printNode1(HeadNode* phead);//�������� ���� ���
void DelNode(HeadNode* phead, DListNode* DelNode);//���� �����
DListNode* findNode(HeadNode* phead, int data);
//void printNode(HeadNode* phead);//���� ���ɼ��� ����
/// ����
int main(void) {
	HeadNode* h = createHead();//��� ��� ����
	DListNode* lp = NULL;
	DListNode* n1 = createNode(10);
	insertNode1(h, lp, n1);
	DListNode* n2 = createNode(20);
	insertNode1(h, n1, n2);
	printNode(h);
	return 0;
}
/// ����� ����
HeadNode* createHead(void) {//��
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)h->head = NULL;
	return h;
}
// ��� ����
DListNode* createNode(int data) {//��
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����");
		exit(1);
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		newNode->pre = NULL;
		return newNode;
	}
}
//�������� ���� insertNode
void insertNode1(HeadNode* phead, DListNode* preNode, DListNode* newNode) {
	if (phead->head == NULL) {
		phead->head = newNode;
	}
	else {
		newNode->pre = preNode;
		newNode->next = preNode->next;
		if (preNode->next != NULL)newNode->next->pre = newNode;
		preNode->next = newNode;
	}
}
//�������� ���� PrintNode
void printNode1(HeadNode* phead) {
	DListNode* curr = NULL;
	if (phead == NULL)return;
	curr = phead->head;
	while (curr != NULL) {
		printf("%d", curr->data);
		curr = curr->next;
	}
}
void DelNode(HeadNode* phead, DListNode* DelNode) {//����Ʈ ���翩��, ���� ��� Ư��
	if (phead->head == NULL) {
		printf("����Ʈ�� �������� ������ ������ ��嵵 �����ϴ�.");
	}
	else {
		DelNode->pre->next = DelNode->next;
		DelNode->next->pre = DelNode->pre;
		free(DelNode);
		// �Ǹ����� ����� ���� ó�� ���� ��� �ϴ� �� �𸣰ڵ�.while�� head ���� ������ ã�Ƽ����� ������ ���ٵ� 
	}
}//���� ���� delnode
//���� ���� ã�� ���
DListNode* findNode(HeadNode* phead, int data) {//���� ���� ��.
	DListNode* curr=phead->head;
	int cnt=1;
	if (curr == NULL) {
		printf("��尡 �������� �ʽ��ϴ�. ����Ʈ�� �����ϼ���");
	}
	else {
		while (curr->next!= NULL) {//������ ������
			curr = curr->next;
			if (curr->data == data) {
				printf("ã���ô� ���� %d��°���� �����մϴ�. ����� ���� %d�Դϴ�.",cnt ,curr->data);
				return;
			}
			else {
				printf("ã�� ��尡 �������� �ʽ��ϴ�.");
				return;
			}
			cnt++;
		}
	}
	
}









//��� ����(���� ���� ��)
//void insertNode(HeadNode* phead, DListNode* preNode, DListNode* nextNode) {//��ȣ(���� ���� ��)
//	//�������� ���� ��尡 �μ��� �־�����. �������� ���� ��尡 �������� ������ ó���� ��带 ������ ��츦 �������� �ʾƵ� �ȴ�.
//	//�ֳ��ϸ� �� ���ǿ� ���ϸ� ��� 2�� �̻��� ���� �ݵ�� �־����� �����̴�.
//	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//	if (phead->head == NULL) {//���� ����Ʈ�ϋ�. if������ ù° ��带 �������ش�.
//		newNode = phead->head;
//	}
//	else if (phead->head != NULL) {//�߰��� ������ �� ó���� ���� ���� ��츦 �������� �ʾƵ� ��.
//		preNode->next = newNode->data;
//		newNode->next = nextNode->data;
//		newNode->pre = preNode->data;
//		nextNode->pre = newNode->data;
//		//������� �´�.
//	}
//	else {
//		DListNode* tempNode = (DListNode*)malloc(sizeof(DListNode));
//		tempNode->next = phead->head;//head�� ����Ű�� �ִ� ���踦 �����ֱ� ���� temp��带 �����.
//		while (phead->head != NULL)//�� �������� �������� ���� ��尡 �������� �ʴ´�.
//		{
//			tempNode->next = tempNode->next->next;//������ ���ư��� �����.
//			//�̰� �̵��� ��������
//		}
//		tempNode->next = newNode->data;//����Ʈ�� �Ǹ��������� ���� ���Ŀ� newNode�� ����Ű�� �Ѵ�.
//	}
//}
//���� �����
//void printNode(HeadNode* phead) {
//	int cnt = 0;//����� ��� ���� while���� ���� ������ ����
//	if (phead->head == NULL) {//���� ����Ʈ�϶�
//		printf("���鸮��Ʈ �Դϴ�. ��带 �����ϼ���");
//	}
//	else {//��尡 1���̻� �����Ҷ�
//		while (phead->head != NULL) {
//			printf("%d��° ����� ������ ���� %d�Դϴ�.", cnt, phead->head->data);//���� �Ǽ��� �κ��ε� ��Ȯ�� �����͸� ����ϴ� �� �ƴ϶� ���踦 ������ �־���.
//			phead->head = phead->head->next;
//			cnt++;
//		}
//	}
//}
//ȥ�� �ٽ� �غ��� ������ ���� �߻���(������ ���� �͵� �ҽ��ڵ� �ٽ� �����ϱ�)
