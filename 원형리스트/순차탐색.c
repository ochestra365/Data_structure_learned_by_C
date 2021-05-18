//#include <stdio.h>
//int LSearch(int* pary, int, int);//함수선언
//int main() {
//	int ary[] = { 3,5,8,2,7,6,1 };//배열 초기화
//	int size = sizeof(ary) / sizeof(ary[0]);//배열사이즈
//	int index = LSearch(ary,size,2);//반환값 저장
//	if (index == -1) {
//		printf("찾기 실패");//반환값 출력실패	
//	}
//	else {
//		printf("%d번 방에 값이 있습니다.", index);//출력성공
//	}
//	return 0;
//}
//
//int LSearch(int* pary, int size, int data) {//배열로 가져온다.
//	for (int i = 0; i < size; i++) {//배열이니까 for문
//		if (data == pary[i]) return i;//만약 비교 데이터값과 pary같으면 출력. 배열은 논리적 순서와 물리적 순서가 서로 같다. 시간 복잡도가 별로 안 좋다.
//		//잘못해서 마지막 원소가 걸리면 시간 복잡도가 매우 늘어난다.
//	}
//	return -1;//만약 찾는 값이 없으면 -1을 반환한다.
//}
////같은 거를 2번 이상 선언하면 안된다.
