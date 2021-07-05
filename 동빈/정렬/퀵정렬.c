#include <stdio.h>
#define SWAP(A,B,temp)((temp)=(A),(A)=(B),(B)=(A))

int number = 10;
int data[] = { 1,10,5,8,7,6,4,3,2,9 };

void show() {
	int i;
	for (i = 0; i < number; i++) {
		printf("%d", data[i]);
	}
}

void quickSort(int* data, int start, int end) {
	if (start >= end) {//원소 1개인 경우 그대로 두기.
		return;
	}
	int key = start;//키는 첫 번쨰 원소
	int i = start + 1, j = end, temp;
	while (i <= j) {//엇갈릴 때까지 반복
		while (i <= end && data[i] <= data[key]) {//키 값보다 큰 값을 만날때까지 
			i++;
		}
		while (j > start && data[j] >= data[key]) {//키 값보다 작은 값을 만날때까지
			j--;
		}
		if (i > j) {//현재 엇갈린 상태면 키 값과 교체
			SWAP(data[i], data[j], temp);
		}
	}
	quickSort(data, start, j - 1);//좌측 파티션
	quickSort(data, j + 1, end);//우측 파티션
}
int main(void) {
	quickSort(data, 0, number - 1);//배열이니까 포인터로 지시
	show();
	return 0;
}
//퀵정렬의 평균 시간 복잡도는 O(N*logN), 최악 시간 복잡도는 O(N^2)