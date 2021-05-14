#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];//멤버변수 순서도 중요하다. 왜냐하면 순서가 반대라면 공백리스트에서 연결할 수 없기 때문이다.
	struct ListNode* link;
}listnode;

//리스트 시작을 알리는 헤더파일 선언(공백리스트)
typedef struct {
	listnode* head;
}linkedList_h;

//공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {//입력값은 당연히 없다. 왜냐하면 데이터를 집어 넣어 줄 필요가 없기 때문이다.
	//Head는 첫번째 노드의 존재성을 확인시켜줄 것이다.
	linkedList_h* L=(linkedList_h*)malloc(sizeof(listnode));//공백리스트의 구조체 포인터를 동적으로 만들어 준다.
	if (L != NULL)L->head = NULL;
	return L;//L을 반환한다.
}
//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinked_h(linkedList_h* L) {//linkedList_h 초기 공백리스트가 모든 연결관계를 제어하는 사실을 알 수 있다. 왜냐하면 
	//link를 통해 헤더부분만 조작하면 나머지 부분도 수식이 가능하기 때문이다.
	listnode* p;//이것은 리스트 포인터가 지시할 파트이다.
	while (L->head != NULL) {//!=는 '존재한다'라는 것을 의미한다.
		p = L->head;//구조체 포인터에 L->head를 할당한다.
		L->head = L->head->link;
		free(p);
		p = NULL;//P값을 비워준다.
	}
}
//연결리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listnode* p;
	p = L->head;
	while (p != NULL)//p가 존재할 때까지, 연결관계가 존재할때까지
	{
		printf("L=(");
		printf("%s", p->data);//p의 데이터를 직접적으로 제어 
		p = p->link;//p의 다음 링크 그럼 다음 노드를 가리키게 된다.
		if (p != NULL)printf(", ");
		printf(")\n");
	}
}
// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(listnode));//삽입할 새노드 할당
	strcpy(newNode->data, x);//새 노드의 데이터 필드에 x저장
	newNode->link = L->head;
	L->head = newNode;
}

//노드를 pre뒤에 삽입하는 연산(이거 수업 때 배운 전위삽입)-->추론중 의심해볼것
void insertMiddleNode(linkedList_h *L ,listnode*pre,char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(linkedList_h));
	strcpy(newNode->data, x);
	if (L == NULL) {//공백리스트인 경우
		newNode->link = NULL;//새 노드를 첫번째이자 마지막 노드로 연결(왜냐하면 마지막 노드의 link값은 null이기 때문이다.)
		L->head = newNode;//새노드의 시작데이터 값
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;//포인터 rpe의 노드 뒤에 새 노드 연결
		pre->link = newNode;
	}
}
//마지막 노드로 삽입하는 연산(이거 수업때 배운 후위삽입)-->추론중 의심해볼것.
void insertLastNode(linkedList_h* L, char* x) {
	listnode* newNode;
	listnode* temp;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link = NULL;//마지막 노드의 link는 항상 NULL이다.
	if (L->head == NULL) {//현재 리스트가 공백인 경우.. 맞네 head가 없으면 아예 생성이 안되니까 리스트가 공백인 것을 의미하네.
		L->head = newNode;//새 노드를 리스트의 시작 노드로 연결
		return;
	}
	//현재 리스트가 공백이 아닌 경우-->노드가 있는 경우
	temp = L->head;
	while (temp->link != NULL)temp = temp->link;//현재 리스트의 마지막 노드를 찾음.
	temp->link = newNode;//새 노드를 마지막 노드의 다음 노드로 연결(후위 삽입?)
}
int main(void) {
	linkedList_h* L = createLinkedList_h();
	printf("(1) 공백 리스트 생성하기\n");
	printList(L); //이거는 말된다. 다음 노드의 첫 시작 데이터값을 불러오는 거기때문에 

	printf("(2) 리스트에 [수] 노드 삽입하기\n");
	insertFirstNode(L, "수");
	printList(L); //이거는 말된다. 다음 노드의 첫 시작 데이터값을 불러오는 거기때문에 

	printf("(3) 리스트 마지막에 [금] 노드 삽입하기 \n");
	insertLastNode(L, "금");
	printList(L);

	printf("(4) 리스트 첫 번째에 [월] 노드 삽입하기 \n");
	insertFirstNode(L, "월");
	printList(L);

	printf("(5) 리스트 공간을 해제하여 공백리스트로 만들기 \n");
	freeLinked_h(L);
	printList(L);
	return 0;
}