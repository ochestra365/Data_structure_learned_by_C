#include <stdio.h>

void insertionSort(int*, int);
void print(int*, int);
int main() {
	int ary[] = { 4,2,7,5,9,1,8,3,6 };//√ ±‚»≠
	int size = sizeof(ary) / sizeof(ary[0]);
	insertionSort(ary, size);
	return 0;
}
void insertionSort(int*pary, int sz) {
	int temp;
	for (int i = 1; i < sz; i++) {
		for (int j = i; j > 0; j--) {
			if (pary[j] < pary[j - 1]) {
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;

			}
		}
	}
}

void print(int* pary, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("ary[%d]=%d\n", i, pary[i]);
	}
}