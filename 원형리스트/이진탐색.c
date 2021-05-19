#include <stdio.h>
//n/2의 형식으로 탐색하겠다. 범위를 쪼개서 이진탐색 반으로 범위를 나눠서 순차탐색보다 빨리 찾는다. 순차탐색보다 탐색하는 시간이 빠르다.
//log형식이다. n^2가 가장 안 좋다. 큰 거는 뒤쪽 작은 거는 앞쪽으로 와야 한다.
int main() {
	int ary[] = { 3,5,8,2,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;

	index = BSearch(ary,size,6);
	if (index == -1)printf("탐색실패");
	else printf("%d\n", index);

	return 0;
}
int BSearch(int* pary, int size, int data) {
	int first = 0;//배열 인덱스를 제어하기 위한 상태값
	int last = size - 1;//배열 인덱스를 제어하기 위한 상태값
	int mid;//배열 인덱스를 제어하기 위한 상태값
	while (first <= last) {
		mid = (first + last) / 2;//평균값-->이진 탐색에서 가장 중요한 부분
		if (data == pary[mid]) return mid;
		else {//target data와 다르면 범위를 2진으로 나눈다.
			if (pary[mid] < data) first = mid + 1;//중간값의 다음방부터 찾게 된다. 작은 값의 범위는 first~mid-1 -->반복하는 게 이진 탐색이다.
			else last = mid - 1;
		}
	}
	return -1;
}
//탐색을 하기 위해서는 먼저 데이터가 정렬될 필요가 있다. 그렇지 않으면 case by case로 값을 찾는다.