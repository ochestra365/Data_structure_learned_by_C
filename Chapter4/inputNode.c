//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
////일반적인 렘에 저장하지 않고 힙영역에서 처리한다.
////단순 연결리스트의 노드 구조를 구조체로 정의
//typedef struct ListNode {
//	int data;//데이터 멤버
//	struct ListNode* link;//자기참조 구조체, 다음 노드의 주소를 저장할 멤버
//}listNode;
//
////리스트 시작을 나타내느 head 노드를 구조체로 정의
//typedef struct {
//	listNode* head;
//}linkedList_h;
//
//
//
//int main(void) {
//	listNode *head=(listNode*)malloc(sizeof(listNode));
//	listNode* node1=(listNode*)malloc(sizeof(listNode));//할당된 메모리 주소 값 노드 생성//자료형은 노드 포인터다.
//	listNode* node2=(listNode*)malloc(sizeof(listNode));
//	listNode* node3=(listNode*)malloc(sizeof(listNode));
//	listNode* node4=(listNode*)malloc(sizeof(listNode));
//	listNode* node5=(listNode*)malloc(sizeof(listNode));
//	if (node1 == NULL)return;
//	if (node2 == NULL)return;
//	if (node3 == NULL)return;
//	if (node4 == NULL)return;
//	if (node5 == NULL)return;
//	if (head == NULL)return;
//	node1->link = NULL;//처음 생성은 초기화 단계이다.
//	node1->data = 10;//노드원의 데이터값을 나타낸다.
//	node2->data = 20;
//	node3->data = 0;
//	node4->data = 0;
//	node5->data = NULL;
//	
//	head->link = node1;//헤드 노드의 링크 필드가 노드 1의 데이터값의 시작 주소값을 가져야 한다.-->헤드노드가 첫번째 노드를 가리키고 있다. LOE연산자는 구조체 포인터 선언 시 멤버의 가리키는 값의 데이터갑승 출력한다.
//	node1->link = node2;
//	node2->link = node3;
//	node3->link = node4;
//
//	listNode* curr = head->link;//node1의 시작주소값 curr은 current의 약자로 현재 가리키고 있는 노드의 값을 나타낸다.
//	while (curr != NULL) {//NULL을 만나면 반복문을 빠져 나온다.
//		printf("%d\n", curr->data);
//		curr = curr->link;//이건 다음 노드의 링크로 다가가는 값을 현재 가리키고 있는 값에 저장한것이다.
//	}
//	free(head);
//	free(node1);
//	free(node2);
//	free(node3);
//	free(node4);
//	free(node5);
//	return 0;
//}