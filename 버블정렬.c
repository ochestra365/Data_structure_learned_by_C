#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
//버블정렬

void bubble_sort(int list[], int n) {
	int i, j, tmp;
	for (i = n - 1; i > 0; i--) {
		//0~(i-1)까지 반복
		for (j = 0; j < i; j++) {
			//j번째와 j+1번째의 요소가 크기 순이 아니면 교환
			if (list[j] < list[j + 1]) {
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
}

void main() {
	int i;
	int n = MAX_SIZE;
	int list[n] = { 7,4,5,1,3 };

	//버블정렬 수행
	bubble_sort(list, n);
	//정렬결과 출력
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
}