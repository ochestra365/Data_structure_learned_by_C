#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int isEmpty();
int isFull();
void enQueue(int);
int deQueue();

int rear = 0;
int front = 0;
int queue[SIZE];

int main() {

	return 0;
}
int isEmpty() {
	if (rear == front)return true;
	else return false;
}
int isFull() {
	if (front == (rear + 1) % SIZE)return true;
	else return false;
}