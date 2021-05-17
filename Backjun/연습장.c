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
////a: 합을 구해야 하는 정수 n개가 저장되어 있는 배열(0 ≤ a[i] ≤ 1, 000, 000, 1 ≤ n ≤ 3, 000, 000)
////n : 합을 구해야 하는 정수의 개수
////리턴값 : a에 포함되어 있는 정수 n개의 합