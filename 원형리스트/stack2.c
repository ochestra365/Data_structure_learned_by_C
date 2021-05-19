#include <stdio.h>
#include <stdbool.h>
//LiquidList(연결자료구조)
typedef struct snode {
	int data;
	struct snode* link;
}Snode;

typedef struct {
	Snode* topstk;
}TStack;//상태값을 드러낸다.

TStack* createHead(void) {
	TStack* T = (TStack*)malloc(sizeof(TStack));
	if (T != NULL)T->topstk = NULL;//스택리스트가 존재하면
	return T;
}
int isEmpty(TStack* ptstack) 
{
	if (ptstack->topstk == NULL) return true;
	else return false;
}
void push(TStack* ptstc, int data) {
	Snode* newNode = (Snode*)malloc(sizeof(Snode));
	if (newNode == NULL)return;
	newNode->data = data;
	newNode->link = ptstc->topstk;//윗노드가 아랫노드를 가리키게 해야 한다. 그래야 윗노드를 삭제해도 아무 문제가 없다. 헤드에 있는 필드에 들어가 있는 값을 새로운 노드의 링크에 저장
	//top은 상태를 나타낸다.
	//그리고 그림 그려보면 위 쪽 데이터를 없애야 아랫쪽데이터를 확인하거나 없앨 수 있는데, 이는 데이터의 무결성을 위한것이다.
	//pop시 아래에서 위를 가리키면 NULL값을 가리키게 된다.
	ptstc->topstk = newNode;//새로운 노드를 통해서 다음 노드를 참조할 수 있도록 상태값을 맨위의 노드에 할당한다.
}
int pop(TStack* ptstack) 
{
	int data;
	Snode* temp;
	if (isEmpty(ptstack)) {
		printf("STACK is EMPTY!\n");
		return;//아래 연산을 시행하지 않으려고 하면 return값을 줘서 함수의연산을 종료시킨다.
	}
	else {//이거 분석해보기
		data = ptstack->topstk->data;//data 값에 맨 위 노드 데이터값을 넣어준다.
		temp = ptstack->topstk;//temp값에 주소값을 넣는다.-->이건 상태를 나타낸다.
		//지금 템프가 가리키고 있는 메모리는 가장 위에 있는 노드를 의미한다.
		ptstack->topstk = ptstack->topstk->link;//맨 위 탑 헤더에 링크를 넣어준다. 논리적으로 탑의 상태를 변경해주고 기존의 탑은 제거해버림
		free(temp);//템프를 반환한다는 것이 맨 위의 노드를 해제한다는 것이다.
		//컴퓨터에서는 메모리 힙영역에 할당된 범위를 날려버리는 것이기 때문이다. 
		return data;//data를 휘발시켜버림
	}
}
int peek(TStack* ptstack) {
	if (isEmpty(ptstack)) {
		printf("STACK EMPTY!!\n");
		return;
	}
	else {
		return ptstack->topstk->data;//data를 넣는다. 가장 상단에 있는 노드의 데이터를 가리킨다.
	}
}
void printStack(TStack* ptstack) {
	Snode* curr = ptstack->topstk;//맨 위의 노드에서 순회하면서 아래로 간다.
	while (curr != NULL) {//참조의 마지막은 NULL이다. 왜냐하면 가리키는 게 아무것도 없기 때문이다.
		printf("%d\n", curr->data);
		curr = curr->link;
	}

}
int main() {
	TStack* h = createHead();
	push(h, 10);
	push(h, 20);
	push(h, 30);
	push(h, 40);
	printStack(h);
	pop(h);
	printStack(h);
	return 0;
}