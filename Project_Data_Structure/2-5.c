#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[80];//���ڸ� ������ �迭 ����
	int i;//�ݺ� �����
	int cnt = 0;//������ ���� ����
	scanf("%s", str);
	for (i = 0; i < str[i]; i++) {//���ڿ��� ���̸�ŭ ������
		cnt++;//���� ����
	}
	printf("%d", cnt);//�ݺ����� ���� ���� ���� ������ ��°����� ��.
	return 0;
}