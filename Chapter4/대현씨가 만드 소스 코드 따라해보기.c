#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct {
	Node* head;
}HeadNode;

HeadNode* createHead(void) {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)h->head = NULL;
	return h;
}

void preInserNode(HeadNode* h, int i) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = i;
		newNode->next = h->head;
		h->head = newNode;
	}
}

Node rearInserNode(HeadNode* h, int i) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* curr;

	if (newNode != NULL) {
		newNode->data = i;
		newNode->next = NULL;
		curr = h->head;
		if (h->head == NULL) {
			h->head = newNode;
			return;
		}
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

void Print_Node(HeadNode* h) {
	int i = 1;
	while (h->head != NULL) {
		printf("%d번째 노드 값 :%d\n", i++, h->head->data);
		h->head = h->head->next;
	}
}
