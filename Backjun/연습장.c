//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//long long sum(int* a, int n);
//
//int main() {
//	int ary[5] = { 1,2,3,4,5 };
//	int* pary = ary;
//	int res;
//	res=sum(pary, 3);
//	printf("%d", res);
//	return 0;
//}
//long long sum(int* a, int n) {
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		res += a[i];
//	}
//	return res;
//}
//
////a: ���� ���ؾ� �ϴ� ���� n���� ����Ǿ� �ִ� �迭(0 �� a[i] �� 1, 000, 000, 1 �� n �� 3, 000, 000)
////n : ���� ���ؾ� �ϴ� ������ ����
////���ϰ� : a�� ���ԵǾ� �ִ� ���� n���� ��