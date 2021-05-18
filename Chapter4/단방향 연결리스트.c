#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//지금은 전위노드를 만들고자 하는 의도를 가지고 있다.
typedef struct node {//노드 생성
	int data;//데이터값
	struct node* next;//자기참조구조체
}Node;//타입생성
typedef struct {
	Node* head;//형 재정의를 했기 때문에 struct를 안 적어 줘도 된다. 노드를 가리킬 수 있는 타입이 와야 한다.
	//자기참조 구조체가 될 필요는 없다. 왜냐하면 노드를 가리킬 수 있는 형태가 되는 것이 가장 논리적으로 깔끔하기 때문이다.
}HeadNode;

/*헤더를 생성하는 함수*///함수를 잘 모르기 때문에 다시 공부할 필요가 있다.
//함수를 아직 잘 모른다.
HeadNode*  createHead(void) {//함수 정의를 작성하고자 한다. 처음부터 함수 헤더를 적으면 안된다. 함수 바디를 만들고 헤더를 만든다.
	//다른 함수들도 다 헤드를 사용하기 때문에 다른 함수에서도 사용할 수 있게 해준다.
	HeadNode *h=(HeadNode*)malloc(sizeof(HeadNode));//지금은 헤드노드를 생성하고자 하는 것이다. (역참조 방지) 동적할당
	//NULL이 h를 가리키는 경우가 있는데 그것을 역참조라고 한다.(역참조는 반대로 가리키는 경우를 말한다.)
	//할당을 못받은 경우 NULL이라는 것이 반환된다. NULL이 반환될 때는 어떤 형태로 처리할 것이냐?
	//NULL을 못넣게 하겠다. NULL은 아무데나 접근할 수 있다.
	//NULL이 참조하게 되면 아예 프로그램이 동작되지 않게 하겠다.
	if (h != NULL) h-> head = NULL;//변수에 NULL을 넣어라는 의미이다. 포인터 구조체의 변수다. HeadNode의 head멤버변수에 NULL을 넣어서 초기화한다.
	return h;// 요거부터는 잘 모른다.-->지금 함수형식과 반환값을 알 수 없어서 힘들다. 리턴형식이랑 헤더의 타입이랑 맞아야 한다.
}
 Node* preintsertNode(HeadNode *h,int data) //전위에 집어 넣는 함수를 만든다. 구조체도 하나의 함수이다. 새로 만드는 노드가 맨 앞에 가야 한다. 
	 //헤드노드만이 가리킬 수 있다.
//Header가 가리키고 있어야 한다. 
{
	
	Node *newNode=(Node*)malloc(sizeof(Node));//노드생성
	//전위 삽입은 
	if (newNode != NULL) {
		newNode->data = data;//인수형 자료를 data값에 넣어줘야 한다.
		newNode->next = h->head;//링크 값이 다음 노드의 데이터가 들어있는 시작주소값을 가리키게 하였다.//newNode의 새로운 필드를 가리키게 한다.
		h->head = newNode;//새로운 노드가 만들어지면서 이전 주소값을 초기화하고 새로운 주소값을 할당받는다.
	}//어렵다. 역참조 방지
	//다음은 헤드노드가 새로운 노드를 가리키게 해야한다.
}
 //후위삽입 새로운 노드가 맨마지막노드로 가는 거.
 //아예 모른다.
Node* rearInsertNode(int data) {//헤드 노드를 통해서 데이터를 넣을 건데 Node가 생성되면 헤드노드를 통해서 기존에 존재하던 노드의 배열 뒤에 노드를 새로 만들어서 삽입하는 것이다.
	 //curr이라는 포인터가 필요하다.
	 Node *newNode=(Node*)malloc(sizeof(Node));//노드 생성
	 if (newNode != NULL) {//새로만들어진 노드가 빈값이 아니면 h->가리키는 값을 초기화하고 다음 연산을 실행해라
		 newNode->data = data;//데이터를 넣고 초기화
		 newNode->next = NULL;//다음 주소는 가리킬 수 없다. 즉, 순회노드를 통해서만 돌아다닐 수 있는 데 목적은 맨마지막 노드부터 돌게 만들거다.
		 //여기까지는 진리다. 그 밑부터는 후위노드에 대해 개념이 없기 때문에 코드를 짤 수 없다.
		 //후위노드에 대해 알아봐야 한다.
	 }

 }
//내가 원하는 노드를 찾아가려면 head노드를 찾아갈 수밖에 없다. Curr 첫번째 노드에 대한 정보를 Head가 담고 있다.
int main(void) {
	HeadNode*h=createHead();//헤드 생성-->가리키는 관계
	


	return 0;
}