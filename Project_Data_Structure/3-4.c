#include <stdio.h>
#define MAX(a,b)((a>b)?a:b)//매크로 a가 b보다 크면 a를 실행 매크로를 쓰면 함수를 구현해주지 않아도 수식 계산이 매우 편해진다.
//나중에 헤더 파일에 넣어야 할 것들이다.
#define MAX_DEGREE 50//최고 넣을 수 있는 계수의 가짓수 50까지이다.-->시스템 함수일 거다.

typedef struct {//구조체 정의
	int degree;//차수다항식의 차수를 저장할 변수//지수라는 의미이다.
	float coef[MAX_DEGREE];//계수//각 항의 계수를 저장할 1차원 배열//계수라는 의미이다.//배열의 출력값은 실수형이다.
}polynomial;//다항식의 라는 의미다.
 
polynomial addPoly(polynomial, polynomial);//출력 1개, 입력 2개 다항식은 다항식으로 출력되니 다항식 변수르 ㄹ쓴다.
void printPoly(polynomial);

int main(void) {
	polynomial A= { 3,{4,3,5,0} };//다항식의 초기화// A는 3차항의 정보를 가지고있다.
	polynomial B = { 4,{3,1,0,2,1} };//B는 4차항의 정보를 가지고 있다.

	polynomial C;//다항식 A,B를 덧셈을 시행할 값을 저장할 구조체변수
	C = addPoly(A, B);//아직까지는 덧셈을 해주기 위한 함수호출 C는 A,B의 합을 리턴받아서 C에 저장한다.//반환 데이터 타입과 저장할 변수의 타입을 같게 해주어야 한다.
	printf("\nA(x) = "); printPoly(A); //같은 기능을 해주는 함수들은 한 코드상에 써주는 것이 좋다.
	printf("\nB(x)="); printPoly(B);
	printf("\nC(x)="); printPoly(C);
	return 0;
}

polynomial addPoly(polynomial A, polynomial B) {//지금 A와 B의 차수와 계수들을 모두 복사해왔다.
	polynomial C; //다항식의 덧셈 결과를 저장할 구조체 변수 선언
	int A_index = 0, B_index = 0, C_index = 0;//인덱스 초기화는 어떤 용도? 반복문을 제어해주기 위한 용도
	int A_degree = A.degree, B_degree = B.degree;//메인에서 복사해온 차수를 초기화된 함수의 지역변수에 대입한다.
	C.degree = MAX(A.degree, B.degree);//매크로 활용이다. 해당 매크로는 A가 크면 A를 반환하고, 그렇지않으면 B를 반환한다.
	//그 반환값을 C의 최고 차수에 대입하여 할당했다.

	while (A_index <= A.degree && B_index <= B.degree) {//3단 분기가 설정되어 있는 상태이고, 차수별로 논리지시자가 옮겨간다.
		if (A_degree > B_degree) {//차수의 가능한 조건 분기를 지금 설정해주고 있는 것이다. 
			C.coef[C_index++] = A.coef[A_index++]+B.coef[B_index++];//해당 코드의계수를 사용하겠다.// 배열을 후위연산으로 시행
			//구조체를 써서 순차 자료구조로 만들었다.
			A_degree--;//차수를 하나씩 낮춰서 비교해간다.
		}
		else if (A.degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {//마지막 분기
			C.coef[C_index++] = B.coef[B_index++];//후위연산자니까 0번인덱스
			B_degree--;
		}//최고차항의 계수를 가져온다.//각각의 연산을 모두 시행돌릴떄까지 계속 반복되는 로직이다.
	}
	//index는 반복문 결과값의 누계를 써서 반복문에서 활용될 수 있도록 한다.
	return C;//while 문을 빠져 나오면 연산이 종료된다.
}
//연산의 기본 알고리즘을 정확하게 꿰뚫고 있어야 풀수 있다.
void printPoly(polynomial P) {
	int i, degree;//지역변수 내에서 차수와 반복제어 변수 설정
	degree = P.degree;//복사한 거를 해당 메모리에 저장 연산이 끝나면 사라지게 할 용도
	for (i = 0; i <= P.degree; i++) {//P의 차수만큼 쓸 수 있게 해준다. 버퍼에 저장한다.
		printf("%3.0fx^%d", P.coef[i], degree--);//%3.0f 변환문자가 의미하는 바는 숫자이다.
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}
//구현파트는 버퍼, 알고리즘은 수학이다.