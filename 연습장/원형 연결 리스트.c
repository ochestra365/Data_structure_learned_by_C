#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

//리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
}h;

//공백 원형 연결 리스트를 생성하는 연산
h* createLinkedList_h(void) {
	h* CL;
	CL = (h*)malloc(sizeof(h));
	CL->head = NULL;//공백 리스트 이므로 NULL로 설정
	return CL;
}

//연결리스트를 순서대로 출력하는 연산
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

//첫 번째 노드 삽입 연산
void insertFirstNode(h* CL, char* x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head = NULL) {//원형 연결리스트가 공백인 경우
		CL->head = newNode;//새 노드를 리스트의 시작 노드로 연결
		newNode->link = newNode;
	}
	else {// 원형 연결리스트가 공백이 아닌 경우
		temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;//마지막 노드를 첫 번째 노드인 new와 원형 연결
		CL->head = newNode;
	}
}
//pre 뒤에 노드를 삽입하는 연산
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
//원형 연결 리스트의 pre뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(h* CL, listNode* old) {
	listNode* pre;//삭제할 노드의 선행자 노드를 나타내는 포인터
	if (CL->head == NULL)return;///공백 리스트인 경우 삭제 연산 중단
	if (CL->head->link == CL->head) {//리스트에 노드가 한 개만 있는 경우
		free(CL->head);//첫번째 노드의 메모리를 해제하고
		CL->head = NULL;//리스트 시작 포인터를 NULL로 설정
		return;
	}
}