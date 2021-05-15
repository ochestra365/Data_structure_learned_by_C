#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,i;
	int* score_ary = (int*)malloc(sizeof(int));
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &score_ary[i]);
	}
	return 0;
}