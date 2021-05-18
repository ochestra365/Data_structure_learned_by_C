#define _CRT_SEUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>//�� ������ �������ִ� C�� ���

#define STACK_SZ	3//��ó��
//#define TRUE	1
//#define FALSE	2
//���� �⺻ �Լ�
int isEmpty(void);//���� üũ(���� ������ ������ ������ִ�.)
int isFull(void);//��ȭüũ(���� ������ ������ ä���� �ִ�.)
void push(int);//���ÿ� �Է�
int pop(void);//���ÿ� ���
int peek(void);//������ ���� Ȯ��
void printStack(void);
int stack[STACK_SZ];
int top = -1;//���� ������ ��ġ�� ��Ÿ���� ���̴�. ���ÿ� �� ���� �����Ͱ� �ԷµǾ� �ִ� �� Ȯ�ε� �����ϴ�. �׻� �� ���� ����Ų��.
//���� ������ ���� ������ �ִ� ���� �巯����.

int main() {

	return 0;
}

int isEmpty() {
	if (top <= -1)return true;
	else return false;
}

int isFull() {
	if (top >= STACK_SZ - 1) return true;//���� ���� true���� ��ȯ
	else return false;
}

void push(int data) {
	if (isFull()) {
		printf("STACK overflow!!\n");
		return;
	}
	else {//0���� ���� index���������� ����Ѵ�
		stack[++top] = data; //top=-1 1 ���� ��Ű�� �� ���� ���꿡 ����Ѵ�. ���Ҹ� �ְ� ���� �Ǵ��ؾ� �Ѵ�.
	}
}

int pop() {//����������� �˾ƾ� �Ѵ�.
	if (isEmpty()) {
		printf("STACK underflow");
		return;
	}
	else {
		return stack[top--];//-1 ����ϰ� ���� -1�� ����� �Ѵ�. ���Ҹ� ���� ���� �Ǵ��ؾ� �Ѵ�.
	}
}
int peek() {
	if (isEmpty()) {
		printf("STACK underflow!!\n");
		exit(1);
	}
	else return stack[top];
}