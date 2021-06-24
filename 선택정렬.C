#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x,y,temp)((temp)=(x),(x)=(y),(y)=(temp))//스왑은 자주 쓰는 알고리즘이니 매크로로 설정하자
#define MAX_SIZE 5

//선택정렬(오름 차순 정렬 시 주어진 배열에서 최소값을 찾고 그것을 차례대로 정렬한다.)
void selection_sort(int list[], int n) {
	int i, j, least, temp;
	//마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1)만큼 반복한다.
	for (i = 0; i < n - 1; i++) {
		least = i;
		//최솟값을 탐색한다.
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least])least = j;
		}
		//최솟값이 자기 자신이면 자료이동을 하지 않는다.
		if (i != least) {
			SWAP(list[i], list[least], temp);
		}
	}
}


int main()
{
	int i;
	int n = MAX_SIZE;
	int list[n] = { 9,6,7,3,5 };

	//선택정렬 수행
	selection_sort(list, n);

	//정렬 결과 출력
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
	return 0;
}