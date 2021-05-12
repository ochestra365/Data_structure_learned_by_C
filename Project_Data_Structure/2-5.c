#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[80];//문자를 저장할 배열 선언
	int i;//반복 제어변수
	int cnt = 0;//세어줄 변수 측정
	scanf("%s", str);
	for (i = 0; i < str[i]; i++) {//문자열의 길이만큼 돌려라
		cnt++;//개수 누적
	}
	printf("%d", cnt);//반복문을 빠져 나온 최종 개수를 출력값으로 함.
	return 0;
}