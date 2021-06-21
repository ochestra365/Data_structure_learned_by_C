#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;//statck 원소

element statck[STACK_SIZE];//1차원 배열 스택 선언
int top = -1;//top 초기화

//스택이 공백 상태인지 확인하는 연산
int isEmpty() {
	if (top == -1)return 1;
	else return 0;
}

//스택이 포화상태인 지 확인하는 연산
int isFull() {
	if (top == STACK_SIZE - 1)return 1;
	else return 0;
}
//스택의 top에 원소를 삽입하는 연산
void push(element item) {
	if (isFull()) {//스택이 포화상태인 경우
		printf("\n\n Stack is overflow");
		return;
	}
	else stack[++top] = item;//top을 증가시킨 이후 현재 top에 원소 삽입
}
//스택의 top에서 원소를 삭제하는 연산
element pop() {
	if (isEmpty()) {
		printf("\n\n Stack is Underflow!!\n");
		return 0;
	}
	else return statck[top--];//현재 top의 원소를 삭제한 후 top감소
}
//스택의 top원소를 검색하는 연산
element peek() {
	if (isEmpty()) {
		printf("\n\n Stack is underflow\n");
		exit(1);
	}
	else return stack[top];//현재 top의 원소 확인
}

//스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\nSTACK[");
	for (i = 0; i <= top; i++) {
		printf("%d", stack[i]);
	}
	prinf("]");
}

void main(void) {
	element item;
	printf("\n** 순차 스택 연산**\n");
	printStack();
	push(1); PrintStack();//1삽입
	push(2); PrintStack();//2삽입
	push(3); PrintStack();//3삽입

	item = peek(); printStack();//현재 top의 원소 출력
	printf("peek =>%d", item);
	item = pop(); printStack();//삭제
	printf("\t pop=>%d", item);
	item = pop(); printStack();//삭제
	printf("\t pop=>%d", item);
	item = pop(); printStack();//삭제
	printf("\t pop=>%d", item);
	getchar();
	return 0;
}

