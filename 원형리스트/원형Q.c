#include <stdio.h>
#include <stdbool.h>
#define SIZE 5
//ť�� �������� ������ ��ΰ� ���� �ִ�. ������ front ������ rear ���� �ڷᱸ�� ���� �ڷᱸ���� ���ؼ� ������ �� �ִ�. ť�� ����ť�� ���� �����ϰ� �ȴ�. ����ť�� ���ϴ�.
//�����Ͱ� �������� rear�� front�� �� ���� ����Ű�� �ִ�. front�� �����Ǹ� ���ǿ� ���� �ʴ�. rear���� front�� �����Ͱ� �Էµǰ� ��µȴ�. rear==frontť��� �ڷᱸ���� �����Ͱ� ����. ���ⱸ�� ����.
//rear==front�� ��� �ִ�.  �����Ͱ� ���� rear ���Ҹ� �ϳ� �� ���� ���� ������ rear�� ����Ű�� ���� �ٸ���. ���� ����� ���� �� rear==front�� �Ǽ� ���� ���������� ��� ���� �� ���� ���� �ȴ�.

//rear+1==front(full) �ߺ��� ���¸� �����ϱ� ���ؼ� ���� ť������ ���� �ϳ� ������� �Ѵ�. ����� front�� ����Ѵ�. ���� �ڷᱸ���� ����

int isEmpty();
int isFull();
void enQueue(int);  // q�� ����
int deQueue();		// q���� ����

int rear = 0;		// �Ա�(���°�)-->�迭 �ε���
int front = 0;		// �ⱸ(���°�)-->�迭 �ε���
int queue[SIZE];
int main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	printf("%d\n", deQueue());//10�� ���� ���� ���� ������ 10�� �����Ǿ�� �Ѵ�. ���� ���� �� ���� ���� ���� �������.
	printf("%d\n", deQueue());//20�� �ι� ���� ���� ������ 20�� �����Ǿ�� �Ѵ�. ���������� �������.
	printf("%d\n", deQueue());//20�� �ι� ���� ���� ������ 20�� �����Ǿ�� �Ѵ�. ���������� �������.


	return 0;
}

int isEmpty() {//��������
	if (rear == front) return true;
	else return false;
}
int isFull() {//��ȭ����
	if (front == (rear + 1) % SIZE) return true;//�迭 ���� �ε����� 0~5���� �ϰ� �Ѵ�. SIZE�� 5�̴�. rear�� �׻� ������ �� ���� �ǹ��Ѵ�. �������� �ϳ� �� �þ ���̴�.
	//�� ũ�Ⱑ ��� �þ�� �Ǽ� ���������� �����͸� ������� �� �ְ� �Ѵ�. ���� �� ���� ���� �ʿ䰡 ����.
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