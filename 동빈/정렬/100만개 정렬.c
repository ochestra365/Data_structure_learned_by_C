#include <stdio.h>
#define SWAP(x,y,tmp)((tmp)=(x),(x)=(y),(y)=(tmp))
int number, data[1000000];

void quickSort(int* data, int start, int end) {
	if (start >= end) return;//원소가 1개인 경우 그대로 두기
	int key = start;//키는 첫번쨰 원소
	int i = start + 1, j = end, tmp;

	while (i <= j) {//엇갈리 때까지 반복
		while (data[i] <= data[key]) {//키 값보다 큰 값을 만날 때까지
			i++;
		}
		while (data[j] >= data[key] && j > start) {//키 값보다 작은 값을 만날 때까지
			j--;
		}
	}
	if (i > j) {//현재 엇갈린 상태면 교체
		SWAP(data[i], data[j], tmp);
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}



int main() {
	scanf_s("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &data[i]);
	}
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}