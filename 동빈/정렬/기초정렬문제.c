// 백준 세 숫자 정렬
#include <stdio.h>
#define SWAP(x,y,tmp)((tmp)=(x),(y)=(x),(x)=(tmp))
int array[3];

int main(void) {
	int i, j, min, index, tmp;
	for (i = 0; i < 3; i++) {
		scanf("%d", &array[i]);
	}
	for (i = 0; i < 3; i++) {
		min = 100001;
		for (j = i; j < 3; j++) {
			if (min > array[i]) {
				min = array[i];
				index = j;
			}
		}
		SWAP(array[i], array[index], tmp);
	}
	for (i = 0; i < 3; i++) {
		printf("%d", array[i]);
	}
	return 0;
}