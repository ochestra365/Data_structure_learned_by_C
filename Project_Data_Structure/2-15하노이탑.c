//#include <stdio.h>
//
//void hanoi(int n, int start, int work, int target);
//int main(void) {
//	hanoi(5, '1', '2', '3','4','5');
//	return 0;
//}
//
//void hanoi(int n, int start, int work, int target) {
//	if (n == 1) {//기저조건
//		printf("%c에서 원반 %d를 %c로 옮김\n", start, n, target);
//	}
//	else {
//		hanoi(n - 1, start, target, work);
//		printf(" %c에서 원반 %d를 %c로 옮김\n", start, n, target);
//		hanoi(n - 1, work, start, target);
//	}
//}
