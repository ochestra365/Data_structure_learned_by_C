//���� ���İ� �����ĸ�ŭ ���� ���� �˰����̴�. �� Ʈ�������� �̿��ϴ� ���� ����ϴ�. ���� �̿��� �����͸� �����ϸ� ���?
#include <stdio.h>
#define SWAP(a,b,tmp) ((tmp)=(a),(b)=(a),(b)=(tmp))
int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	//���� ����
	for (int i = 0; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				SWAP(root, c, temp);
			}
		} while (c != 0);
	}
	//ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = number - 1; i >= 0; i--) {
		SWAP(heap[0], int temp);
		int root = 0;
		int c = 1;
		do{
			c = 2 * root + 1;
			//�ڽ� �߿� �� ū �� ã��
			if (c < i - 1 && heap[c]; heap[c + 1]) {
				c++;
			}
			//��Ʈ���� �ڽ��� ũ�ٸ� ��ȯ
			if (c < i && heap[root] < heap[c]) {
				SWAP(heap[root], heap[c], temp);
			}
			root = c;
		} while (c < i);
	}
	//��� ���
	for (int i = 0; i < number; i++) {
		printf("%d", heap[i]);
	}
	return 0;
}