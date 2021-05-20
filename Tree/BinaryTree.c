#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//전위순회 데이터를 먼저 처리.
typedef struct BtreeNode {
	char data;
	struct BtreeNode* left;
	struct BtreeNode* right;
}BTNode;
//데이터를 어느 시점에 처리하느냐에 따라서 정해진다.
BTNode* makeBTNode(data) {
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void makeLeftTree(BTNode* root,BTNode* sub) //부모 트리의 왼쪽에 자식들을 만들 것이다.
{
	if (root->left != NULL)free(root->left);//기존의 왼쪾에 서브 트리가 있으면 삭제하고 새로운 놈으로 연결하겠다.
	root->left = sub;
}
void makeRightTree(BTNode* root, BTNode* sub) 
{
	if (root->right != NULL)free(root->right);
	root->right = sub;
}
void preorder(BTNode* root) {//전위순회: 데이터->왼쪽서브->오른쪽 서브
	if (root == NULL)return;
	printf("%c\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(BTNode* root) {//중위
	if (root == NULL)return;
	inorder(root->left);
	printf("%c\t", root->data);
	inorder(root->right);
}
void postorder(BTNode* root) {//후위
	if (root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	printf("%c\t", root->data);
}
int main() {
	BTNode* b1 = makeBTNode('a');
	BTNode* b2 = makeBTNode('b');
	BTNode* b3 = makeBTNode('c');
	BTNode* b4 = makeBTNode('d');
	BTNode* b5 = makeBTNode('e');
	BTNode* b6 = makeBTNode('f');
	BTNode* b7 = makeBTNode('g');
	BTNode* b8 = makeBTNode('h');

	makeLeftTree(b1, b2);
	makeRightTree(b1, b3);
	makeLeftTree(b2, b4);
	makeRightTree(b2, b5);
	makeLeftTree(b3, b6);
	makeRightTree(b3, b7);
	makeLeftTree(b4, b8);

	preorder(b1);
	printf("\n");
	return 0;
}