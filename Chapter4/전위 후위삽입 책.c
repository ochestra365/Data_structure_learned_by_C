#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];//������� ������ �߿��ϴ�. �ֳ��ϸ� ������ �ݴ��� ���鸮��Ʈ���� ������ �� ���� �����̴�.
	struct ListNode* link;
}listnode;

//����Ʈ ������ �˸��� ������� ����(���鸮��Ʈ)
typedef struct {
	listnode* head;
}linkedList_h;

//���� ���� ����Ʈ�� �����ϴ� ����(���鸮��Ʈ�� �ϳ��� ����Ʈ ���� �������� ������̴�. ����� ������ ����!!!!
linkedList_h* createLinkedList_h(void) {//�Է°��� �翬�� ����. �ֳ��ϸ� �����͸� ���� �־� �� �ʿ䰡 ���� �����̴�.
	//Head�� ù��° ����� ���缺�� Ȯ�ν����� ���̴�.
	linkedList_h* L=(linkedList_h*)malloc(sizeof(listnode));//���鸮��Ʈ�� ����ü �����͸� �������� ����� �ش�.
	if (L != NULL)L->head = NULL;//���鸮��Ʈ�ϱ� NULL�� ����(�������� �����ϴ� ���̴�.)
	return L;//L�� ��ȯ�Ѵ�.
}
//���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinked_h(linkedList_h* L) {//linkedList_h �ʱ� ���鸮��Ʈ�� ��� ������踦 �����ϴ� ����� �� �� �ִ�. �ֳ��ϸ� 
	//link�� ���� ����κи� �����ϸ� ������ �κе� ����� ��������� link�� ���� ������ �����ϱ� �����̴�.
	listnode* curr;//�̰��� ����Ʈ �����Ͱ� ������ ��Ʈ�̴�.
	while (L->head != NULL) {//!=NULL�� '�����Ѵ�'��� ���� �ǹ��Ѵ�.
		curr = L->head;//����ü �����Ϳ� L->head�� �Ҵ��Ѵ�. ���� ���� ó���ε�
		L->head = L->head->link;//�̷��� �ϸ� ��ü�� �����̴�. �μ����ظ� �����ϸ� �� ���ϴ�.(��ġ����)
		free(curr);//�޸� �Ҵ��� Ǯ���ش�.
		curr = NULL;//P���� ����ش�. ���� node�� link�� �������·� �дٰ� ���� �ȴ�.
	}
}
//���Ḯ��Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
	listnode* curr;
	printf("L=(");
	curr = L->head;//��尡 ���� �߿��ϴ�. ��ũ�� ��ũ�� �ɾ ��� �����ϴ� ���̴�.
	while (curr != NULL)//p�� ������ ������, ������谡 �����Ҷ�����
	{
		printf("%s", curr->data);//p�� �����͸� ���������� ���� 
		curr = curr->link;//p�� ���� ��ũ �׷� ���� ��带 ����Ű�� �ȴ�.
		if (curr != NULL)printf(", ");
	}
	printf(")\n");
}
// ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h* L, char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(listnode));//������ ����� �Ҵ�
	strcpy(newNode->data, x);//�� ����� ������ �ʵ忡 x����//���ڹ迭�� �޾Ƽ� ������ �ʵ忡 �����Ѵ�.
	newNode->link = L->head;//ó�� �����ϸ� ù��°���� ������ ����̱� ������ link�ʵ忡 NULL���� �־��ִ� ���̴�.
	L->head = newNode;
}

//��带 pre�ڿ� �����ϴ� ����(�̰� ���� �� ��� ��������)-->�߷��� �ǽ��غ���
void insertMiddleNode(linkedList_h *L ,listnode*pre,char* x) {
	listnode* newNode = (listnode*)malloc(sizeof(linkedList_h));
	strcpy(newNode->data, x);
	if (L == NULL) {//���鸮��Ʈ�� ���
		newNode->link = NULL;//�� ��带 ù��°���� ������ ���� ����(�ֳ��ϸ� ������ ����� link���� null�̱� �����̴�.)
		L->head = newNode;//������� ���۵����� ��
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;//������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}
//������ ���� �����ϴ� ����(�̰� ������ ��� ��������)-->�߷��� �ǽ��غ���.
void insertLastNode(linkedList_h* L, char* x) {
	listnode* newNode;
	listnode* curr;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link = NULL;//������ ����� link�� �׻� NULL�̴�.
	if (L->head == NULL) {//���� ����Ʈ�� ������ ���.. �³� head�� ������ �ƿ� ������ �ȵǴϱ� ����Ʈ�� ������ ���� �ǹ��ϳ�.
		L->head = newNode;//�� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	//���� ����Ʈ�� ������ �ƴ� ���-->��尡 �ִ� ���
	curr = L->head;
	while (curr->link != NULL)curr = curr->link;//���� ����Ʈ�� ������ ��带 ã��.
	curr->link = newNode;//�� ��带 ������ ����� ���� ���� ����(���� ����?)
}
//����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(linkedList_h* L, listnode* p) {
	listnode* curr;//������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL)return;//���� ����Ʈ��� ���� ���� �ߴ�
	if (L->head->link == NULL) {//����Ʈ�� ��尡 �� ���� �ִ� ���
		free(L->head);//ù ���� ��带 �޸𸮿��� �����ϰ�
		L->head = NULL;//����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (p == NULL)return;
	else {//������ ��� p�� ������ ��带 ������ pre�� �̿��� ã��
		curr = L->head;
		while (curr->link != p) {//�Ǹ����� ���� NULL�����ְŵ�? �װ� �����ּҰ����� ó������ ������ �Ű�
			//����� ������ ���� �����ּ��ݾ�
			curr = curr->link;//head���� �����.
		}
		curr->link = p->link;//������ ��� p�� ������ ���� ���� ��带 ����
		free(p);//���� ����� �޸� ����
	}
}
//����Ʈ���� x��带 Ž���ϴ� ����
listnode* searchNode(linkedList_h *L, char* x) {
	listnode* temp;
	temp = L->head;//L->head�� �����ع����� ������ ����ü�����͸� �����ϴ� �Ŵ�. �׷��� temp������ ã���ִ� �Ŵ�. ������ �����ϴϱ�
	//���鸮��Ʈ�� Ÿ�� �Ѿ�� ���ش�.
	while (temp != NULL) {//temp�� link��Ʈ�� NULL�̴�.//���������� �ϴ� ó������ ������ ã�ƺ��ǵ�
		if (strcmp(temp->data, x) == 0)return temp;//��忡�� ������ �������ڰ� �޸��ٰ� ���� ���� ���� ã���� �� �װ��� ��ȯ�Ѵ�.
		else temp = temp->link;//�װ� �ƴ϶�� temp�� ��������Ʈ�� �����ּҰ����� �ű��.
	}
	return temp;//���� ã�� ���� ������ NULL���� ��ȯ�Ѵ�.
	//if else �������� �ص� �ɰ��̴�.
}
//����Ʈ�� �������� �������� �ٲٴ� ����
void resverse(linkedList_h* L) {
	listnode* p;
	listnode* q;
	listnode* r;

	p = L->head;//���鸮��Ʈ
	q = NULL;//�ʱ�ȭ
	L = NULL;//�ʱ�ȭ

	//����Ʈ�� ù ��° ������ ��ũ�� ���� ���� ���� �̵��ϸ鼭 
	//��� ���� ������ �ٲ�
	while (p != NULL) {//NULL�� �ƴҶ����� ������ ������.
		r = q;//��� r�� ��� q���ȴ�.
		q = p;//��� q�� ��� p�� �ȴ�.
		p = p->link;//�������� �̵�
		q->link = r;//��� q�� ���� �ּҴ� r�� �ȴ�. r->q->p //å 177�ʱ׸� ����-->�̰Ŵ� ����� ��ƴ�.
	 }
	L->head = q;
}
int main(void) {//���� ���� �׳� ��� �����Ǵ� ������ �߿��� ��Ʈ�� �ƴ��� �ʹ�.
	linkedList_h* L = createLinkedList_h();
	listnode* p;
	printf("(1) ���� ����Ʈ �����ϱ�\n");
	printList(L); //�̰Ŵ� ���ȴ�. ���� ����� ù ���� �����Ͱ��� �ҷ����� �ű⶧���� 

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�\n");
	insertFirstNode(L, "��");
	printList(L); //�̰Ŵ� ���ȴ�. ���� ����� ù ���� �����Ͱ��� �ҷ����� �ű⶧���� 

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ� \n");
	insertLastNode(L, "��");
	printList(L);

	printf("(4) ����Ʈ ù ��°�� [��] ��� �����ϱ� \n");
	insertFirstNode(L, "��");
	printList(L);

	printf("(5) ����Ʈ ������ �����Ͽ� ���鸮��Ʈ�� ����� \n");
	freeLinked_h(L);
	printList(L);
	return 0;
}
//å�� �ʿ��� �Լ��� ���� �����Ѵ�.
//�׸��� �� ��ɵ��� �̿��ؼ� ������ ���������� ���� �����Ѵ�.
//�˰� ���� ���� �ƴ϶�� ���� ���� ������ ���̴�. �̰� ȥ�ڼ� �˱� ���� ������ 10�ð� �ɷȰ�, å���ϱ� 2�ð� �ɸ��µ� ��¥ ������
//�Ƹ� ��ܼ��� ���� �ϸ� ���� �����ϴ� �� ���� �����ϴ� �� �ƴ϶� �˰� ���ϱ� ������ �̸��ϰ� ������ ������ �׷� ���ϸ� ����� �Ծ ����� Ǯ�ڴ�