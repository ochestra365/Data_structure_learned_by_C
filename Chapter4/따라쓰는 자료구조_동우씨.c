#include <stdio.h>
#include <stdlib.h>
//(��� ��� �߰��� ���� data)-->�߰����� ���
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
void midInserNode(HeadNode* h, Node* p, int data);
Node* searchNode(HeadNode* h, int data);
Node* delNode(HeadNode* h, Node* temp);
int main()
{
	HeadNode* h = creatHead();
	Node* a = preInserNode(h, 10);
	Node* b = preInserNode(h, 20);
	Node* c = preInserNode(h, 30);
	midInserNode(h, b, 40);
	return 0;
}
HeadNode* createHead(void) {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)h->head = NULL;
	return h;
}
//��������: 3���� ��尡 ���� �� �� ó������ ���� ��.
void preInsertNode(HeadNode* h, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = h->head;//��尡 ����Ű�� �� ó�� ����ڳ�
		h->head = newNode;//��带 ���ؼ��� �� �� �ֳ�
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
		printf("\n���� ��尡 NULL�Դϴ�.\n");
		return;
	}
	Node* curr = h->head;
	int i = 1;
	while (curr != NULL) {
		printf("%d��° ��� ������ %d\n", i++, curr->data);
		curr = curr->next;
	}
}
void delAllNode(HeadNode* h)
{
	if (h->head == NULL) {
		printf("������ ����Ʈ�� ����ֽ����.\n");
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
		printf("�����Ϸ�\n");
	}
}

Node* searchNode(HeadNode* h, int data) {
	Node* s = h->head;
	int i = 1;
	while (s != NULL) {
		if (s->data == data) {
			printf("ã�� ��: %d��° %d\n", i, s->data);
			return s;
		}
		else
		{
			s = s->next;
			i++;
		}
	}
	printf("ã�� ���� �����ϴ�.\n");
	return s;
}

Node* delNode(HeadNode* h, Node* temp) {
	Node* curr;
	if (h == NULL) {
		printf("��尡 NULL�Դϴ�.\n");
		return;
	}
	if (temp == NULL) {
		printf("�˻��� ��尡 NULL�Դϴ�.\n");
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

void midInserNode(HeadNode* h, Node* p, int data) {
	int cnt = 0;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		if (h->head == NULL) {
			h->head = newNode;
		}
		else if (p == NULL)printf("������ ��带 ���弼��");
		else {
			newNode->data = data;//�ʱ�ȭ
			newNode->next = NULL;//�ʱ�ȭ
			while (newNode->next != p->next) {
				newNode = h->head;//������ �ȵȴ�. ������� ��������� �Ѵ�.
				h->head = h->head->next;
				cnt++;
			}//��ȸ�ϸ鼭 ��ȸȽ������ ����� ���� �ߴµ� ���д�.
			p->next = newNode;//p���� �� ��� ����Ŵ
		}
		printf("%d��° ��尡 ���� ���� �Ǿ����ϴ�. �����ʹ� %d�Դϴ�.", cnt, data);
	}
}
//�������� �ۼ��� �ڵ�
//if (newNode != NULL) {
//	newNode->data = data;
//	newNode->next = NULL;
//	if (h->head == NULL)h->head = newNode;
//	else if (p == NULL)printf("������ ��ġ�� ã�� �� ����.");
//	else {
//	newNode->next=p->next; //������ �߿��ϴ�.
//	p->next=newNode;
//	}
//}