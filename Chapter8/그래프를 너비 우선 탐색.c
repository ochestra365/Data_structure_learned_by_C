#include <stdiol.h>
#include <memormy.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

// 그래프에 대한 인접 리스트의 노드 구조 정의
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;
typedef struct graphType {
	int n;//정점 개수
	graphNode* adjList_H[MAX_VERTEX];//정점에 대한 인접 리스트의 헤드 노드 배열
	int visited[MAX_VERTEX];//정점에 대한 방문 표시를 위한 배열
}graphType;
typedef int element;

//<<큐(6장에서 설명한 연결리스트를 이용한 큐 연산>>
typedef struct QNode {
	int data;//data 필드의 자료형을 int로 수정
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
}//큐

//너비 우선 탐색을 위한 초기 공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
	int v;
	g->n = 0;//그래프의 정점 개수를 0으로 초기화
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;//그래프의 정점에 대한 배열 visited를 FALSE로 초기화
		g->adjList_H[v] = NULL;//인접 리스트에 대한 헤드 노드 배열을 NULL로 초기화
	}
}
//그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과했습니다.");
		return;
	}
	g->n++;
}
//그래프 g에 간선 (u,v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n그래프에 없는 정점입니다.");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}
//그래프 g에 대한 인접 리스트를 출력하는 연산
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t정점 %c의 인접리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("-> %c", p->vertex + 65);
			p = p->link;
		}
	}
}
//그래프 g에서 정점 v에 대한 너비 우선 연산 탐색
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;//큐
	Q = createLinkedQueue();//큐생성
	g->visited[v] = TRUE;//시작 정점 v에 대한 배열값을 TRUE로 설정
	printf(" %c", v + 65);
	enQueue(Q, v);//현재 정점 v를 큐에 enQueue
}
//큐가 공백이 아닌 동안 너비 우선 탐색 수행
while (!isEmpty(Q)) {
	v = deQueue(Q);
	// 현재 정점 w를 방문하지 않은 경우
	for (w = g->adjList_H[v]; w; w = w->link)//인접 정점이 있는 동안 수행
	{
		if (!g->visited[w->vertex]) {//인접 정점이 있는 동안 수행
			g->visited[w->vertex] = TRUE;//정점 w가 방문하지 않은 정점인 경우
			printf(" %c", w->vertex + 65);//정점 0~6 A~G로 바꾸어 출력
			enQueue(Q, w->vertex);
		}
	}//큐가 공백이면 너비 우선 탐색 종료
}