/*�������� : �ι�° �ڷ���� �� �ڷḦ ���Ͽ� �����Ѵ�.*/
#include <stdio.h>

void insertionSort(int*, int);//��������
void print(int*, int);//����Ʈ ����
int main() 
{
	int ary[] = { 4,2,7,5,9,1,8,3,6 };//�ʱ�ȭ
	int size = sizeof(ary) / sizeof(ary[0]);//������
	insertionSort(ary, size);//��������
	//print(ary, size);
	return 0;
	
}

void insertionSort(int* pary, int sz) 
{
	int temp;
	for (int i = 1; i < sz; i++) {//��ü �ݺ��� ������ �ܰ� �׸��� �ݺ� Ƚ���� ��ü ���� ũ�⺸�� ���� �� �ۿ� ����.
		for (int j = i; j>0;j--) {//n�� ° �ڷ�� ���� ������ ���İ����
			if (pary[j] < pary[j - 1]) {//n-1�ڷᰡ n�ڷẸ�� ũ�� ���Ҿ˰����� �����Ѵ�.
				temp = pary[j];//���Ҿ˰���
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;//swap �տ� �ִ� �� �ΰ� ���� �˰��� �Ἥ �ٲ�
			}
		}
		printf("\n%d�ܰ� : ",i);//�ܰ踦 �巯�� ��.
		for (int k = 0; k < sz; k++) {
			printf("%d  ", pary[k]);//���
		}
	}
}
void print(int* pary, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("ary[%d] = %d\n", i,pary[i]);//���鼭 ����ع���
	}
}
