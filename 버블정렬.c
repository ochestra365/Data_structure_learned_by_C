#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
//��������

void bubble_sort(int list[], int n) {
	int i, j, tmp;
	for (i = n - 1; i > 0; i--) {
		//0~(i-1)���� �ݺ�
		for (j = 0; j < i; j++) {
			//j��°�� j+1��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
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

	//�������� ����
	bubble_sort(list, n);
	//���İ�� ���
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
}