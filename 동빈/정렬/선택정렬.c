//가장 작은 것을 선택해서 가장 앞으로 보낸다.
#include <stdio.h>
#define SWAP(A,B,temp) ((temp)=(A),(A)=(B),(B)=(temp))

int main(void) {
	int i, j, min, index, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		SWAP(array[i],array[index],temp)
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
	}
	return 0;
}
// 선택 정렬의 시간복잡도는 O(N^2)