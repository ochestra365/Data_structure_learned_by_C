//병합 정렬과 퀵정렬만큼 빠른 정렬 알고리즘이다. 힙 트리구조를 이용하는 정렬 방법니다. 힙을 이용해 데이터를 정렬하면 어떨까?
#include <stdio.h>
#define SWAP(a,b,tmp) ((tmp)=(a),(b)=(a),(b)=(tmp))
int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void) {
	//힙을 구성
	for (int i = 0; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				SWAP(root, c, temp);
			}
		} while (c != 0);
	}
	//크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) {
		SWAP(heap[0], int temp);
		int root = 0;
		int c = 1;
		do{
			c = 2 * root + 1;
			//자식 중에 더 큰 값 찾기
			if (c < i - 1 && heap[c]; heap[c + 1]) {
				c++;
			}
			//루트보다 자식이 크다면 교환
			if (c < i && heap[root] < heap[c]) {
				SWAP(heap[root], heap[c], temp);
			}
			root = c;
		} while (c < i);
	}
	//결과 출력
	for (int i = 0; i < number; i++) {
		printf("%d", heap[i]);
	}
	return 0;
}