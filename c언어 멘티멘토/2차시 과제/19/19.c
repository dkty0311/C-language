#include <stdio.h>

int main()
{
	char a[100] = { 0 };
	char b[100] = { 0 };
	int sum1 = 0, sum2 = 0;

	printf("문자열 입력 >> ");
	scanf_s("%s", &a[0],100);

	printf("문자열 입력 >> ");
	scanf_s("%s", &b[0],100);

	for (int i = 0; i < 100; i++)
	{
		if (a[i] == 0)
		{
			break;
		}
		else
			sum1 += 1;
	}

	for (int i = 0; i < 100; i++)
	{
		if (b[i] == 0)
		{
			break;
		}
		else
			sum2 += 1;
	}

	printf("%d", (sum1 + sum2));
}