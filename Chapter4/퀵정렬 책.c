#include <stdio.h>
typedef int element;
int size, i = 0;
//피벗을 기준으로 양분하여 왼쪽 파티션에서는 피벗값보다 크거나 같은 값을 찾고, 오른쪽 파티션에서는 피벗값보다 작거나 같은 값을 찾는다. 그 이후 왼쪽에서 찾은 값과 오른 쪽에서 찾은 값을 바꾼다.
// 그래서 오른쪽 파티션에는 피벗 값보다 큰값이, 왼쪽 파티션에서는 피벗값보다 작은 값들이 모이게 된다.
// 그리고 이것들을 재귀적으로 불러서 그 안에서 새로운 파티션을 만들고
// 나눠진 파티션들이 부분적으로 2개씩 이루어질 때 모두 결합해서 정렬이 되게 한다.
// 즉 1차원 배열을 다차원으로 만들고, 그것을 다시 1차원으로 돌려버리면 퀵소트가 되는 것이다.
//주어진 부분 집합 안에서 피봇 위치를 확정하여 분할 위치를 정하는 연산

//배열을 사용하는 게 전제가 되어 있다.
int partition(element a[], int begin, int end) {
	int pivot, L, R, t;//배열인덱스를 가지고 노는거다.
	element temp;
	L = begin;
	R = end;
	pivot = (int)((begin + end) / 2.0);

	printf("\n [%d단계 : pivot=%d]\n", ++i, a[pivot]);
	while (L < R) {//start와 end가 교차되는 지점
		while ((a[L] < a[pivot]) && (L < R))L++;//pivot 기준값을 지켜주면 원소자리를 하나씩 앞으로 감
		while ((a[R] >= a[pivot] && (L < R))) R--;
		if (L < R) {
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
			if (L == pivot) pivot = R;

		}
	}
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++)printf("%d", a[t]);
	printf("\n");
	return R;
}

void quickSort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end);//피봇 위치에 따라 분할 위치가 결정됨
		quickSort(a, begin, p - 1);//피봇 왼쪽 부분집합에 대해 퀵 정렬을 재귀호출
		quickSort(a, p + 1, end);//피봇 오른쪽 부분집합에 대해 퀵정렬을 재귀호출
	}
}