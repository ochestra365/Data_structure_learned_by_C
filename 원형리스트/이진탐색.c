#include <stdio.h>
//n/2�� �������� Ž���ϰڴ�. ������ �ɰ��� ����Ž�� ������ ������ ������ ����Ž������ ���� ã�´�. ����Ž������ Ž���ϴ� �ð��� ������.
//log�����̴�. n^2�� ���� �� ����. ū �Ŵ� ���� ���� �Ŵ� �������� �;� �Ѵ�.
int main() {
	int ary[] = { 3,5,8,2,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;

	index = BSearch(ary,size,6);
	if (index == -1)printf("Ž������");
	else printf("%d\n", index);

	return 0;
}
int BSearch(int* pary, int size, int data) {
	int first = 0;//�迭 �ε����� �����ϱ� ���� ���°�
	int last = size - 1;//�迭 �ε����� �����ϱ� ���� ���°�
	int mid;//�迭 �ε����� �����ϱ� ���� ���°�
	while (first <= last) {
		mid = (first + last) / 2;//��հ�-->���� Ž������ ���� �߿��� �κ�
		if (data == pary[mid]) return mid;
		else {//target data�� �ٸ��� ������ 2������ ������.
			if (pary[mid] < data) first = mid + 1;//�߰����� ��������� ã�� �ȴ�. ���� ���� ������ first~mid-1 -->�ݺ��ϴ� �� ���� Ž���̴�.
			else last = mid - 1;
		}
	}
	return -1;
}
//Ž���� �ϱ� ���ؼ��� ���� �����Ͱ� ���ĵ� �ʿ䰡 �ִ�. �׷��� ������ case by case�� ���� ã�´�.