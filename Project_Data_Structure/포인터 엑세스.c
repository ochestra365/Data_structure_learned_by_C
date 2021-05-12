//#include <stdio.h>
//
//int main(void) {
//	int i = 10,j=20;
//	int* pi,*pj;
//	pi = &i;
//	pj = &j;
//
//	printf("i와 j의 데이터 값 : %d, %d\n", i, j);
//	printf("i와 j의 주소값 : %d, %d\n", &i, &j);
//	printf("pi와 pj가 가리키는 데이터 값 : %d, %d\n", *pi, *pj);
//	printf("pi와 pj가 가리키는 변수의 주소값 : %d,%d\n", &(*pi), &(*pj));
//	printf("pi와 pj의 주소값 : %d, %d\n", &pi, &pj);
//	printf("pi와 pj의 데이터 값 : %d, %d", pi, pj);
//	printf("pi와 pj의 거리 : %u", pi - pj);//일련의 선언 시 일정 단위 이후에 바로 메모리에 할당되는 것을 알 수있다.
//
//	return 0;
//}