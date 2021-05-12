//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//struct employee {
//	char name[10];
//	int year;
//	int pay;
//};
//int main(void) {
//	struct employee Lee;
//	struct employee* Sptr = &Lee;
//	strcpy(Sptr->name, "이순신");//1인수에 2인수의 값 복사
//	Sptr->year = 2015;//포인터를 이용해서 데이터 할당
//	Sptr->pay = 5900;//포인터를 이요해서 데이터 할당
//
//	printf("\n 이름 : %s", Sptr->name);
//	printf("\n 입사 : %d", Sptr->year);
//	printf("\n 연봉 : %d", Sptr->pay);
//	return 0;
//}