#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a,b)((a>b)?a:b)

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* LL_rotate(treeNode* parent) {
	treeNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
treeNode* RR_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode* LR_rotate(treeNode* parent) {
	treeNode* child = parent->left;
	parent->left = RR_rotate(child);
	return LL_ratate(parent);
}
treeNode* RL_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

//서브 트리의 높이를 구하는 연산
int getHeight(treeNode* p) {
	int height = 0;
	if(p!=NULL)height=MAX()
}