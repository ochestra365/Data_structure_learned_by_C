//#include <stdio.h>
//int LSearch(int* pary, int, int);//�Լ�����
//int main() {
//	int ary[] = { 3,5,8,2,7,6,1 };//�迭 �ʱ�ȭ
//	int size = sizeof(ary) / sizeof(ary[0]);//�迭������
//	int index = LSearch(ary,size,2);//��ȯ�� ����
//	if (index == -1) {
//		printf("ã�� ����");//��ȯ�� ��½���	
//	}
//	else {
//		printf("%d�� �濡 ���� �ֽ��ϴ�.", index);//��¼���
//	}
//	return 0;
//}
//
//int LSearch(int* pary, int size, int data) {//�迭�� �����´�.
//	for (int i = 0; i < size; i++) {//�迭�̴ϱ� for��
//		if (data == pary[i]) return i;//���� �� �����Ͱ��� pary������ ���. �迭�� ���� ������ ������ ������ ���� ����. �ð� ���⵵�� ���� �� ����.
//		//�߸��ؼ� ������ ���Ұ� �ɸ��� �ð� ���⵵�� �ſ� �þ��.
//	}
//	return -1;//���� ã�� ���� ������ -1�� ��ȯ�Ѵ�.
//}
////���� �Ÿ� 2�� �̻� �����ϸ� �ȵȴ�.
