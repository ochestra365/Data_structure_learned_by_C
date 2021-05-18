/*삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다.*/
#include <stdio.h>

void insertionSort(int*, int);//삽입정렬
void print(int*, int);//프린트 정렬
int main() 
{
	int ary[] = { 4,2,7,5,9,1,8,3,6 };//초기화
	int size = sizeof(ary) / sizeof(ary[0]);//사이즈
	insertionSort(ary, size);//삽입정렬
	//print(ary, size);
	return 0;
	
}

void insertionSort(int* pary, int sz) 
{
	int temp;
	for (int i = 1; i < sz; i++) {//전체 반복을 돌려줄 단계 그리고 반복 횟수는 전체 방의 크기보다 작을 수 밖에 없다.
		for (int j = i; j>0;j--) {//n번 째 자료와 초항 까지의 정렬관계식
			if (pary[j] < pary[j - 1]) {//n-1자료가 n자료보다 크면 스왑알고리즘을 시행한다.
				temp = pary[j];//스왑알고리즘
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;//swap 앞에 있는 거 두개 스왑 알고리즘 써서 바꿈
			}
		}
		printf("\n%d단계 : ",i);//단계를 드러낼 것.
		for (int k = 0; k < sz; k++) {
			printf("%d  ", pary[k]);//출력
		}
	}
}
void print(int* pary, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("ary[%d] = %d\n", i,pary[i]);//돌면서 출력해버림
	}
}
