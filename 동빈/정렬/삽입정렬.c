//�� ���ڸ� ������ ��ġ�� ����
#include <stdio.h>
#define SWAP(x,y,tmp) ((tmp)=(x),(x)=(y),(y)=(tmp))

int main(void) {
	int i, j, tmp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (j >= 0 && array[j] > array[j + 1]) {
			SWAP(array[j], array[j + 1], tmp);
			j--;
		}
		for (i = 0; i < 10; i++) {
			printf("%d", array[i]);
		}
	}
	return 0;
}
//�ð����⵵�� O(N^2)�̴�.