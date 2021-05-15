//å
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
}
int main() {

	return 0;
}