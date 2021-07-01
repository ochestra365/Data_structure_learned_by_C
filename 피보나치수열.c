#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 1, c = 0, i = 0, answer = 0;
	printf("input number : ");
	scanf_s("%d", &answer);
	for (i = 1, i <= answer; i++) {
		printf("%d", a);
		c = a + b;
		a = b;
		b = c;
	}
	return 0;
}