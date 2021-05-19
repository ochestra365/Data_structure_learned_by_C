#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define STACK_SZ
int isEmpty(void);
int isFull(void);
void push(int);
int pop(void);
int peek(void);
void printStack(void);
int stack[STACK_SZ];
int top = -1;
int main() {

	return 0;
}
int isEmpty() {
	if (top <= -1)return true;
	else return false;
}
int isFull() {
	if (top >= STACK_SZ - 1)return true;
	else return false;
}
void push(int data) {
	if (isFull()) {
		printf("STACK overflow\n");
		return;
	}
	else {
		stack[++top] = data;
	}
}
int pop() {
	if (isEmpty()) {
		printf("STACK underflow");
		return;
	}
	else {
		return stack[top--];
	}
}
int peek() {
	if (isEmpty()) {
		printf("STACK underflow\n");
		exit(1);
	}
	else return stack[top];
}

void