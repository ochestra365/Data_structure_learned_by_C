#include <stdio.h>
#define SWAP(x,y,tmp)((tmp)=(x),(x)=(y),(y)=(tmp))

int main(void) {
	int number, i, j, min, index, tmp;
	scanf("%d", &number);
	for (i = 0; i < number; i++) {
		scanf("%d", &array[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001;
		for (j = i; j < number; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		SWAP(array[i], array[index], tmp);
	}
	for (i = 0; i < number; i++) {
		printf("%d", array[i]);
	}
	return 0;
}