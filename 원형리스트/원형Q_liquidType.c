#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define SIZE 5
int queue[SIZE];
//함수선언
int isEmpty();
int isFull();

Qnode queue_ary[SIZE];

typedef struct qnode {
	int data;
	int rear, front;
}Qnode;

void initQueue(Qnode* pq) {
	pq->data = 0;
	pq->front = 0;
	pq->rear = 0;
}
int isEmpty(Qnode* pq) {
	if (pq->front == pq->rear)return true;
	else return false;
}
int isFull(Qnode* pq) {
	if (pq->front == (pq->rear + 1) % SIZE)return true;//논리적으로 방을 만들어주는 것이다.
	else return false;
}
void enQueue(Qnode* pq, int data) {
	if (isFull(pq)) {
		printf("~~");
		return;
	}
	else {
		queue[(pq->rear++) % SIZE] = data;
	}
}
void deQueue(Qnode* pq, Qnode* target) {
	if (isEmpty(pq)) {
		printf("underflow");
		return;
	}
	else {
		queq
	}
}
int main(void) {
	Qnode pq;
	initQueue(&pq);
	return 0;
}



