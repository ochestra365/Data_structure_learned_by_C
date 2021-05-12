//#include <stdio.h>
//
//int main(void) {
//	char* ptrArray[2];//포인터 배열
//	char** ptrptr;//이중 포인터
//	int i;
//	//포인터 배열은 논리적 연결을 시퀀스화 한 것이다.
//	ptrArray[0] = "Korea";//포인터 배열의 초기 배열요소에 K의 시작주소값 삽입
//	ptrArray[1] = "Seoul";//포인터 배열의 차기 배열요소에 S의 시작주소값 삽입
//
//	ptrptr = ptrArray;//포인터 배열의 시작주소값을 이중포인터에 할당
//	printf("\n ptrArray[0]의 주소 (&ptrArray[0])=%u", &ptrArray[0]);//초기 주소
//	printf("\n ptrArray[0]의 값 (ptrArray[0]=%u	", ptrArray[0]);//초기 주소 값
//	printf("\n ptrArray[0]의 참조값 (*ptrArray[0])=%c", *ptrArray[0]);//참조 문자값
//	printf("\n ptrArray[0]의 참조 문자열 (*ptrArray[0])=%s\n", *ptrArray);//참조 문자열을 통해 메모리 주소로 타고 들어가서 개행문자를 만나기 전까지 모두 출력
//
//	printf("\n ptrArray[1]의 주소 (&ptrArray[1]=%u)", &ptrArray[1]);//차기 주소값 초기 주소값과 완전히 다르다.
//	printf("\n ptrArray[1]의 값 (ptrArray[1]=%u", ptrArray[1]);//차기 주소가 가리키는 값 주소
//	printf("\n ptrArray[1]의 참조값 (*ptrArray[1])=%c", *ptrArray[1]);//차기 배열요소의 첫번째 값
//	printf("\n ptrArray[1]의 참조 문자열 (*ptrArray[1])=%s\n", *(ptrArray + 1));//참조 문자열을 통해 차기 버퍼를 모두 출력
//
//	printf("\n ptrptr의 주소 (&ptrptr) = %u", &ptrptr);//이중포인터의 주소
//	printf("\n ptrtpr의 값 (ptrptr)=%u", ptrptr);//이중포인터의 주소와 포인터 배열의 주소는 서로 같다.
//	printf("\n ptrptr의 1차 참조값 (*ptrptr)=%u", *ptrptr);//1차 참조 값은 포인터 배열의 첫번쨰 배열요소 값.
//	printf("\n ptrptr의 2차 참조값 (**ptrptr)=%u", **ptrptr);//2차 참조값은 가리키는 문자의 아스키코드 값.
//	printf("\n ptrptr의 2차 참조 문자열 (**ptrptr)=%s", *ptrptr);//참조 문자열 모두 출력
//	
//	printf("\n\n *ptrArray[0]: ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(ptrArray[0] + i));//버퍼단위로 끊어서 출력 배열요소의 방을 단위별로 쪼개서 출력
//	}
//	printf("\n **ptrptr : ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(*ptrptr + i));//각 버퍼단위로 끊어서 출력(1차 참조의 주소값)
//	}
//	printf("\n\n *ptrArray[1] : ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(ptrArray[1] + i));//각 버퍼단위로 끊어서 가져옴
//	}
//	printf("\n **(ptrptr1) : ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(*(ptrptr + 1) + i));//상기와 같은 내용임
//	}
//	return 0;
//}
////배열은 무조건 등차수열이다. 그런데 논리적 단위의 연결도 있다. 이걸 그림으로 도식화해서 발견해야 한다.
