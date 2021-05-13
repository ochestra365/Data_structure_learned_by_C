#include <stdio.h>
typedef struct node {//��带 ������ ����ü ����->����ü�� �������� �ϳ��� ����̴�.
	int data;//�� 1��� ��Ʈ�� �ڷ������� �����͸� �����Ѵ�.
	struct node* link;//�ڱ����� ����ü
}Node;//����ü �� ����
//���� ���� �Լ��� ��ɺ��� �ľ��ϴ� ���� ��ü �ڵ��� �켱�̴�.
void addNode(Node* target, int data) {//����� ���´´�. �����Լ���. �Ǿ����� ���ο� �Լ��� ������Ű�� �Լ���.
	Node* newNode=(Node*)malloc(sizeof(Node));//malloc���� �������� �Ҵ��Ѵ�. �׸��� �� ���� ����ü �����Ϳ� �ִ´�.
	//newNode�� �ٸ� �޸𸮿��� ������� ����̴�.
	//�ش� ���� �Լ������� ������ ��������̴�. �������� ������ �ǰ����� ���� ��ü�� ���ÿ��� �ֹ��ع����� �������� ������ �ִ� �Լ���� ���� �� �ִ�.
	newNode->data = data;//���� ���� data �Ű������� ���� �����κ��� �޾Ƽ� �����͸� ����Ų��.
	newNode->link = target->link;//Ÿ���õǴ� ����� ��ũ���� ���ο� ����� link���� �Ҵ��Ѵ�.
	target->link = newNode;//���� ����� ���� �ּҰ��� link���� �ִ´�. �׸��� ������ ���� �Ŀ� �Լ��� ��ȯ�Ѵ�.
	//��ȯ���� �������� �ʱ� ������ ���ο����� ��ȯ���� ���� ������ ����ü�� �ʿ��ϴ�.
	//���������� ��ȯ�� ��ũ���� newNode�� data���� link���� ����ȴ�. �׸��� �� �Լ��� ������ ���� �� ��� �����Ͱ� ���ÿ�����
	//�Ҵ�Ǿ� �����Ƿ� �ֹߵǾ� ������.
}

int main(void) {
	int i;
	//�Լ��� ��ȯ���� ���� ������ ���� ������Ʈ
	Node* head=(Node*)malloc(sizeof(Node));//�ʱ� ��� ����
	Node* node1=(Node*)malloc(sizeof(Node));//node1�� ����
	Node* node2=(Node*)malloc(sizeof(Node));//node2�� ����
	Node* node3=(Node*)malloc(sizeof(Node));//node3�� ����
	Node* node4=(Node*)malloc(sizeof(Node));//node4�� ����
	Node* node5=(Node*)malloc(sizeof(Node));//node5�� ����
	// ��� ���� ��Ʈ
	//�ʱ�ȭ�� �����ִ� ���̴�.
	head->link = NULL;
	node1->data = 10;
	node2->data = 20;
	node3->data = 30;
	node4->data = 40;
	node5->data = 50;
	// �Լ��� ������ ��Ʈ

	
	//�����Ʈ

	free(head);//��������ȯ
	free(node1);//��������ȯ
	free(node2);//��������ȯ
	free(node3);//��������ȯ
	free(node4);//��������ȯ
	free(node5);//������ ��ȯ
	return 0;
}