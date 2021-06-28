//���� ���� �˰���-->������ ���� 2������ �и��ϰ� ������ �ذ��ϰ� ����� ��Ƽ� ������ ������ �ذ��ϴ� ����, �ſ� ���� ���� �ӵ�
//����Ʈ�� �� ��Ҵ� �ǹ�(pivot)�̶�� �Ѵ�. �ǹ��� �������� ���� ��ҵ��� ��� ��������, �ǹ����� ū ���� ��� ���������� ������.
//�ǹ��� ������ ���� ����Ʈ�� ������ ����Ʈ�� �ٽ� �����Ѵ�.
//���ҵ� �κ� ����Ʈ�� ���ؼ� ��ȯ ȣ���� �̿��ؼ� ������ �ݺ��Ѵ�.-->����, ����, ����
#include <stdio.h>
#define MAX_SIZE 9
#define SWAP(x,y,temp)((temp)=(x),(x)=(y),(y)=(temp))
//1. �ǹ��� �������� 2���� �κи���Ʈ�� ������.
//2. �ǹ����� ���� ���� ��� ���� �κ� ����Ʈ��, ū ���� ������ �κ� ����Ʈ�� �ű��.
//3. 2���� ��յ� �迭�� �պ�����
/*������ ���ڵ��� ���ĵǴ� ����*/
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right;
	pivot = list[left];// ������ ����Ʈ�� ���� ���� �����͸� �ǹ����� ����(������ �� ����)
/*low�� high�� ������ ������ �ݺ�(low<high)*/
	do {
		/*list[low]�� �ǹ����� ������ ��� low�� ����*/
		do {
			low++;//low�� left +1���� ����
		} while (low <= right && list[low] < pivot);
		/*list[high]�� �ǹ����� ũ�� ��� high�� ����*/
		do {
			high--;//high�� right���� ����
		} while (high >= left && list[high] > pivot);

		//���� low�� high�� �������� �ʾ����� list[low]�� list[high]��ȯ
		if (low < high) {
			SWAP(list[low], list[high], temp);
		}while (low < high);

		//low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
		SWAP(list[left], list[high], temp);

		//�ǹ��� ��ġ�� high�� ��ȯ
		return high;
	}
}
//�� ����
void quick_sort(int list[], int left, int right) {
	/*������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �ƴϸ�*/
	if (left < right) {
		//partition �Լ��� ȣ���ؼ� �ǹ��� �������� ����Ʈ�� ��յ� ����-����(Divide)
		int q = partition(list, left, right);//q �ǹ��� ��ġ
		//�ǹ��� ������ 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
		quick_sort(list, left, q - 1);//(left~�ǹ� �ٷ� ��) ���� �κ� ����Ʈ ����
		quick_sort(list, q + 1, right);//(�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ����
	}
}
void main() {
	int i;
	int n = MAX_SIZE;
	int list[n] = { 5,3,8,4,9,1,6,2,7 };

	//�� ���� ����(left: �迭�� ���� =0, right: �迭�� �� =8)
	quick_sort(list, 0, n - 1);
	//���İ�� ���
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
}