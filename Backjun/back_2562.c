//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main() {
//	int i,j;
//	int* ary = (int*)malloc(sizeof(int));
//	int max=ary[0];
//	for (i = 0; i < 9; i++) {
//		scanf("%d", &ary[i]);
//	}
//	for (i = 0; i < 9; i++) {
//		for (j =i+1; j < 9; j++) {
//			if (ary[i] == ary[j]) {
//				printf("%d번째 수와 %d 번쨰 수가 같습니다.", i, j); break;
//			}
//		}
//		if (max < ary[i]) max = ary[i];
//	}
//	printf("%d", max);
//	for (i = 0; i < 9; i++) {
//		free(ary+i);
//	}
//	return 0;
//}