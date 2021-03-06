//#include <stdio.h>
//#include<stdlib.h>
//typedef char element;
//typedef struct treeNode {
//	char key;
//	struct treeNode* left;
//	struct treeNode* right;
//}treeNode;
////이진 트리는 중복된 값이 있으면 안된다. 부모 노드를 기준으로 왼쪽에는 작은 값, 오른 쪽에는 큰값이 존재해야 한다. 그것이 규칙이다.
////출력 결과는 순서대로 되게 한다. 중복되는 게 없으면서 부모보다 큰 값은 오른쪽으로 배열된다.
////노드를 삽입 할 때마다 각 분기와 비교해서 비교 분기마다 작으면 각 분기의 왼쪽, 크면 오른쪽으로 배치한다.
////루트를 기준으로 가장 작은 값은 왼쪽, 오른쪽은 큰 쪽,
////삭제시에는 가장 오른쪽에 MAX값을 차상위 노드에 복사해주고, MAX값을 지워준다. 그러면 연결은 그대로 된다.
//treeNode* searchBST(treeNode* root, char x);//이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
//treeNode* insertNode(treeNode* p, char x);//포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
//void deleteNode(treeNode* root, element key);//루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
//void displayInorder(treeNode* root); 
//
//int main() {
//	treeNode* root = NULL;
//	searchBST(root, 'a');
//	root=insertNode(root, 'd');
//	insertNode(root, 'e');
//	insertNode(root, 'f');
//	insertNode(root, 'g');
//	insertNode(root, 'a');
//	insertNode(root, 'z');
//	insertNode(root, 'u');
//	insertNode(root, 'y');
//	displayInorder(root);
//	return 0;
//}
//
//treeNode* searchBST(treeNode* root, char x) {//검색 조건을 달아주는 것이다.
//	if (root == NULL)printf("생성된 노드가 없습니다.");
//	else {
//		treeNode* p;//함수에서 찾을 root를 할당할 p를 함수 내에서 생성한다.
//		p = root;//p는 루트라고 설정
//		while (p != NULL) {//루트가 존재하면
//			if (x < p->key)p = p->left;//만약 key값에 포함된 것보다 작으면 왼쪽에서 검색
//			else if (x == p->key)return p;//키값이 루트값과 같다면 함수반환값으로 정함
//			else p = p->right;//루트 값보다 크다면 오른쪽에서 검색
//		}
//		printf("\n 찾는 키가 없습니다.");
//		return p;//p반환
//	}
//}
//
//treeNode* inserNode(treeNode* p, char x) {//노드 삽입
//	treeNode* newNode;//새 노드를 생성
//	if (p == NULL) {
//		newNode = (treeNode*)malloc(sizeof(treeNode));
//		newNode->key = x;
//		newNode->left = NULL;
//		newNode->right = NULL;
//		return newNode;
//	}
//	else if (x < p->key)p->left = inserNode(p->left, x);
//	else if (x > p->key)p->right = inserNode(p->right, x);
//	else printf("\n이미 같은 키가 있습니다.\n");
//
//	return p;
//}
//void deleteNode(treeNode* root, element key) {
//	treeNode* parent, * p, *succ,* succ_parent;
//	treeNode* child;
//	parent = NULL;
//	p = root;
//	while ((p != NULL) && (p->key != key)) {//삭제할 노드의 위치 탐색
//		parent = p;
//		if (key < p->key)p = p->key;
//		else p = p->right;
//	}
//	if (p == NULL) {//삭제할 노드가 없는 경우
//		printf("\n찾는 키가 이진 트리에 없습니다.");
//		return;
//	}
//	if ((p->left == NULL) && (p->right == NULL)) {//삭제할 노드가 단말 노드인 경우
//		if (parent != NULL) {
//			if (parent != NULL) {
//				if (parent->left == p)parent->left = NULL;
//				else parent->right = NULL;
//			}
//			else root = NULL;
//		}
//	}
//	else if ((p->left == NULL) || (p->right == NULL)) {//삭제할 노드가 자식 노드를 한 개 가진 경우
//		if (p->left != NULL)child = p->left;
//		else child = p->right;
//		if (parent != NULL) {
//			if (parent->left == p)parent->left = child;
//			else parent->right = child;
//		}
//		else root = child;
//	}
//	else {//삭제할 노드가 자식 노드 2 개 가진 경우
//		succ_parent = p;
//		succ = p->left;
//		while (succ->right != NULL) {//왼쪽 서브 트리에서 후계자 찾기
//			succ_parent = succ;
//			succ = succ->right;
//		}
//		if (succ_parent->left == succ)succ_parent->left = succ->left;
//		else succ_parent->right = succ->left;
//		p->key = succ->key;
//		p = succ;
//	}
//	free(p);
//}
//
//void displayInorder(treeNode* root) {
//	if (root) {
//		displayInorder(root->left);
//		printf("%c_", root->key);
//		displayInorder(root->right);
//	}
//}