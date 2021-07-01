//옆에 있는 값과 비교해서 더 작은 값을 앞으로 보낸다.
#include <stdio.h>
#define SWAP(x,y,temp) ((temp)=(x),(x)=(y),(y)=(temp))
int main(void) {
	int i, j, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		if (array[j] > array[j + 1]) {
			SWAP(array[j],array[j+1],temp)
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
	}
	return 0;
}