#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//이중연결리스트: 멤버가 하나 더 생긴다. 데이터, next, pre
/// 구조체 선언
typedef struct node {//참
	int data;
	struct node* next;
	struct node* pre;
}DListNode;


typedef struct head {//참
	DListNode* head;
}HeadNode;
/// 함수선언
DListNode* createNode(int data);//참
HeadNode* createHead(void);//참
//void insertNode(HeadNode* phead, DListNode preNode, DListNode* next);//모호 노드를 만들어 주고 연결시켜 주는 것이다.
void insertNode1(HeadNode* phead, DListNode* preNode, DListNode* newNode);//선생님이 만든 노드
void printNode1(HeadNode* phead);//선생님이 만든 노드
void DelNode(HeadNode* phead, DListNode* DelNode);//내가 만든거
DListNode* findNode(HeadNode* phead, int data);
//void printNode(HeadNode* phead);//참일 가능성이 높음
/// 메인
int main(void) {
	HeadNode* h = createHead();//헤드 노드 생성
	DListNode* lp = NULL;
	DListNode* n1 = createNode(10);
	insertNode1(h, lp, n1);
	DListNode* n2 = createNode(20);
	insertNode1(h, n1, n2);
	printNode(h);
	return 0;
}
/// 헤드노드 생성
HeadNode* createHead(void) {//참
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)h->head = NULL;
	return h;
}
// 노드 생성
DListNode* createNode(int data) {//참
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL) {
		printf("메모리 할당 실패");
		exit(1);
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		newNode->pre = NULL;
		return newNode;
	}
}
//선생님이 만든 insertNode
void insertNode1(HeadNode* phead, DListNode* preNode, DListNode* newNode) {
	if (phead->head == NULL) {
		phead->head = newNode;
	}
	else {
		newNode->pre = preNode;
		newNode->next = preNode->next;
		if (preNode->next != NULL)newNode->next->pre = newNode;
		preNode->next = newNode;
	}
}
//선생님이 만든 PrintNode
void printNode1(HeadNode* phead) {
	DListNode* curr = NULL;
	if (phead == NULL)return;
	curr = phead->head;
	while (curr != NULL) {
		printf("%d", curr->data);
		curr = curr->next;
	}
}
void DelNode(HeadNode* phead, DListNode* DelNode) {//리스트 존재여부, 삭제 노드 특정
	if (phead->head == NULL) {
		printf("리스트가 존재하지 않으니 삭제할 노드도 없습니다.");
	}
	else {
		DelNode->pre->next = DelNode->next;
		DelNode->next->pre = DelNode->pre;
		free(DelNode);
		// 맨마지막 노드의 삭제 처리 경우는 어떻게 하는 지 모르겠따.while로 head 부터 끝까지 찾아서가서 지워야 할텐데 
	}
}//내가 만든 delnode
//내가 만든 찾는 노드
DListNode* findNode(HeadNode* phead, int data) {//내가 만든 것.
	DListNode* curr=phead->head;
	int cnt=1;
	if (curr == NULL) {
		printf("노드가 존재하지 않습니다. 리스트를 생성하세요");
	}
	else {
		while (curr->next!= NULL) {//끝까지 돌린다
			curr = curr->next;
			if (curr->data == data) {
				printf("찾으시는 값은 %d번째노드는 존재합니다. 노드의 값은 %d입니다.",cnt ,curr->data);
				return;
			}
			else {
				printf("찾는 노드가 존재하지 않습니다.");
				return;
			}
			cnt++;
		}
	}
	
}









//노드 삽입(내가 만든 거)
//void insertNode(HeadNode* phead, DListNode* preNode, DListNode* nextNode) {//모호(내가 만든 거)
//	//이전노드랑 다음 노드가 인수로 주어진다. 이전노드랑 다음 노드가 구해졌기 때문에 처음에 노드를 삽일할 경우를 생각하지 않아도 된다.
//	//왜냐하면 이 조건에 의하면 적어도 2개 이상의 노드는 반드시 주어지기 때문이다.
//	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
//	if (phead->head == NULL) {//공백 리스트일떄. if문에서 첫째 노드를 생성해준다.
//		newNode = phead->head;
//	}
//	else if (phead->head != NULL) {//중간에 넣을떄 맨 처음에 넣을 때의 경우를 생각하지 않아도 됨.
//		preNode->next = newNode->data;
//		newNode->next = nextNode->data;
//		newNode->pre = preNode->data;
//		nextNode->pre = newNode->data;
//		//여기까진 맞다.
//	}
//	else {
//		DListNode* tempNode = (DListNode*)malloc(sizeof(DListNode));
//		tempNode->next = phead->head;//head가 가리키고 있는 관계를 지켜주기 위해 temp노드를 만든다.
//		while (phead->head != NULL)//맨 마지막에 넣을때는 다음 노드가 존재하지 않는다.
//		{
//			tempNode->next = tempNode->next->next;//끝까지 돌아가게 만든다.
//			//이건 이따가 생각하자
//		}
//		tempNode->next = newNode->data;//리스트의 맨마지막까지 돌린 이후에 newNode를 가리키게 한다.
//	}
//}
//내가 만든거
//void printNode(HeadNode* phead) {
//	int cnt = 0;//몇번쨰 노드 인지 while문을 통해 돌려줄 변수
//	if (phead->head == NULL) {//공백 리스트일때
//		printf("공백리스트 입니다. 노드를 생성하세요");
//	}
//	else {//노드가 1개이상 존재할때
//		while (phead->head != NULL) {
//			printf("%d번째 노드의 데이터 값은 %d입니다.", cnt, phead->head->data);//내가 실수한 부분인데 정확한 데이터를 출력하는 게 아니라 관계를 변수에 넣었다.
//			phead->head = phead->head->next;
//			cnt++;
//		}
//	}
//}
//혼자 다시 해보기 컴파일 에러 발생함(이전에 만든 것들 소스코드 다시 복습하기)
