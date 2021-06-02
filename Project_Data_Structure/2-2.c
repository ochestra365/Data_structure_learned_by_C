#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print_line(void);
int main(void) {
	int i,j;
	scanf("%d", &i);
	printf("구구단 %d단을 입력하세요 : ", i);
	while (1) {
		if (i < 0 || i>9)
			printf("구구단이라고요. 9단까지 하세요");
		else break;
	}
	for (j = 1; j <= 9; j++) {
		printf("%d * %d = %d\n", i, j, (i * j));
	}
		/*for (i = 1; i <= 9; i++) {
			printf("구구단 %d단입니다.\n", i);
			for (j = 1; j <= 9; j++) {
				printf("%d * %d = %d\n", i, j, (i * j));
			}
			print_line();
		}*/
	return 0;
}

void print_line(void) {
	int i;
	for (i = 0; i < 50; i++) {
		printf("=");
	}
	printf("\n");
}