#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct {
	Node* head;
}HeadNode;

HeadNode* creatHead(void);
void preInsertNode(HeadNode* h, int data);
void rearInserNode(HeadNode* h, int data);
void print_Node(HeadNode* h);
void delAllNode(HeadNode* h);
Node* searchNode(HeadNode* h, int data);
Node* delNode(HeadNode* h, Node* temp);
int main()
{
	HeadNode* h = creatHead();
	preInserNode(h, 10);
	return 0;
}
HeadNode* createHead(void) {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)h->head = NULL;
	return h;
}
//전위삽입: 3개의 노드가 있을 떄 맨 처음으로 가는 것.
void preInsertNode(HeadNode* h, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = h->head;//헤드가 가리키는 게 처음 노드자나
		h->head = newNode;//헤드를 통해서만 알 수 있네
	}
}
void rearInserNode(HeadNode* h, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
		if (h->head == NULL) {
			newNode->data = data;
			newNode->next = NULL;
			if (h->head == NULL) {
				h->head = newNode;
			}
			else {
				Node* curr = h->head;
				while (curr->next != NULL) {
					curr = curr->next;
				}
				curr->next = newNode;
			}
		}
	}
}
void print_Node(HeadNode* h) {
	if (h->head == NULL) {
		printf("\n현재 노드가 NULL입니다.\n");
		return;
	}
	Node* curr = h->head;
	int i = 1;
	while (curr != NULL) {
		printf("%d번째 노드 데이터 %d\n", i++, curr->data);
		curr = curr->next;
	}
}
void delAllNode(HeadNode* h)
{
	if (h->head == NULL) {
		printf("삭제할 리스트가 비어있스빈다.\n");
	}
	else {
		Node* curr = h->head;
		Node* temp;
		while (curr != NULL) {
			temp = curr->next;
			free(curr);
			curr = temp;
		}
		h->head = NULL;
		printf("삭제완료\n");
	}
}

Node* searchNode(HeadNode* h, int data) {
	Node* s = h->head;
	int i = 1;
	while (s != NULL) {
		if (s->data == data) {
			printf("찾은 값: %d번째 %d\n", i, s->data);
			return s;
		}
		else
		{
			s = s->next;
			i++;
		}
	}
	printf("찾는 값이 없습니다.\n");
	return s;
}

Node* delNode(HeadNode* h, Node* temp) {
	Node* curr;
	if (h == NULL) {
		printf("헤드가 NULL입니다.\n");
		return;
	}
	if (temp == NULL) {
		printf("검색한 노드가 NULL입니다.\n");
	}
	else if (h->head->next == NULL) {
		h->head = h->head->next;
		free(temp);
		return;
	}
	else {
		curr = h->head;
		if (curr == temp) {
			h->head = temp->next;
			free(temp);
			return;
		}
		while (curr->next != temp) {
			curr = curr->next;
		}
		curr->next = temp->next;
		free(temp);
	}
}