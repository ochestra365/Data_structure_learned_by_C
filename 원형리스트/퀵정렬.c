/* 퀵 정렬 : 대표적인 분할 정복 알고리즘*///시간복잡도가 가장 좋다. n*log(n)
/* 정렬이 되어 있지 않은  구조에서 사용하면 빠르다.
1. 피봇[pivot]이라는 것을 만들어야 한다.
2. 원소들 중에서 기준을 고른다. 이 pivot을 기준으로 앞은 작은 값, 뒤에는 큰 값을 위치시킨다.(분할)
3. 분할된 작은 리스트들을 재귀적으로 동작을 시킨다. 같은 형태의 알고리즘을 계속 반복시킨다.(정복)
4. 정렬된 작은 리스트들을 결합한다.(결합) left는 오른쪽으로 가면서 pivot을 큰 값들을 찾고 ,right는 왼쪽으로 가면서 pivot보다 작은 값을 찾고 양측에서 정렬이 이루어진다.
*/
#include <stdio.h>
void quickSort(int*, int Left, int Right);//어렵다 모르겠다.
int main() {
	int ary[] = { 3,5,2,4,7,1,6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);//시작이 0부터 되니까 마지막 인덱스 값.
	return 0;
}
void quickSort(int* pary, int left, int right) 
{
	if (left >= right) return;//기저조건
	int pivot = left;
	int temp;
	int Lleft = pivot + 1;//0번 기준값 자기자신과 비교할 필요는 없으니까
	int Lright = right;//맨끝에서 부터 찾아본다.
	while (Lleft <= Lright) {//교체가 안될 때까지 서로 비교한다. Lleft와 Lright가 교체가 안 될때까지 
		while (pary[Lleft] <= pary[pivot]) Lleft++;//왼쪽부터 오른쪽으로 이동
		while (pary[Lright] >= pary[pivot]&&Lright>left)Lright--;//오른쪽에서 왼쪽으로 이동 &&조건이 없으면 배열조건을 넘어서 실행이 되버림

		if (Lleft > Lright) {//교체되었다. 작은 인덱스의 값이 작은 값이다. 
			temp = pary[Lright];
			pary[Lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else {
			temp = pary[Lright];
			pary[Lright] = pary[Lleft];
			pary[Lleft] = temp;
		}
	}
	for (int k = 0; k < right + 1; k++) {
		printf("%d  ", pary[k]);
	}
	printf("\n");
	quickSort(pary, left, Lright - 1);//아예 모른다.
	quickSort(pary, Lright + 1, right);
}