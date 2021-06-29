#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

//�׷����� ���� ���� ����Ʈ�� ��� ���� ����
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;//���� ����
	graphNode* adjList_H[MAX_VERTEX];//������ ���� ���� ����Ʈ�� ����� �迭
	int visited[MAX_VERTEX];//������ ���� �湮ǥ�ø� ���� �迭
}graphNode;

//<<����(5�忡�� ������ ���� ����Ʈ�� �̿��� ���ÿ��� ����)
typedef int element;

typedef struct stackNode {
	int data;//data �ʵ��� �ڷ����� int�� ����
	struct stackNode* link;
}stackNode;

stackNode* top;

//������ ������ �� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL)return 1;
	else return 0;
}
void push(int item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop() {
	int item;
	stackNode* temp = top;

	if (isEmpty()) {
		printf("\n\nUnderflow\n\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}//����>>

//���� �켱 Ž���� ���� �ʱ� ���� �׷����� �����ϴ� ����
void createGraph(graphType* g) {
	int v;
	g->n = 0;//�׷����� ���� ������ 0���� �ʱ�ȭ
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;//�׷����� ������ ���� �迭 visited�� FALSE�� �ʱ�ȭ
		g->adjList_H[v] = NULL;//���� ����Ʈ�� ���� ��� ��� �迭�� NULL�� �ʱ�ȭ
	}
}
//�׷��� g�� ���� v�� �����ϴ� ���� :
void insertVertex(graphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTEX) {
		printf("\n�׷����� ������ ������ �ʰ��ߴ�.");
		return;
	}
	g->n++;
}
//�׷��� g�� ���� (u,v)�� �����ϴ� ����:
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n�׷����� ���� �����Դϴ�.");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}
//�׷��� g�� �� ������ ���� ���� ����Ʈ�� ����ϴ� ����
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t ���� %c�� ��������Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("->%c", p->vertex + 65);
			p = p->link;
		}
	}
}
//�׷��� g���� ���� v�� ���� ���� �켱 Ž�� ����
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;//������ top����
	push(v);//���� �켱 Ž���� �����ϴ� ���� v�� ���ÿ� push
	g->visited[v] = TRUE;//���� v�� �湮�����Ƿ� �ش� �迭���� TRUE�� ����
	printf("%c", v + 65);
	while (!isEmpty()) {
		v = pop();
		w = g->adjList_H[v];
		//���� ������ �ִ� ���� ����
		while (w) {
			//���� ���� w�� �湮���� ���� ���
			if (!g->visited[w->vertex]) {
				if (isEmpty())push(v);//���� v�� ���ƿ� ��츦 ���� �ٽ� push�Ͽ� ����
				push(w->vertex);//���� ���� w�� ���ÿ� Ǫ��
				g->visited[w->vertex] = TRUE;//���� w�� ���� �迭���� TRUE�� ����
				pritnf("%c", w->vertex + 65);//���� 0~6�� A~G�� �ٲ㼭 ���
				v = w->vertex;
				w = g->adjList_H[v];
			}
			//���� ���� w�� �̹� �湮�� ���
			else w = w->link;
		}//while(w)
	}//������ �����̸� ���� �켱Ž�� ����
}

void main() {

	//�ʹ� ���Ƽ� ����
}