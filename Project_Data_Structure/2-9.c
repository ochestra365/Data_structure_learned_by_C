//#include <stdio.h>
//
//int main(void) {
//	int i;//반복 제어 변수
//	char string[20] = "Dreams come true", string2[20], * ptr1, * ptr2;//배열 초기화 및 타 배열 선언, 그리고 포인터 선언
//	ptr1 = string;//초기화 배열을 포인터에 할당
//	printf("string의 주소 = %u \t ptr1=%u\n", string, ptr1);//할당된 포인터와 배열의 시작주소값은 같다.
//	printf("\n string = %s \n ptr1=%s", string, ptr1);//포인터에 배열을 할당하면 배열처럼 쓸 수 있다.
//	printf("\n\n %s", ptr1 + 7);//버퍼의 7번째 방부터 쭉 출력해라-->매우 유용한 출력방식
//	ptr2 = &string[7];//7번째 주소값을 저장
//	printf("\n %s \n\n", ptr2);//이후 주소값이후 쭉 실행
//
//	for (i = 16; i >= 0; i--) {
//		putchar(*(ptr1+i));//버퍼단위의 출력 개념 호환성이 높은 매우 중요한 개념 데이터 값을 출력한다. 거꾸로 출력
//	}
//	for (i = 0; i < 20; i++) {
//		string2[i] = *(ptr1 + i);//버퍼단위의 입력 개념 매우 중요한 개념, 주소에 해당하는 데이터값을 불러서 배열2에 할당한다.
//	}
//	printf("\n\n string =%s", string);
//	printf("\n string2 =%s", string2);
//
//	*ptr1 = 'P';//각 버퍼의 주소번호 순서대로 문자 상수 데이터 할당
//	*(ptr1 + 1) = 'e';
//	*(ptr1 + 2) = 'a';
//	*(ptr1 + 3) = 'c';
//	*(ptr1 + 4) = 'e';
//	printf("\n\n string = %s\n", string);
//	return 0;
//}
//
////버퍼는 액서스 범위단계를 나타내는 거지 자료형 그 자체가 아니다. 실체는 변수의 데이터 타입이다.