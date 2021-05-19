#include <stdio.h>
#include <stdlib.h>
//(헤더 노드 중간값 삽입 data)-->중간삽입 노드
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
		Node* curr = h->head;//순회노드가 링크타고 가면서 다음 노드들을 가리킨다.
		Node* temp;//삭제한 노드의 다음값을 저장할 링크
		while (curr != NULL) {//마지막 노드가 가리키는 값은 NULL이다. 그러니까 리스트를 죄다 돈 다는 말이다.
			temp = curr->next;//템프에 현재 노드가 가리키는 노드 주소값을 주고
			free(curr);//현재 노드를 지운다.
			curr = temp;//현재 노드에 삭제된 노드가 가리키는 주소값을 준다.
		}
		h->head = NULL;//마지막으로 리스트까지 지워준다.
		printf("삭제완료\n");
	}
}

Node* searchNode(HeadNode* h, int data) {
	Node* s = h->head;//무조건 링크타고 들어가기 때문에 노드의 시작을 알리는 것을 이용한다.
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
		return;//함수 내에서 return은 아래 연산을 시행하지 않겠다는 의미이다.
	}
	if (temp == NULL) {
		printf("검색한 노드가 NULL입니다.\n");
	}
	else if (h->head->next == NULL) {//리스트만 생성되어 있고 노드가 생성되어 있지 않다.
		h->head = h->head->next;
		free(temp);
		return;
	}
	else {
		curr = h->head;
		if (curr == temp) {//노드가 존재하지만 모든 리스트를 삭제하겠다.
			h->head = temp->next;
			free(temp);
			return;
		}
		while (curr->next != temp) {//삭제할 노드의 이전 노드까지 타고들어간다.
			curr = curr->next;
		}
		curr->next = temp->next;//삭제할 노드가 가리키는 주소값을 현재 노드의 주소값으로 준다.
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
		else if (p == NULL)printf("삽입할 노드를 만드세요");
		else {
			newNode->data = data;//초기화
			newNode->next = NULL;//초기화
			while (newNode->next != p->next) {
				newNode = h->head;//순서가 안된다. 순서대로 가르쳐줘야 한다.
				h->head = h->head->next;
				cnt++;
			}//순회하면서 순회횟수까지 만들어 볼라 했는데 실패다.
			p->next = newNode;//p값이 새 노드 가리킴
		}
		printf("%d번째 노드가 값은 생성 되었습니다. 데이터는 %d입니다.", cnt, data);
	}
}
//선생님이 작성한 코드
//if (newNode != NULL) {
//	newNode->data = data;
//	newNode->next = NULL;
//	if (h->head == NULL)h->head = newNode;
//	else if (p == NULL)printf("삽입할 위치를 찾으 수 없다.");
//	else {
//	newNode->next=p->next; //순서가 중요하다.
//	p->next=newNode;
//	}
//}