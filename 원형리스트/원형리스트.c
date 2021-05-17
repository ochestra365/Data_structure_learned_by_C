#include <stdio.h>
//원형에서는 헤더가 마지막 노드를 가리키게 한다. 그래야만 마지막 노드의 정보를 찾아가기 쉽다.
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
//void printNode(HeadNode* phead);//만들기
int main() {
	HeadNode* h = createHead();//헤더 생성
	Node* A = createNode(h, 10);
	Node* B = createNode(h, 20);
	Node* C = createNode(h, 30);
	Node* D = createNode(h, 40);
	Node* E = createNode(h, 50);//노드 생성
	insertFirstNode(h, A);//초항 생성(초항이 원형)
	return 0;
}
HeadNode* createHead() {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));//헤드노드 구조체 포인터의 사이즈는 헤드노드 만큼이어야 한다.
	if (h != NULL)h->head = NULL;
	return h;
}
Node* createNode(HeadNode* phead, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));//힙 영역에 리스트 크기만큼 저장할 수 있는 만큼 할당받고, 그 값을 리턴 받는다.
	if (newNode == NULL) {
		printf("메모리 할당 실패");
		return;
	}
	else {
		newNode->data = data;
		newNode->link = NULL;//만들어진 노드는 그 어떤 것도 가리키지 않은 관계성이 없는 것이다.
		return newNode;
	}
}
void insertFirstNode(HeadNode* phead, Node* newNode) {//수열의 초항
	if (phead->head == NULL) {//공백리스트일 때
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
	if (phead->head == NULL) {//공백리스트일 때
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head;//마지막 노드를 가리키면 curr노드를 따로 만들어서 움직일 필요가 없다.
		while (phead->head != NULL) {
			//tempNode = tempNode->link;
			phead->head = phead->head->link;//모든 링크값들이 최종적으로 반복을 빠져나와 반환된다.
		}
		//tempNode->link = newNode;
		//newNode->link = phead->head;
		phead->head = newNode;//마지막 노드가 첫번째 노드
	}
}
//node1 이 헤더 역할을 한다.
//void printNode(HeadNode* phead) {
//
//}