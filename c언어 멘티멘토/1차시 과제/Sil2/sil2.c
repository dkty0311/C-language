#include <stdio.h>

int main()
{
	int inputA, inputB, inputC;
	printf("3������ ���ÿ� �Է��ϼ���: ");
	scanf_s("%d %d %d", &inputA, &inputB, &inputC);

	printf("������ ������ %d�Դϴ�.", inputA + inputB + inputC);
	printf("������ ����� %d�Դϴ�.", (inputA + inputB + inputC) / 3);

	return 0;
}