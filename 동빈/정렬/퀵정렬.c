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
	if (start >= end) {//���� 1���� ��� �״�� �α�.
		return;
	}
	int key = start;//Ű�� ù ���� ����
	int i = start + 1, j = end, temp;
	while (i <= j) {//������ ������ �ݺ�
		while (i <= end && data[i] <= data[key]) {//Ű ������ ū ���� ���������� 
			i++;
		}
		while (j > start && data[j] >= data[key]) {//Ű ������ ���� ���� ����������
			j--;
		}
		if (i > j) {//���� ������ ���¸� Ű ���� ��ü
			SWAP(data[i], data[j], temp);
		}
	}
	quickSort(data, start, j - 1);//���� ��Ƽ��
	quickSort(data, j + 1, end);//���� ��Ƽ��
}
int main(void) {
	quickSort(data, 0, number - 1);//�迭�̴ϱ� �����ͷ� ����
	show();
	return 0;
}
//�������� ��� �ð� ���⵵�� O(N*logN), �־� �ð� ���⵵�� O(N^2)