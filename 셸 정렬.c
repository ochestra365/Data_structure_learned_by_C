#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,temp)((temp)=(x),(x)=(y),(y)=(temp))
#define MAX_SIZE 10
//���������� ������ ���ķ� ���������� �̿��� ��ġ�͸� ��ȯ�Ǵ� ���� �����ϴ� ���̴�. ������� 10�� ��忡�� 5�� �ʸ� ��ġ �׸��� 3�� �ʸ���ġ �̷��� ���� �� �ְ� �ϴ� ���̴�.
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];//���� ���Ե� ������ i��° ������ key ������ ����
		//���� ���ĵ� �迭�� i-gap�����̹Ƿ� i-gap��° ���� �������� �����Ѵ�.
		//j���� first�̻��̾�� �ϰ�
		//key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+gap��°�� �̵�
		for (j = i - gap; j >= first && list[j] > key; j = j - gap) {
			list[j + gap] = list[j];//���ڵ带 gap��ŭ ���������� �̵�
		}
		list[j + gap] = key;
	}
}
//�� ����
void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 2) { gap++; }//gap�� Ȧ���� �����.

		//�κ� ����Ʈ�� ������ gap�� ����.
		for (i = 0; i < gap; i++) {
			//�κ� ����Ʈ�� ���� ���� ���� ����
			inc_insertion_sort(list, i, n - 1, gap);
		}
	}
}
int main() {
	int i;
	int n = MAX_SIZE;
	int list[n] = { 10,8,6,20,4,3,22,1,0,15,16 };

	//�� ���� ����
	shell_sort(list, n);
	//���� ��� ���
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
	return 0;
}