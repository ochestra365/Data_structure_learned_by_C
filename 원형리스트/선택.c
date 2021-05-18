///* 선택정렬 : 0번방을 최소값이라고 가정한다. */
////최소값 가진 원소들과 나머지 원소들과 자꾸 경쟁시킨다. 그중에서 가장 작은 최소 값이 최소값에 저장된다. 거기 있는 index를 0번방하고 교환한다.
//#include <stdio.h>
//void selectSort(int*, int);
//int main() {
//	int ary[] = { 4,2,7,5,9,1,8,3,6 };//초기화
//	int size = sizeof(ary) / sizeof(ary[0]);//사이즈
//	selectSort(ary, size);//선택 정렬 함수
//	return 0;
//}
//void selectSort(int* pary, int size) 
//{
//	for (int i = 0; i < size - 1; i++) {//사이즈보다 하나 작은 만큼 반복시킨다. 왜냐하면 자기자신과 비교할 필요는 없기 때문이다.
//		int min = i;//최솟값에 i를 넣어준다. 가장 작은 값과 경쟁시켜서 정렬시킨다.
//		for (int j=i+1; j<size; j++) {//키 값을 줬을 때, 나머지 방하고 비교했을 때, 0번방이 최솟값일 때 한번 작업이 끝나면 최솟값을 찾는다.
//			if (pary[min] > pary[j]) min = j;//만약 최솟값넣은 것이 크면 j의 인덱스를 바꾼다.
//		}//그 다음 최솟값을 찾은 값과 첫번쨰와 스왑알고리즘을 통해서 바꿔준다.
//		int temp = pary[min];						//값을 실제로 바꿔준다.
//		pary[min] = pary[i];
//		pary[i] = temp;
//		printf("\n%d 단계 : ",i+1);
//		for (int k = 0; k < size; k++) {//단순한 출력
//			printf("ary[%d] : %d\n", k, pary[k]);
//		}
//	}
//}