#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//������ȸ �����͸� ���� ó��.
typedef struct BtreeNode {
	char data;
	struct BtreeNode* left;
	struct BtreeNode* right;
}BTNode;
//�����͸� ��� ������ ó���ϴ��Ŀ� ���� ��������.
BTNode* makeBTNode(data) {
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void makeLeftTree(BTNode* root,BTNode* sub) //�θ� Ʈ���� ���ʿ� �ڽĵ��� ���� ���̴�.
{
	if (root->left != NULL)free(root->left);//������ �ަU�� ���� Ʈ���� ������ �����ϰ� ���ο� ������ �����ϰڴ�.
	root->left = sub;
}
void makeRightTree(BTNode* root, BTNode* sub) 
{
	if (root->right != NULL)free(root->right);
	root->right = sub;
}
void preorder(BTNode* root) {//������ȸ: ������->���ʼ���->������ ����
	if (root == NULL)return;
	printf("%c\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(BTNode* root) {//����
	if (root == NULL)return;
	inorder(root->left);
	printf("%c\t", root->data);
	inorder(root->right);
}
void postorder(BTNode* root) {//����
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