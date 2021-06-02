#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

//리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
}h;

//공백 연결 리스트를 생성하는 연산
h* createLinkedList_h(void) {
	h* L;
	L = (h*)malloc(sizeof(h));
	if(L!=NULL)L->head = NULL;//공백리스트이므로 NULL로 설정. 역참조라는 것은 논리의 비교대상이 없을 때 발생한다.
	return L;
}
//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedLsit_h(h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
//연결리스트를 순서대로 출력하는 연산
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
void insertFirstNode(h* L, char* x) {//전위삽입
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
//마지막 노드로 삽입하는 연산
void insertLastNode(h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {//현재 리스트가 공백인 경우
		L->head = newNode;//새 노드를 리슽의 시작 노드로 연결
		return;
	}
	//현재 리스트가 공백이 아닌 경우
	temp = L->head;
	while (temp->link != NULL)temp = temp->link;//현재 리스트의 마지막 노드를 찾음
	temp->link = newNode;//새 노드를 마지막 노드(temp)의 다음 노드로 연결
}
//리스트에서 노드 p를 삭제하는 연산
void deleteNode(h* L, listNode* p) {
	listNode* pre;//삭제할 노드의 선행자 노드를 나타낼 포인터
	if (L->head == NULL)return;//공백 리스트라면 삭제 연산 중단.
	if (L->head->link == NULL) {//리스트에 노드가 한 개만 있는 경우
		free(L->head);//첫 번째 노드를 메모리에서 해제하고
		L->head = NULL;//리스트 시작 포인터를 NULL로 설정
	}
	else if (p == NULL)return;//삭제할 노드가 없다면 삭제 연산 중단
	else {//삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해 찾음
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;//삭제할 노드 p의 선행자 노드와 다음 노드를 연결
		free(p);//삭제 노드의 메모리 해제
	}
}
//리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)return temp;
		else temp = temp->link;
	}
	return temp;
}
// 리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;//포인터 p를 첫 번째 노드에 설정
	q = NULL;
	r = NULL;

	//리스트의 첫 번쨰 노드부터 링크를 따라 다음 노드로 이동하면서
	//노드 간의 연결을 바꿈
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
	printf("(1) 공백 리스트 생성하기\n");
	printList(L); getchar();

	printf("(2) 리스트에 [수] 노드 삽입하기!\n");
	insertFirstNode(L, "수");
	printList(L); getchar();

	printf("(3) 리스트 마지막에 [금] 노드 삽입하기!\n");
	insertLastNode(L, "금");
	printList(L); getchar();

	printf("(4)리스트의 첫번째에 [월]노드 삽입하기!\n");
	insertFirstNode(L, "월");
	printList(L); getchar();

	printf("(5)리스트 공간을 해제하여 공백리스트로 만들기\n");
	freeLinkedLsit_h(L);
	printList(L);

	getchar();
	return 0;
}