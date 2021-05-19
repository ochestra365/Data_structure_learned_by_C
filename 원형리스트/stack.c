#define _CRT_SEUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>//�� ������ �������ִ� C�� ���
//���������� â�� ������ ���� â�� ������ ���� â�� ������ ���̴�.
#define STACK_SZ	3//��ó��
//#define TRUE	1
//#define FALSE	2
//���� �⺻ �Լ�
int isEmpty(void);//���� üũ(���� ������ ������ ������ִ�.)
int isFull(void);//��ȭüũ(���� ������ ������ ä���� �ִ�.)
void push(int);//���ÿ� �Է�
int pop(void);//���ÿ� ���
int peek(void);//������ ���� Ȯ��
void printStack(void);
int stack[STACK_SZ];//���� ����
int top = -1;//���� ������ ��ġ�� ��Ÿ���� ���̴�. ���ÿ� �� ���� �����Ͱ� �ԷµǾ� �ִ� �� Ȯ�ε� �����ϴ�. �׻� �� ���� ����Ų��. �׳� �迭����� �ε��� ���� �巯���� ���°��̴�.
//���� ������ ���� ������ �ִ� ���� �巯����.//�迭 �̿��ϴϱ�

int main() {
	push(10);
	push(11);
	push(12);
	pop();
	push(13);
	printStack();
	return 0;
}

int isEmpty() {
	if (top <= -1)return true;//��� �ֳĴ� �Լ��� ������ ���̶�� �����
	else return false;//��� �ֳĴ� �Լ��� ������ �ƴ϶�� �����
}

int isFull() {
	if (top >= STACK_SZ - 1) return true;//���� �����ŭ �������� ���� �� �ֳĴ� �Լ��� ������ �׷��ٰ� �����.
	else return false;//���� �����ŭ �������� ���� �� �ֳĴ� �Լ��� ������ �ƴ϶�� �����.
}

void push(int data) {
	if (isFull()) {//�ϴ� �ֱ� ���� ���� �� �ִ� �� �ƴ� �� Ȯ��
		printf("STACK overflow!!\n");//���� �� ������ �ش� ��°��� ��ȯ��.
		return;//������ �߸� �� �Ʒ� ��ɹ����� ������ �ȵǾ� �ؼ� return �� ��Ų��.
	}
	else {//0���� ���� index���������� ����Ѵ�
		stack[++top] = data; //top=-1 1 ���� ��Ű�� �� ���� ���꿡 ����Ѵ�. ���Ҹ� �ְ� ���� �Ǵ��ؾ� �Ѵ�. �迭�� ����Ϸ���
	}
}

int pop() {//����������� �˾ƾ� �Ѵ�.
	if (isEmpty()) {//�ϴ� ���� ���� ������ �� �ƴ� �� Ȯ��
		printf("STACK underflow");//��� ������ �ش� ��°��� ��ȯ��
		return;
	}
	else {
		return stack[top--];//-1 ����ϰ� ���� -1�� ����� �Ѵ�. ���Ҹ� ���� ���� �Ǵ��ؾ� �Ѵ�. ���� �迭��Ҹ� ��ȯ�ϴϱ� ���� �迭��Ҵ� �ֹߵǾ� ����.
		//������ ���Ҹ� ������ ī��Ʈ�� �����ִ� ���̴�.(�迭�̿�)
	}
}
int peek() {
	if (isEmpty()) {//��� �ִ��� 
		printf("STACK underflow!!\n");
		exit(1);//���α׷� ����A
	}
	else return stack[top];//���� ���� �ִ� ž���� ��ȯ
}
void printStack() {
	if (!isEmpty()) {
		for (int i = 0; i <= top; i++) {
			printf("%d   ", stack[i]);
		}
	}
}

//���� ������ �����ڷᱸ���� ���ؼ� ���� ���̴�.
//�޸𸮿��� �� ������� ����Ǿ� �ִ� ��, �������δ� �ְ� ���� �Ǵ� �Ŵ�.