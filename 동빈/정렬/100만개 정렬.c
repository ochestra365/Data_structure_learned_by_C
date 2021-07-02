#include <stdio.h>
#define SWAP(x,y,tmp)((tmp)=(x),(x)=(y),(y)=(tmp))
int number, data[1000000];

void quickSort(int* data, int start, int end) {
	if (start >= end) return;//���Ұ� 1���� ��� �״�� �α�
	int key = start;//Ű�� ù���� ����
	int i = start + 1, j = end, tmp;

	while (i <= j) {//������ ������ �ݺ�
		while (data[i] <= data[key]) {//Ű ������ ū ���� ���� ������
			i++;
		}
		while (data[j] >= data[key] && j > start) {//Ű ������ ���� ���� ���� ������
			j--;
		}
	}
	if (i > j) {//���� ������ ���¸� ��ü
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