/*삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다.*/
//정렬되어 있는 리스트중에서 하나 하나 배열요소 값을 비교하여 삽입해서 정렬한다.
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
//안에는 알고리즘만 써주는 거지 구조 자체는 생각을 하지 않는다.
void insertionSort(int* pary, int sz) 
{
	int temp;
	for (int i = 1; i < sz; i++) {//전체 반복을 돌려줄 단계 그리고 반복 횟수는 전체 방의 크기보다 작을 수 밖에 없다. 전체 제어 i
		for (int j = i; j>0;j--) {//n번 째 자료와 초항 까지의 정렬관계식
			if (pary[j] < pary[j - 1]) {//n-1자료가 n자료보다 크면 스왑알고리즘을 시행한다.
				temp = pary[j];//스왑알고리즘
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;//swap 앞에 있는 거 두개 스왑 알고리즘 써서 바꿈
			}
		}
		//printf("\n%d단계 : ",i);//단계를 드러낼 것.
		//for (int k = 0; k < sz; k++) {
		//	printf("%d  ", pary[k]);//출력
		//}
	}
}
//이전 단계는 순차적으로 정렬되어 있다. 현 단계는 이전단계에서 정렬된 리스트와 다음 값을 비교하는 것 밖에 없다.
//그리고 비교 횟수는 당연히 이전 단계 정렬된 배열 요소와 정렬되지 않은 배열 요소를 각각 비교해주는 것이다.
//그래서 이전에 정렬된 것이 2개가 있다고 하면 다음 요소는 2번만 비교하며 된다.
//위 포맷은 각각의 배열 인덱스에 값을 비교하고 할당하는 것이다.
//즉 한 번의 알고리즘만 제대로 정립하면 반복 제어만 잘해줘도 그 한 번의 알고리즘이 표준코딩이 되는 것이다.
void print(int* pary, int sz) {
	for (int i = 0; i < sz; i++) {
		printf("ary[%d] = %d\n", i,pary[i]);//돌면서 출력해버림
	}
}
