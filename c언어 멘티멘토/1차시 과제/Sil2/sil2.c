#include <stdio.h>

int main()
{
	int inputA, inputB, inputC;
	printf("3과목을 동시에 입력하세요: ");
	scanf_s("%d %d %d", &inputA, &inputB, &inputC);

	printf("과목의 총합은 %d입니다.", inputA + inputB + inputC);
	printf("과목의 평균은 %d입니다.", (inputA + inputB + inputC) / 3);

	return 0;
}