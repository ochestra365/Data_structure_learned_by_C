#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int* num = (int*)malloc(sizeof(int));
		int tmp = *num;
		int sum = 0, count = 0;
		double avg;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", num[j]);
			sum += num[j];
		}
		avg = sum / tmp;
		for (int k = 0; k < num; k++) {
			if (avg < num[k]) count++;
		}
		free(num + i);
	}
	return 0;
}