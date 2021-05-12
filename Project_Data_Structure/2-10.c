//#include <stdio.h>
//
//int main(void) {
//	int i;//반복 제어 변수
//	char* ptrArray[4] = { {"Korea"},{"Seoul"},{"Mapo"},{"152번지 2/3"} };//주소의 초기화 맨 앞의 주소값이 포인터로 저장된다.
//	for (i = 0; i < 4; i++) {
//		printf("\n%s", ptrArray[i]);//각 단위에 초기화된 배열들을 출력해서 불러와라.%s변환문자이므로 각 단위별로 끊어서 가져온다. 
//	}
//	ptrArray[2] = "Jongro";//3번방에 종로의 문자열을 삽입해라 이때, J의 시작주소값이 저장될 것이다.
//	printf("\n\n");
//	for (i = 0; i < 4; i++) {
//		printf("\n%s", ptrArray[i]);//배열의 각 요소를 순차적으로 출력 시행하기 위한 조건문이다.
//	}
//	return 0;
//}