/* �� ���� : ��ǥ���� ���� ���� �˰���*///�ð����⵵�� ���� ����. n*log(n)
/* ������ �Ǿ� ���� ����  �������� ����ϸ� ������.
1. �Ǻ�[pivot]�̶�� ���� ������ �Ѵ�.
2. ���ҵ� �߿��� ������ ����. �� pivot�� �������� ���� ���� ��, �ڿ��� ū ���� ��ġ��Ų��.(����)
3. ���ҵ� ���� ����Ʈ���� ��������� ������ ��Ų��. ���� ������ �˰����� ��� �ݺ���Ų��.(����)
4. ���ĵ� ���� ����Ʈ���� �����Ѵ�.(����) left�� ���������� ���鼭 pivot�� ū ������ ã�� ,right�� �������� ���鼭 pivot���� ���� ���� ã�� �������� ������ �̷������.
*/
#include <stdio.h>
void quickSort(int*, int Left, int Right);//��ƴ� �𸣰ڴ�.
int main() {
	int ary[] = { 3,5,2,4,7,1,6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);//������ 0���� �Ǵϱ� ������ �ε��� ��.
	return 0;
}
//���°��� ������ ���� �޸𸮸� ���� ������ �Ŵ� �ƴϴ�.
void quickSort(int* pary, int left, int right) //�ε��� ���� ������ ���ؼ��̴�.
{
	if (left >= right) return;//��������
	int pivot = left;
	int temp;
	int Lleft = pivot + 1;//0�� ���ذ� �ڱ��ڽŰ� ���� �ʿ�� �����ϱ�
	int Lright = right;//�ǳ����� ���� ã�ƺ���.
	while (Lleft <= Lright) {//��ü�� �ȵ� ������ ���� ���Ѵ�. Lleft�� Lright�� ��ü�� �� �ɶ����� 
		while (pary[Lleft] <= pary[pivot]) Lleft++;//���ʺ��� ���������� �̵�, �ε��� ���� �ǵ��.
		while (pary[Lright] >= pary[pivot]&&Lright>left)Lright--;//�����ʿ��� �������� �̵� &&������ ������ �迭������ �Ѿ ������ �ǹ���, �ε��� ���� �ǵ��.

		if (Lleft > Lright) {//��ü�Ǿ���. ���� �ε����� ���� ���� ���̴�. 
			temp = pary[Lright];
			pary[Lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else {
			temp = pary[Lright];
			pary[Lright] = pary[Lleft];
			pary[Lleft] = temp;
		}
	}
	for (int k = 0; k < right + 1; k++) {
		printf("%d  ", pary[k]);
	}
	printf("\n");
	quickSort(pary, left, Lright - 1);//��͸� �ؿ� �޾��༭ �ٽ� pivot���� �ڵ鸵�� �� �ְ���
	quickSort(pary, Lright + 1, right);//��͸� �ؿ� �޾��༭ �ٽ� pivot���� �ڵ鸵�Ҽ� �ְ���.
	//�׷��� �ǹ��� �̵��� �ε��� �迭��� �߰��� �Ǿ ���� ����Ʈ �ΰ��� ������ �ǰ� �� ������ ���Ľ�Ű�� �����̴�.
}//while�� �ε������� �±��Ѱ� ������� ������ �Ǵ� �̺а���� �����ϴ�. �׸��� ��ͺκ��� �ǹ����� �ϳ��� ���������� �Űܼ� ����Ʈ���� �迭��Ű�� ��Ȳ�� �ǹ��Ѵ�.