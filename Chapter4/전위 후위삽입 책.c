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

//공백 연결 리스트를 생성하는 연산(공백리스트는 하나의 리스트 열을 논리적으로 만든것이다. 여기는 제한이 없다!!!!
linkedList_h* createLinkedList_h(void) {//입력값은 당연히 없다. 왜냐하면 데이터를 집어 넣어 줄 필요가 없기 때문이다.
	//Head는 첫번째 노드의 존재성을 확인시켜줄 것이다.
	linkedList_h* L=(linkedList_h*)malloc(sizeof(listnode));//공백리스트의 구조체 포인터를 동적으로 만들어 준다.
	if (L != NULL)L->head = NULL;//공백리스트니까 NULL로 설정(역참조를 방지하는 것이다.)
	return L;//L을 반환한다.
}
//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinked_h(linkedList_h* L) {//linkedList_h 초기 공백리스트가 모든 연결관계를 제어하는 사실을 알 수 있다. 왜냐하면 
	//link를 통해 헤더부분만 조작하면 나머지 부분도 노드의 멤버변수인 link를 통해 수식이 가능하기 때문이다.
	listnode* curr;//이것은 리스트 포인터가 지시할 파트이다.
	while (L->head != NULL) {//!=NULL은 '존재한다'라는 것을 의미한다.
		curr = L->head;//구조체 포인터에 L->head를 할당한다. 현재 노드는 처음인데
		L->head = L->head->link;//이렇게 하면 실체는 우측이다. 인수분해를 생각하면 될 듯하다.(위치개념)
		free(curr);//메모리 할당을 풀어준다.
		curr = NULL;//P값을 비워준다. 현재 node의 link를 진공상태로 둔다고 보면 된다.
	}
}
//연결리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listnode* curr;
	printf("L=(");
	curr = L->head;//헤드가 정말 중요하다. 링크에 링크를 걸어서 계속 접근하는 것이다.
	while (curr != NULL)//p가 존재할 때까지, 연결관계가 존재할때까지
	{
		printf("%s", curr->data);//p의 데이터를 직접적으로 제어 
		curr = curr->link;//p의 다음 링크 그럼 다음 노드를 가리키게 된다.
		if (curr != NULL)printf(", ");
	}
	printf(")\n");
}
// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(listnode));//삽입할 새노드 할당
	strcpy(newNode->data, x);//새 노드의 데이터 필드에 x저장//문자배열을 받아서 데이터 필드에 저장한다.
	newNode->link = L->head;//처음 대입하면 첫번째이자 마지막 노드이기 때문에 link필드에 NULL값을 넣어주는 것이다.
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
		newNode->link = pre->link;//포인터 pre의 노드 뒤에 새 노드 연결
		pre->link = newNode;
	}
}
//마지막 노드로 삽입하는 연산(이거 수업때 배운 후위삽입)-->추론중 의심해볼것.
void insertLastNode(linkedList_h* L, char* x) {
	listnode* newNode;
	listnode* curr;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link = NULL;//마지막 노드의 link는 항상 NULL이다.
	if (L->head == NULL) {//현재 리스트가 공백인 경우.. 맞네 head가 없으면 아예 생성이 안되니까 리스트가 공백인 것을 의미하네.
		L->head = newNode;//새 노드를 리스트의 시작 노드로 연결
		return;
	}
	//현재 리스트가 공백이 아닌 경우-->노드가 있는 경우
	curr = L->head;
	while (curr->link != NULL)curr = curr->link;//현재 리스트의 마지막 노드를 찾음.
	curr->link = newNode;//새 노드를 마지막 노드의 다음 노드로 연결(후위 삽입?)
}
//리스트에서 노드 p를 삭제하는 연산
void deleteNode(linkedList_h* L, listnode* p) {
	listnode* curr;//삭제할 노드의 선행자 노드를 나타낼 포인터
	if (L->head == NULL)return;//공백 리스트라면 삭제 연산 중단
	if (L->head->link == NULL) {//리스트에 노드가 한 개만 있는 경우
		free(L->head);//첫 번쨰 노드를 메모리에서 해제하고
		L->head = NULL;//리스트 시작 포인터를 NULL로 설정
		return;
	}
	else if (p == NULL)return;
	else {//삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해 찾음
		curr = L->head;
		while (curr->link != p) {//맨마지막 노드는 NULL값이있거든? 그걸 시작주소값으로 처리때려 버리는 거고
			//여기는 삭제할 곳의 시작주소잖아
			curr = curr->link;//head부터 연결됨.
		}
		curr->link = p->link;//삭제할 노드 p의 선행자 노드와 다음 노드를 연결
		free(p);//삭제 노드의 메모리 해제
	}
}
//리스트에서 x노드를 탐색하는 연산
listnode* searchNode(linkedList_h *L, char* x) {
	listnode* temp;
	temp = L->head;//L->head를 조작해버리면 메인의 구조체포인터를 조작하는 거다. 그래서 temp값으로 찾아주는 거다. 메인은 소중하니까
	//공백리스트를 타고 넘어가게 해준다.
	while (temp != NULL) {//temp의 link파트는 NULL이다.//순차적으로 싹다 처음부터 끝까지 찾아볼건데
		if (strcmp(temp->data, x) == 0)return temp;//헤드에서 끝까지 논리지시자가 달리다가 서로 같은 값을 찾으면 그 그값을 반환한다.
		else temp = temp->link;//그게 아니라면 temp를 다음리스트의 시작주소값으로 옮긴다.
	}
	return temp;//만약 찾는 것이 없으면 NULL값을 반환한다.
	//if else 구문으로 해도 될것이다.
}
//리스트의 노드순서를 역순으로 바꾸는 연산
void resverse(linkedList_h* L) {
	listnode* p;
	listnode* q;
	listnode* r;

	p = L->head;//공백리스트
	q = NULL;//초기화
	L = NULL;//초기화

	//리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서 
	//노드 간의 연결을 바꿈
	while (p != NULL) {//NULL이 아닐때까지 연산을 돌린다.
		r = q;//노드 r은 노드 q가된다.
		q = p;//노드 q는 노드 p가 된다.
		p = p->link;//다음노드로 이동
		q->link = r;//노드 q의 다음 주소는 r이 된다. r->q->p //책 177쪽그림 참조-->이거는 상당히 어렵다.
	 }
	L->head = q;
}
int main(void) {//여기 밑은 그냥 어떻게 구현되는 가이지 중요한 파트는 아니지 싶다.
	linkedList_h* L = createLinkedList_h();
	listnode* p;
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
//책은 필요한 함수를 먼저 구현한다.
//그리고 그 기능들을 이용해서 메인을 순차적으로 쉽게 저장한다.
//알고 나면 별거 아니라는 말이 가장 ㅈ같은 말이다. 이거 혼자서 알기 까지 과정이 10시간 걸렸고, 책보니까 2시간 걸리는데 진짜 ㅈ같다
//아마 고단수랑 같이 하면 빨리 이해하는 게 내가 이해하는 게 아니라 알고 보니까 쉬워서 이말일거 같은데 앞으로 그런 말하면 돈까스를 먹어서 기분을 풀겠다