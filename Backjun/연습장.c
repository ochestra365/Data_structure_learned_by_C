#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int* num = (int*)malloc(sizeof(int));
		int sum = 0, count = 0;
		double avg;
		int arr[num];
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &arr[j]);
		}
	}
	return 0;
}