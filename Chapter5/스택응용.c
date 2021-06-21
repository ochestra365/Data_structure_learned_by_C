#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100
int testPair(char* exp) {
	char symbol, open_pair;
	//char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol)
		{
			//(1) ���� ��ȣ�� ���ÿ� ����
		case '(':
		case '[':
		case '{':
			push(symbol); break;
			//(2)���� �� ��ȣ�� ������
		case ')':
		case ']':
		case '}':
			if (top == NULL)return 0;
			else {
				//(2)-1 ���ÿ��� ���������� ���� ��ȣ�� ����
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					//(2)-3 ��ȣ ���� Ʋ���� ���� ����
					return 0
					//(2)-4 ��ȣ ���� ������ ���� symbol �˻縦 �����
				else break;
			}
		}
	}
	if (top == NULL)return 1;//���� �˻縦 ��ģ �� ������ �����̸� 1��ȯ
	else return 0;//������ �ƴϸ� 0�� ��ȯ(���İ�ȣ Ʋ��)
}

void main(void) {
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);

	if (testPair(express) == 1)
		printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�.");
	else
		printf("\n\n ������ ��ȣ�� Ʋ�Ƚ��ϴ�.");

	getchar();
}