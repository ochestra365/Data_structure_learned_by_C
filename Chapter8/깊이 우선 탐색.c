#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

//그래프에 대한 인접 리스트의 노드 구조 정의
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;//정점 개수
	graphNode* adjList_H[MAX_VERTEX];//정점에 대한 인접 리스트의 헤드노드 배열
	int visited[MAX_VERTEX];//정점에 대한 방문표시를 위한 배열
}graphNode;

//<<스택(5장에서 설명한 연결 리스트를 이요한 스택연산 수행)
typedef int element;

typedef struct stackNode {
	int data;//data 필드의 자료형을 int로 수정
	struct stackNode* link;
}stackNode;

stackNode* top;

//스택이 공백인 지 확인하는 연산
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
}//스택>>

//깊이 우선 탐색을 위해 초기 공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
	int v;
	g->n = 0;//그래프의 정점 개수를 0으로 초기화
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;//그래프의 정점에 대한 배열 visited를 FALSE로 초기화
		g->adjList_H[v] = NULL;//인접 리스트에 대한 헤드 노드 배열을 NULL로 초기화
	}
}
//그래프 g에 정점 v를 삽입하는 연산 :
void insertVertex(graphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTEX) {
		printf("\n그래프의 정점의 개수를 초과했다.");
		return;
	}
	g->n++;
}
//그래프 g에 간선 (u,v)를 삽입하는 연산:
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
//그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t 정점 %c의 인접리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("->%c", p->vertex + 65);
			p = p->link;
		}
	}
}
//그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;//스택의 top설정
	push(v);//깊이 우선 탐색을 시작하는 정점 v를 스택에 push
	g->visited[v] = TRUE;//정점 v를 방문했으므로 해당 배열값을 TRUE로 설정
	printf("%c", v + 65);
	while (!isEmpty()) {
		v = pop();
		w = g->adjList_H[v];
		//인접 정점이 있는 동안 수행
		while (w) {
			//현재 정점 w를 방문하지 않은 경우
			if (!g->visited[w->vertex]) {
				if (isEmpty())push(v);//정점 v로 돌아올 경우를 위해 다시 push하여 저장
				push(w->vertex);//현재 정점 w를 스택에 푸쉬
				g->visited[w->vertex] = TRUE;//정점 w에 대한 배열값을 TRUE로 설정
				pritnf("%c", w->vertex + 65);//정점 0~6을 A~G로 바꿔서 출력
				v = w->vertex;
				w = g->adjList_H[v];
			}
			//현재 정점 w가 이미 방문된 경우
			else w = w->link;
		}//while(w)
	}//스택이 공백이면 깊이 우선탐색 종료
}

void main() {

	//너무 많아서 생략
}