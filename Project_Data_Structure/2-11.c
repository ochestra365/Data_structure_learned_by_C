//#include <stdio.h>
//
//int main(void) {
//	char* ptrArray[2];//������ �迭
//	char** ptrptr;//���� ������
//	int i;
//	//������ �迭�� ���� ������ ������ȭ �� ���̴�.
//	ptrArray[0] = "Korea";//������ �迭�� �ʱ� �迭��ҿ� K�� �����ּҰ� ����
//	ptrArray[1] = "Seoul";//������ �迭�� ���� �迭��ҿ� S�� �����ּҰ� ����
//
//	ptrptr = ptrArray;//������ �迭�� �����ּҰ��� ���������Ϳ� �Ҵ�
//	printf("\n ptrArray[0]�� �ּ� (&ptrArray[0])=%u", &ptrArray[0]);//�ʱ� �ּ�
//	printf("\n ptrArray[0]�� �� (ptrArray[0]=%u	", ptrArray[0]);//�ʱ� �ּ� ��
//	printf("\n ptrArray[0]�� ������ (*ptrArray[0])=%c", *ptrArray[0]);//���� ���ڰ�
//	printf("\n ptrArray[0]�� ���� ���ڿ� (*ptrArray[0])=%s\n", *ptrArray);//���� ���ڿ��� ���� �޸� �ּҷ� Ÿ�� ���� ���๮�ڸ� ������ ������ ��� ���
//
//	printf("\n ptrArray[1]�� �ּ� (&ptrArray[1]=%u)", &ptrArray[1]);//���� �ּҰ� �ʱ� �ּҰ��� ������ �ٸ���.
//	printf("\n ptrArray[1]�� �� (ptrArray[1]=%u", ptrArray[1]);//���� �ּҰ� ����Ű�� �� �ּ�
//	printf("\n ptrArray[1]�� ������ (*ptrArray[1])=%c", *ptrArray[1]);//���� �迭����� ù��° ��
//	printf("\n ptrArray[1]�� ���� ���ڿ� (*ptrArray[1])=%s\n", *(ptrArray + 1));//���� ���ڿ��� ���� ���� ���۸� ��� ���
//
//	printf("\n ptrptr�� �ּ� (&ptrptr) = %u", &ptrptr);//������������ �ּ�
//	printf("\n ptrtpr�� �� (ptrptr)=%u", ptrptr);//������������ �ּҿ� ������ �迭�� �ּҴ� ���� ����.
//	printf("\n ptrptr�� 1�� ������ (*ptrptr)=%u", *ptrptr);//1�� ���� ���� ������ �迭�� ù���� �迭��� ��.
//	printf("\n ptrptr�� 2�� ������ (**ptrptr)=%u", **ptrptr);//2�� �������� ����Ű�� ������ �ƽ�Ű�ڵ� ��.
//	printf("\n ptrptr�� 2�� ���� ���ڿ� (**ptrptr)=%s", *ptrptr);//���� ���ڿ� ��� ���
//	
//	printf("\n\n *ptrArray[0]: ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(ptrArray[0] + i));//���۴����� ��� ��� �迭����� ���� �������� �ɰ��� ���
//	}
//	printf("\n **ptrptr : ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(*ptrptr + i));//�� ���۴����� ��� ���(1�� ������ �ּҰ�)
//	}
//	printf("\n\n *ptrArray[1] : ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(ptrArray[1] + i));//�� ���۴����� ��� ������
//	}
//	printf("\n **(ptrptr1) : ");
//	for (i = 0; i < 5; i++) {
//		printf("%c", *(*(ptrptr + 1) + i));//���� ���� ������
//	}
//	return 0;
//}
////�迭�� ������ ���������̴�. �׷��� ���� ������ ���ᵵ �ִ�. �̰� �׸����� ����ȭ�ؼ� �߰��ؾ� �Ѵ�.
