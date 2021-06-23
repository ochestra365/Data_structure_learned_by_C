#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char element;//���� Ž�� Ʈ�� element�� �ڷ����� char�� ����
typedef struct treeNode {
	char key;//�������ʵ�
	struct treeNode* left;//���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;//������ ���� Ʈ�� ��ũ �ʵ�
}treeNode;

//���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key)p = p->left;
		else if (x == p->key)return p;
		else p = p->right;
	}
	printf("\n ã�� Ű�� �����ϴ�!!");
	return p;
}
//������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key)p->right = insertNode(p->right, x);
	else pritntf("\n�̹� ���� Ű�� �ֽ��ϴ�.!\n");

	return p;
}
//��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {//������ ����� ��ġ Ž��
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
}

//������ ��尡 ���� ���
if (p == NULL) {
	printf("\nã�� Ű�� ���� Ʈ���� �����ϴ�!!!");
	return;
}
//������ ��尡 �ܸ� ����� ���
if ((p->left == NULL) && (p->right == NULL)) {
	if (parent != NULL) {
		if (parent->left == p) parent->left = NULL;
		else parent->right = NULL;
	}
	else root = NULL;
}
//������ ��尡 �ڽ� ��带 �� �� ���� ���
else if ((p->left == NULL) || (p->right == NULL)) {
	if (p->left != NULL)child = p->left;
	else child = p->right;

	if (parent != NULL) {
		if (parent->left == p)parent->left = child;
		else parent->right = child;
	}
	else root = child;
}

//������ ��尡 �ڽ� ��带 �� �� ���� ���
else {
	succ_parent = p;
	succ = p->left;
	while(succ->)
}