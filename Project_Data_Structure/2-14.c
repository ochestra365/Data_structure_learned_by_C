//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//long int fact(int);
//
//int main(void) {
//	int n, result;
//	printf("���� �Է� : \n");
//	scanf("%d", &n);
//	result = fact(n);
//	printf("\n%d\n%d\n%d", n, result);
//	return 0;
//	
//}
//
//long int fact(int n) {//long int�� ��������̴�. 
//	int value;
//	if (n <= 1){//1�� ���� ������ �ٷ� �������´�. �ֳ��ϸ� 1�� ������ �ִ� �ǹ̴� ���̱� �����̴�.
//		printf("\n fact(1)�Լ� ȣ��!");
//		printf("\n fact(1) �� 1 ��ȯ");
//		return 1;
//	}
//	else
//	{
//		printf("\n fact(%d) �Լ� ȣ��", n);
//		value = (n * fact(n - 1));//���ȣ��� �޸𸮰� �� �Ҵ�ȴ�.
//		printf("\n fact(%d) �� %ld ��ȯ", n, value);
//		return value;
//	}
//}