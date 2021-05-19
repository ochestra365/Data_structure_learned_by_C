#define _CRT_SEUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>//참 거짓을 지원해주는 C의 언어
//브라우저에서 창이 닫히면 현재 창이 닫히고 다음 창이 닫히는 것이다.
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
int stack[STACK_SZ];//스택 생성
int top = -1;//현재 스택의 위치를 나타내는 것이다. 스택에 몇 개의 데이터가 입력되어 있는 지 확인도 가능하다. 항상 맨 위를 가리킨다. 그냥 배열요소의 인덱스 값을 드러내는 상태값이다.
//스택 원소의 가장 맨위에 있는 값을 드러낸다.//배열 이용하니까

int main() {
	push(10);
	push(11);
	push(12);
	pop();
	push(13);
	printStack();
	return 0;
}

int isEmpty() {
	if (top <= -1)return true;//비어 있냐는 함수의 질문에 참이라고 대답함
	else return false;//비어 있냐는 함수의 질문에 아니라고 대답함
}

int isFull() {
	if (top >= STACK_SZ - 1) return true;//스택 사이즈만큼 차있으면 가득 차 있냐는 함수의 질문에 그렇다고 대답함.
	else return false;//스택 사이즈만큼 차있으면 가득 차 있냐는 함수의 질문에 아니라고 대답함.
}

void push(int data) {
	if (isFull()) {//일단 넣기 전에 가득 차 있는 지 아닌 지 확인
		printf("STACK overflow!!\n");//가득 차 있으면 해당 출력값을 반환함.
		return;//에러가 뜨면 그 아래 명령문들은 실행이 안되야 해서 return 을 시킨다.
	}
	else {//0으로 만들어서 index변수값으로 사용한다
		stack[++top] = data; //top=-1 1 증가 시키고 그 값을 연산에 사용한다. 원소를 넣고 나서 판단해야 한다. 배열에 사용하려고
	}
}

int pop() {//공백상태인지 알아야 한다.
	if (isEmpty()) {//일단 빼기 전에 공백인 지 아닌 지 확인
		printf("STACK underflow");//비어 있으면 해당 출력값을 반환함
		return;
	}
	else {
		return stack[top--];//-1 사용하고 나서 -1을 빼줘야 한다. 원소를 빼고 나서 판단해야 한다. 이전 배열요소를 반환하니까 지금 배열요소는 휘발되어 버림.
		//맨위의 원소를 뺴고나서 카운트를 감해주는 것이다.(배열이용)
	}
}
int peek() {
	if (isEmpty()) {//비어 있느냐 
		printf("STACK underflow!!\n");
		exit(1);//프로그램 종료A
	}
	else return stack[top];//가장 위에 있는 탑값을 반환
}
void printStack() {
	if (!isEmpty()) {
		for (int i = 0; i <= top; i++) {
			printf("%d   ", stack[i]);
		}
	}
}

//스택 구조를 순차자료구조에 의해서 만든 것이다.
//메모리에는 각 결과값이 저장되어 있는 데, 논리적으로는 넣고 빼고가 되는 거다.