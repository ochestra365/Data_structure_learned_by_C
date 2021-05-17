#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a;
	int b;
	
	if (scanf("%c", &a)) {
		printf("%p", &a);
	}
	else if(scanf("%d", &b)) {
		printf("%p", &b);
	}
	return 0;
}