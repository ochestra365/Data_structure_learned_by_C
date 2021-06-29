#include <stdiol.h>
#include <memormy.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

// �׷����� ���� ���� ����Ʈ�� ��� ���� ����
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;
typedef struct graphType {
	int n;//���� ����
	graphNode* adjList_H[MAX_VERTEX];//������ ���� ���� ����Ʈ�� ��� ��� �迭
	int visited[MAX_VERTEX];//������ ���� �湮 ǥ�ø� ���� �迭
}graphType;
typedef int element;

//<<ť(6�忡�� ������ ���Ḯ��Ʈ�� �̿��� ť ����>>
typedef struct QNode {
	int data;//data �ʵ��� �ڷ����� int�� ����
	struct QNode* link;
}QNode;
typedef struct {
	QNode* front, * rear;
}LQueueType;

LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}
int isEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf("\n Underflow\n");
		return 1;
	}
	return 0;
}
void enQueue(LQueueType* LQ, int item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
int deQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	int item;
	if (isEmpty(LQ))return 0
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL) LQ->rear = NULL;
		free(old);
		return item;
	}
}//ť

//�ʺ� �켱 Ž���� ���� �ʱ� ���� �׷����� �����ϴ� ����
void createGraph(graphType* g) {
	int v;
	g->n = 0;//�׷����� ���� ������ 0���� �ʱ�ȭ
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;//�׷����� ������ ���� �迭 visited�� FALSE�� �ʱ�ȭ
		g->adjList_H[v] = NULL;//���� ����Ʈ�� ���� ��� ��� �迭�� NULL�� �ʱ�ȭ
	}
}
//�׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTEX) {
		printf("\n �׷��� ������ ������ �ʰ��߽��ϴ�.");
		return;
	}
	g->n++;
}
//�׷��� g�� ���� (u,v)�� �����ϴ� ����
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
//�׷��� g�� ���� ���� ����Ʈ�� ����ϴ� ����
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t���� %c�� ��������Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("-> %c", p->vertex + 65);
			p = p->link;
		}
	}
}
//�׷��� g���� ���� v�� ���� �ʺ� �켱 ���� Ž��
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;//ť
	Q = createLinkedQueue();//ť����
	g->visited[v] = TRUE;//���� ���� v�� ���� �迭���� TRUE�� ����
	printf(" %c", v + 65);
	enQueue(Q, v);//���� ���� v�� ť�� enQueue
}
//ť�� ������ �ƴ� ���� �ʺ� �켱 Ž�� ����
while (!isEmpty(Q)) {
	v = deQueue(Q);
	// ���� ���� w�� �湮���� ���� ���
	for (w = g->adjList_H[v]; w; w = w->link)//���� ������ �ִ� ���� ����
	{
		if (!g->visited[w->vertex]) {//���� ������ �ִ� ���� ����
			g->visited[w->vertex] = TRUE;//���� w�� �湮���� ���� ������ ���
			printf(" %c", w->vertex + 65);//���� 0~6 A~G�� �ٲپ� ���
			enQueue(Q, w->vertex);
		}
	}//ť�� �����̸� �ʺ� �켱 Ž�� ����
}