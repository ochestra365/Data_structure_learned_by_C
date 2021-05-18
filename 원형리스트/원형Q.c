#include <stdio.h>
#include <stdbool.h>
#define SIZE 5
//큐는 데이터의 입출입 경로가 따로 있다. 앞쪽이 front 뒤쪽이 rear 순차 자료구조 연결 자료구조를 통해서 구현할 수 있다. 큐는 원형큐를 많이 구현하게 된다. 원형큐가 편하다.
//데이터가 없을때는 rear와 front가 한 곳을 가리키고 있다. front가 증가되면 정의에 맞지 않다. rear에서 front로 데이터가 입력되고 출력된다. rear==front큐라는 자료구조가 데이터가 없다. 입출구가 같다.
//rear==front면 비어 있다.  데이터가 들어가면 rear 원소를 하나 더 집어 넣을 때마다 rear가 가리키는 것이 다르다. 최종 방까지 갔을 때 rear==front가 되서 가득 차있을때와 비어 있을 때 값이 같게 된다.

//rear+1==front(full) 중복된 형태를 방지하기 위해서 원형 큐에서는 방을 하나 비워놔야 한다. 출력은 front를 사용한다. 순차 자료구조의 형태

int isEmpty();
int isFull();
void enQueue(int);  // q에 삽입
int deQueue();		// q에서 제거

int rear = 0;		// 입구(상태값)-->배열 인덱스
int front = 0;		// 출구(상태값)-->배열 인덱스
int queue[SIZE];
int main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	printf("%d\n", deQueue());//10이 가장 먼저 들어갔기 때문에 10이 삭제되어야 한다. 제일 먼저 들어간 것이 제일 먼저 사라진다.
	printf("%d\n", deQueue());//20이 두번 쨰로 들어갔기 때문에 20이 삭제되어야 한다. 순차적으로 사라진다.
	printf("%d\n", deQueue());//20이 두번 쨰로 들어갔기 때문에 20이 삭제되어야 한다. 순차적으로 사라진다.


	return 0;
}

int isEmpty() {//공백조건
	if (rear == front) return true;
	else return false;
}
int isFull() {//포화조건
	if (front == (rear + 1) % SIZE) return true;//배열 방의 인덱스를 0~5까지 하게 한다. SIZE는 5이다. rear는 항상 다음에 들어갈 것을 의미한다. 논리적으로 하나 더 늘어난 것이다.
	//방 크기가 계속 늘어나게 되서 순차적으로 데이터를 집어넣을 수 있게 한다. 방을 더 집어 넣을 필요가 없다.
	else return false;
}

void enQueue(int data) {
	if (isFull()) printf("Queue overflow\n");
	else {
		rear = rear % SIZE;
		queue[rear] = data;
		rear++;
	}
}

int deQueue() {
	if (isEmpty()) {
		printf("Queue underflow!!\n");
		return;
	}
	else {
		return queue[front++ % SIZE];
	}
}