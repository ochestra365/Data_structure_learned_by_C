//책
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data[4];
	struct node* next;
}Node;

typedef struct {
	Node* head;
}Head;
Head CreateHead() {
	Head* h = (Head*)malloc(sizeof(Node));
}
void freelink(Head* L) {
	Node* curr;
	while (L->head != NULL) {
		curr = L->head;
		L->head = L->head->next;
		free(curr);
		curr = NULL;
	}
}
void printList(Head* L) {
	Node* curr;
	printf("L=(");
	curr = L->head;
	while (curr != NULL) {
		printf("%s", curr->data);
		curr = curr->next;
		if (curr != NULL)printf(", ");
	}
	printf(")\n");
}
void insertFirstNode(Head* L, char* x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, x);
	newNode->next = L->head;
	L->head = newNode;
}
void insertMiddleNode(Head* L, Node* pre, char* x) {
	Node* newNode = (Node*)malloc(sizeof(Head));
	strcpy(newNode->data, x);
	if (L == NULL) {
		newNode->next = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->next = pre->next;
		pre->next = newNode;
	}
}
void inserLastNode(Head* L, char* x) {
	Node* newNode;
	Node* curr;
	newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, x);
	newNode->next = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	curr = L->head;
	while (curr->next != NULL)curr = curr->next;
	curr->next = newNode;
}
void deleteNode(Head* L, Node* P) {
	Node* curr;
	if (L->head == NULL)return;
	if (L->head->next == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (P == NULL)return;
	else {
		curr = L->head;
		while (curr->next != P) {
			curr = curr->next;
		}
		curr->next = P->next;
		free(P);
	}
}
Node* searchNode(Head* L, char* x) {
	Node* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)return temp;
		else temp = temp->next;
	}
	return temp;

}
void reverse(Head* L) {
	Node* p;
	Node* q;
	Node* r;
	p = L->head;
	q = NULL;//메모리초기화
	L = NULL;//메모리초기화
	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;//구조체의 필드만 바꿔주는 것이다.
	}
	L->head = q;
}
int main() {
	//출력부분
	return 0;
}