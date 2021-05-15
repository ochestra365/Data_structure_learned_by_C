//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main() {
//	int arr[10];
//	int res = 0;
//	int i, j;
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &arr[i]);
//		arr[i] = arr[i] % 42;
//	}
//	for (int i = 0; i < 10; i++) {
//		int cnt = 0;
//		for (j = 0; j < i; i++) {
//			if (arr[i] == arr[j]) cnt++;
//		}
//		if (cnt == 0)res++;
//	}
//	printf("%d", res);
//	return 0;
//}