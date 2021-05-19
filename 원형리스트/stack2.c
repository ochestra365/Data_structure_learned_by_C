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
	ptstc->topstk = newNode;
}
int pop(TStack* ptstack) 
{
	int data;
	Snode* temp;
	if (isEmpty(ptstack)) {
		printf("STACK is EMPTY!\n");
		return;
	}
	else {//이거 분석해보기
		data = ptstack->topstk->data;//data 값에 맨 위 노드값을 넣어준다.
		temp = ptstack->topstk;//temp값에 주소값을 넣는다.
		ptstack->topstk = ptstack->topstk->link;//맨 위 탑 헤더에 링크를 넣어준다. 논리적으로 탑의 상태를 변경해주고 기존의 탑은 제거해버림
		free(temp);//템프 반환
		return data;//data를 휘발시켜버림
	}
}
int peek(TStack* ptstack) {
	if (isEmpty(ptstack)) {
		printf("STACK EMPTY!!\n");
		return;
	}
	else {
		return ptstack->topstk->data;//data를 넣는다.
	}
}
void printStack(TStack* ptstack) {
	Snode* curr = ptstack->topstk;
	while (curr != NULL) {
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