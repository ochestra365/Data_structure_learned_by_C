#include <stdio.h>
typedef struct node {//노드를 생성할 구조체 선언->구조체는 논리적으로 하나의 노드이다.
	int data;//제 1멤버 인트형 자료형을의 데이터를 선언한다.
	struct node* link;//자기참조 구조체
}Node;//구조체 명 선언
//가장 먼저 함수의 기능부터 파악하는 것이 전체 코드의 우선이다.
void addNode(Node* target, int data) {//기능을 일컫는다. 전이함수다. 맨앞으로 새로운 함수를 생성시키는 함수다.
	Node* newNode=(Node*)malloc(sizeof(Node));//malloc으로 동적으로 할당한다. 그리고 그 값을 구조체 포인터에 넣는다.
	//newNode는 다른 메모리에서 만들어진 노드이다.
	//해당 노드는 함수내에서 실행할 템프노드이다. 힙영역에 저장은 되겠지만 연산 자체는 스택에서 휘발해버리는 논리구조를 가지고 있는 함수라는 것을 수 있다.
	newNode->data = data;//템프 노드는 data 매개변수를 메인 렘으로부터 받아서 데이터를 가리킨다.
	newNode->link = target->link;//타게팅되는 노드의 링크값을 새로운 노드의 link값에 할당한다.
	target->link = newNode;//템프 노드의 시작 주소값을 link값에 넣는다. 그리고 마무리 연산 후에 함수에 반환한다.
	//반환값이 존재하지 않기 때문에 메인에서는 반환값을 따로 저장할 구조체가 필요하다.
	//최종적으로 반환된 링크값은 newNode의 data값과 link값이 저장된다. 그리고 이 함수는 연산이 끝난 후 모든 데이터가 스택영역에
	//할당되어 있으므로 휘발되어 버린다.
}

int main(void) {
	int i;
	//함수를 반환받은 값을 저장할 변수 생성파트
	Node* head=(Node*)malloc(sizeof(Node));//초기 노드 생성
	Node* node1=(Node*)malloc(sizeof(Node));//node1을 생성
	Node* node2=(Node*)malloc(sizeof(Node));//node2를 생성
	Node* node3=(Node*)malloc(sizeof(Node));//node3을 생성
	Node* node4=(Node*)malloc(sizeof(Node));//node4을 생성
	Node* node5=(Node*)malloc(sizeof(Node));//node5를 생성
	// 노드 생성 파트
	//초기화를 시켜주는 것이다.
	head->link = NULL;
	node1->data = 10;
	node2->data = 20;
	node3->data = 30;
	node4->data = 40;
	node5->data = 50;
	// 함수를 저장할 파트

	
	//출력파트

	free(head);//힙영역반환
	free(node1);//힙영역반환
	free(node2);//힙영역반환
	free(node3);//힙영역반환
	free(node4);//힙영역반환
	free(node5);//힙영역 반환
	return 0;
}