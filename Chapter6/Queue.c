#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4
typedef char element;//큐 원소(element)의 자료형을 char로 정의'
typedef struct {
	element queue[Q_SIZE];//1차원 배열 큐 선언
	int front, rear;
}QueueType;

//공백 순차 큐를 생성하는 연산
QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;//front 초깃값 설정
	Q->rear = -1;//rear 초깃값 설정
	return Q;
}
//순차 큐가 공백 상태인 지 검사하는 연산
int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("Queue is empty!");
		return 1;
	}
	else return 0;
}
//순차 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("Queue is full!");
		return 1;
	}
	else return 0;
}
//순차 큐의 rear에 원소를 삽입하느 연산
void enQueue(QueueType* Q, element item) {
	if (isFull(Q))return;//포화상태이면 삽입연산 중단
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}
//순차 큐의 front에서 원소를 삭제하는 연산
element deQueue(QueueType* Q) {
	if (isEmpty(Q))return;//공백상태이면 삭제연산 중단
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

//순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType* Q) {
	if (isEmpty(Q))exit(1);
	else return Q->queue[Q->front + 1];
}