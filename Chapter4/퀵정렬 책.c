#include <stdio.h>
typedef int element;
int size, i = 0;
//�ǹ��� �������� ����Ͽ� ���� ��Ƽ�ǿ����� �ǹ������� ũ�ų� ���� ���� ã��, ������ ��Ƽ�ǿ����� �ǹ������� �۰ų� ���� ���� ã�´�. �� ���� ���ʿ��� ã�� ���� ���� �ʿ��� ã�� ���� �ٲ۴�.
// �׷��� ������ ��Ƽ�ǿ��� �ǹ� ������ ū����, ���� ��Ƽ�ǿ����� �ǹ������� ���� ������ ���̰� �ȴ�.
// �׸��� �̰͵��� ��������� �ҷ��� �� �ȿ��� ���ο� ��Ƽ���� �����
// ������ ��Ƽ�ǵ��� �κ������� 2���� �̷���� �� ��� �����ؼ� ������ �ǰ� �Ѵ�.
// �� 1���� �迭�� ���������� �����, �װ��� �ٽ� 1�������� ���������� ����Ʈ�� �Ǵ� ���̴�.
//�־��� �κ� ���� �ȿ��� �Ǻ� ��ġ�� Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����

//�迭�� ����ϴ� �� ������ �Ǿ� �ִ�.
int partition(element a[], int begin, int end) {
	int pivot, L, R, t;//�迭�ε����� ������ ��°Ŵ�.
	element temp;
	L = begin;
	R = end;
	pivot = (int)((begin + end) / 2.0);

	printf("\n [%d�ܰ� : pivot=%d]\n", ++i, a[pivot]);
	while (L < R) {//start�� end�� �����Ǵ� ����
		while ((a[L] < a[pivot]) && (L < R))L++;//pivot ���ذ��� �����ָ� �����ڸ��� �ϳ��� ������ ��
		while ((a[R] >= a[pivot] && (L < R))) R--;
		if (L < R) {
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
			if (L == pivot) pivot = R;

		}
	}
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++)printf("%d", a[t]);
	printf("\n");
	return R;
}

void quickSort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end);//�Ǻ� ��ġ�� ���� ���� ��ġ�� ������
		quickSort(a, begin, p - 1);//�Ǻ� ���� �κ����տ� ���� �� ������ ���ȣ��
		quickSort(a, p + 1, end);//�Ǻ� ������ �κ����տ� ���� �������� ���ȣ��
	}
}