#include <stdio.h>

typedef struct node//형재정의를 통해서 구조체 struct를 node를 Node로 선언
{
    int data;
    struct node* next;
}Node;

typedef struct//헤드 노드로 선언한다. 초기 노드를 가리킬 수 있는 것.
{
    Node* head;//노드를 가리킬 수 있는 타입 화살표가 되버린 헤드
}HeadNode;

/*헤더를 생성하는 함수*/
HeadNode* createHead(void)//헤드노드를 만드는 것이다. 구조체포인터로 사용한다.
{
    HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));//헤드를 만든다.
    if (h != NULL) h->head = NULL;//HeadNode의 값은 처음에 반드시 초기화 NULL값으로 초기화 시켜 주겠다.
    return h;
}

void preInsertNode(HeadNode* h, int i)
{
    Node* newNode = (Node*)malloc(sizeof(Node));//노드가 생성된다.
    if (newNode != NULL)//노드의 정보를 확인할 수 있으면 다음 연산을 시행한다. 즉, 노드가 존재하면
    {
        newNode->data = i;//정수형 데이터를 할당한다.
        newNode->next = h->head;//헤드 포인터의 값을 새로만들어진 next 구조체 포인터의 값에 넣어준다. 그럼 처음 생성된 노드의 
        //next는  NULL값을 가진다.
        h->head = newNode;//새로운 노드의 초기 주소값을 헤드에 할당한다.
        //n번째 노드의 next포인터 넥스트포인터멤버변수에는 n-1번째 주소값이 저장된다. 그리고 가리키게 된다.
        //즉 전위노드 구조체는 모든 값이 할당된 상태이다.
        //제일 마지막으로 생성된 노드가 초기 노드를 가리키고 있다.
    }
}

Node rearInsertNode(HeadNode* h, int i)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* curr;

    if (newNode != NULL)
    {
        newNode->data = i;
        newNode->next = NULL;
        curr = h->head;
        if (h->head == NULL)//리스트아무것도없을때
        {
            h->head = newNode;
            return;
        }
        while (curr->next != NULL)//마지막 노드 찾아감, 뒤에 만들어진 노드의 존재를 확인할 수 없으니까 빠져나갔는데
        {
            curr = curr->next;//자기 참조 구조체의 포인터니까 가리킬 수 있다.
        }
        curr->next = newNode;//curr->next에 만들어진 주소의 새 주소를 할당해서 이어준다. 최종적으로 이어줘서 알수 있게 해줬다.
    }
}


void Print_Node(HeadNode* h)
{
    int i = 1;
    while (h->head != NULL)//노드가 존재하면 아래 연산을 시행해라 확인하고자하는 정보는 멤버변수의 정보인데 노드가 없어서 멤버변수의 정보를 확인할 수 없기때문에 NULL이라고 한다.
    {
        printf("%d번째 노드 값 : %d\n", i++, h->head->data);//노드가 가리키는 데이터 값을 출력하세요
        h->head = h->head->next;//출력하고 나면 현재 노드의 주소값에 다음 노드의 주소값을 대입하세요
        //그러면 전위나 후위나 모두 포인터할 수 있으니까
    }
}
void rmv_node(HeadNode* h) {
    Node* curr = h->head;//외부 구조체 포인터변수 cur 생성 후위연산도 존재하니까 head는 건드릴 수 없다. 외부 구조체 포인터를 따로 이용해서 NULL값을 넣어준다.
    while (h->head != NULL) {//노드의 정보를 확인할 수 없는 상태가 아닌 값이 아니면 해당 연산을 돌려요.
        //노드가 존재하면 해당 연산을 시행하시오.
        curr->data = NULL;//데이터에 NULL값을 대입한다.
        //printf("%d번째 노드 값: %d\n", i, curr->data);
        curr = curr->next;//다음 노드로 넘어간다.
    }//1번 노드부터 순회하면서 모든 버퍼에 NULL값을 대입한 뒤 노드가 뒤에 존재하지않으면 반복문을 빠져나온다.
    h->head = NULL;//마지막으로 head의 자기참조 포인터 데이터값도 깔끔하게 털어준다.
    while (h->head != NULL) {
        if (curr->data == NULL) {
            printf("노드가없어요 \n");
        }
        curr = curr->next;
    }
    if ((h->head==NULL))printf("노드가 없습니다. \n");
}
/*검색*/
Node* searchNode(HeadNode*h,int dataa) {//여기부터 다시 해보자.
    Node* s = h->head;//헤드(h->head)
    if (s != NULL) {//head가 가리키는 첫번 째 노드가 존재하면
        if (s->data == dataa) {
            printf("데이터 값은 %d입니다.", dataa); return s;
        }
        while (s->next != NULL) {
            s = s->next;
        }
    }
    else {
        printf("첫번 째 노드가 없습니다.");
        return s;
    }
    return s;
}
/*삭제함수*///못만들겠어 ㅠㅠㅠ
removeNode(HeadNode* h, Node* d) {

}
int main(void)
{
    int res;
    HeadNode* head = createHead();//헤드노드 선언
    preInsertNode(head, 1);
    preInsertNode(head, 2);
    preInsertNode(head, 200);
    preInsertNode(head, 300);

    rearInsertNode(head, 3);
    rearInsertNode(head, 4);
    //Print_Node(head);//노드를 순회하면서 출력됨
    //Print_Node(head);
    //rmv_node(head);//노드를 순회하면서 NULL값 대입
    Print_Node(head);//출력이 되지 않음. 모든 자료가 날아갔음을 알 수 있따.
    searchNode(head, 1);
    return 0;
}