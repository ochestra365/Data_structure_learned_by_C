//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////�Ϲ����� ���� �������� �ʰ� ���������� ó���Ѵ�.
////�ܼ� ���Ḯ��Ʈ�� ��� ������ ����ü�� ����
//typedef struct ListNode {
//	int data;//������ ���
//	struct ListNode* link;//�ڱ����� ����ü, ���� ����� �ּҸ� ������ ���
//}listNode;
//
////����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
//typedef struct {
//	listNode* head;
//}linkedList_h;
//
//
//
//int main(void) {
//	listNode *head=(listNode*)malloc(sizeof(listNode));
//	listNode* node1=(listNode*)malloc(sizeof(listNode));//�Ҵ�� �޸� �ּ� �� ��� ����//�ڷ����� ��� �����ʹ�.
//	listNode* node2=(listNode*)malloc(sizeof(listNode));
//	listNode* node3=(listNode*)malloc(sizeof(listNode));
//	listNode* node4=(listNode*)malloc(sizeof(listNode));
//	listNode* node5=(listNode*)malloc(sizeof(listNode));
//	if (node1 == NULL)return;
//	if (node2 == NULL)return;
//	if (node3 == NULL)return;
//	if (node4 == NULL)return;
//	if (node5 == NULL)return;
//	if (head == NULL)return;
//	node1->link = NULL;//ó�� ������ �ʱ�ȭ �ܰ��̴�.
//	node1->data = 10;//������ �����Ͱ��� ��Ÿ����.
//	node2->data = 20;
//	node3->data = 0;
//	node4->data = 0;
//	node5->data = NULL;
//	
//	head->link = node1;//��� ����� ��ũ �ʵ尡 ��� 1�� �����Ͱ��� ���� �ּҰ��� ������ �Ѵ�.-->����尡 ù��° ��带 ����Ű�� �ִ�. LOE�����ڴ� ����ü ������ ���� �� ����� ����Ű�� ���� �����Ͱ��� ����Ѵ�.
//	node1->link = node2;
//	node2->link = node3;
//	node3->link = node4;
//
//	listNode* curr = head->link;//node1�� �����ּҰ� curr�� current�� ���ڷ� ���� ����Ű�� �ִ� ����� ���� ��Ÿ����.
//	while (curr != NULL) {//NULL�� ������ �ݺ����� ���� ���´�.
//		printf("%d\n", curr->data);
//		curr = curr->link;//�̰� ���� ����� ��ũ�� �ٰ����� ���� ���� ����Ű�� �ִ� ���� �����Ѱ��̴�.
//	}
//	free(head);
//	free(node1);
//	free(node2);
//	free(node3);
//	free(node4);
//	free(node5);
//	return 0;
//}