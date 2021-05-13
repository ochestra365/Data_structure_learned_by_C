//#include <stdio.h>
//
//typedef struct {
//	int row;
//	int col;
//	int value;
//}term;
//
//void smTransepose(term a[], term b[]) {//구조체 배열들을 각각 인수로 갖는다. a는 희소행렬이고, b는 전치행렬이다.
//	//메인에 a와 b의 구조체를 써서 구조체 배열을 만든다.
//	int m, n, v, i, j, p;
//	//따로 데이터를 분할해서 쓰는 이유는 그 데이터도 쓰겠다는 의미이다.
//	m = a[0].row;//희소 행렬 a의 수
//	n = a[0].col;//희소 행렬 열 수
//	v = a[0].value;//희소 행렬 a에서 0이 아닌 원소 수 
//	b[0].row = n;//전치 행렬 b의 행수==희소행렬 a의 수
//	b[0].col = m;//전치 행렬 b의 열수==희소행렬 b의 수
//	b[0].value = v;//전치 행렬 b의 원소수 
//	if (v > 0) {//모든 행렬 요소가 0이 아니면
//		p = 1;//일단 1값을 p에 할당
//		for (i = 0; i < n; i++) {
//			for (j = 1; j <= v; j++) {
//				if (a[j].col == i) {
//					b[p].row = a[j].col;
//					b[p].col = a[j].row;
//					b[p].value = a[j].value;
//					p++;
//				}
//			}
//		}
//	}
//}
