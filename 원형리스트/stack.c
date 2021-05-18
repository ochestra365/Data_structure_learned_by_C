#define _CRT_SEUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>//참 거짓을 지원해주는 C의 언어

#define STACK_SZ	3//전처리
//#define TRUE	1
//#define FALSE	2
//스택 기본 함수
int isEmpty(void);//공백 체크(스택 단위가 완전히 비워져있다.)
int isFull(void);//포화체크(스택 단위가 완전히 채워져 있다.)
void push(int);//스택에 입력
int pop(void);//스택에 출력
int peek(void);//맨위의 스택 확인
void printStack(void);
int stack[STACK_SZ];
int top = -1;//현재 스택의 위치를 나타내는 것이다. 스택에 몇 개의 데이터가 입력되어 있는 지 확인도 가능하다. 항상 맨 위를 가리킨다.
//스택 원소의 가장 맨위에 있는 값을 드러낸다.

int main() {

	return 0;
}

int isEmpty() {
	if (top <= -1)return true;
	else return false;
}

int isFull() {
	if (top >= STACK_SZ - 1) return true;//가득 차면 true값을 반환
	else return false;
}

void push(int data) {
	if (isFull()) {
		printf("STACK overflow!!\n");
		return;
	}
	else {//0으로 만들어서 index변수값으로 사용한다
		stack[++top] = data; //top=-1 1 증가 시키고 그 값을 연산에 사용한다. 원소를 넣고 나서 판단해야 한다.
	}
}

int pop() {//공백상태인지 알아야 한다.
	if (isEmpty()) {
		printf("STACK underflow");
		return;
	}
	else {
		return stack[top--];//-1 사용하고 나서 -1을 빼줘야 한다. 원소를 빼고 나서 판단해야 한다.
	}
}
int peek() {
	if (isEmpty()) {
		printf("STACK underflow!!\n");
		exit(1);
	}
	else return stack[top];
}