#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;//스택 원소의 자료형을 int로 정의
typedef struct stackNode {//스택의 노드를 구조체로 정의
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;//스택의 top노드를 지정하기 위해 포인터 top 선언

//스택이 공백 상태인지 확인하는 연산
int isEmpty() {
	if (top == NULL)return 1;
	else return 0;
}
//스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));//프로그램 실행 도중에 노드를 생성해야 하니까
	temp->data = item;//삽입 노드를 top의 위에 연결
	temp->link = top;//top 위치를 삽입 노드로 연결
	top = temp;
}
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {//스택이 공백리스트인 경우
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {//스택이 공백리스트가 아닌경우
		item = temp->data;
		top = temp->link;//top위치를 삭제 노드 아래로 이동
		free(temp);//삭제된 노드의 메모리 반환
		return item;//삭제된 원소 반환
	}
}
element peek() {
	if (top == NULL) {//스택이 공백리스트인 경우
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {//스택이 공백리스트가 아닌 경우
		return(top->data);//현재 top의 원소 반환
	}
}

//스택의 원소를 top에서 bottom순서로 출력하는 연산
void printStack() {
	stackNode* p = top;
	pritnf("\nSTACK[");
	while (p) {
		printf("%d", p->data);
		p = p->link;
	}
	printf("] ");
}
int main()
{
	element item;
	top = NULL;
	pritnf("\n** 연결 스택 연산 **\n");
	printStack();
	push(1); printStack();//1삽입
	push(2); printStack();//2삽입
	push(3); printStack();//3삽입

	item = peek(); printStack();//현재 top의 원소 출력
	printf("peek=>%d", item);

	item = pop(); printStack();//삭제
	printf("\t pop=>%d", item);

	item = pop(); printStack();//삭제
	printf("\t pop => %d", item);

	item = pop(); printStack();//삭제
	printf("\t pop=> %d", item);

	getchar();
	return 0;
}