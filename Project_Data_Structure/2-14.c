//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//long int fact(int);
//
//int main(void) {
//	int n, result;
//	printf("정수 입력 : \n");
//	scanf("%d", &n);
//	result = fact(n);
//	printf("\n%d\n%d\n%d", n, result);
//	return 0;
//	
//}
//
//long int fact(int n) {//long int가 출력형식이다. 
//	int value;
//	if (n <= 1){//1을 집어 넣으면 바로 빠져나온다. 왜냐하면 1이 가지고 있는 의미는 참이기 때문이다.
//		printf("\n fact(1)함수 호출!");
//		printf("\n fact(1) 값 1 반환");
//		return 1;
//	}
//	else
//	{
//		printf("\n fact(%d) 함수 호출", n);
//		value = (n * fact(n - 1));//재귀호출시 메모리가 또 할당된다.
//		printf("\n fact(%d) 값 %ld 반환", n, value);
//		return value;
//	}
//}