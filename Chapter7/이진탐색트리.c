#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char element;//이진 탐색 트리 element의 자료형을 char로 정의
typedef struct treeNode {
	char key;//데이터필드
	struct treeNode* left;//왼쪽 서브 트리 링크 필드
	struct treeNode* right;//오른쪽 서브 트리 링크 필드
}treeNode;

//이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key)p = p->left;
		else if (x == p->key)return p;
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다!!");
	return p;
}
//포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
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
	else pritntf("\n이미 같은 키가 있습니다.!\n");

	return p;
}
//루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {//삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
}

//삭제할 노드가 없는 경우
if (p == NULL) {
	printf("\n찾는 키가 이진 트리에 없습니다!!!");
	return;
}
//삭제할 노드가 단말 노드인 경우
if ((p->left == NULL) && (p->right == NULL)) {
	if (parent != NULL) {
		if (parent->left == p) parent->left = NULL;
		else parent->right = NULL;
	}
	else root = NULL;
}
//삭제할 노드가 자식 노드를 한 개 가진 경우
else if ((p->left == NULL) || (p->right == NULL)) {
	if (p->left != NULL)child = p->left;
	else child = p->right;

	if (parent != NULL) {
		if (parent->left == p)parent->left = child;
		else parent->right = child;
	}
	else root = child;
}

//삭제할 노드가 자식 노드를 두 개 가진 경우
else {
	succ_parent = p;
	succ = p->left;
	while(succ->)
}