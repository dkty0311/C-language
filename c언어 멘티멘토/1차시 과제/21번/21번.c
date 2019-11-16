#include <stdio.h>
#define num 32

int main(void)
{
	int c[num], i = 0, j, n;

	printf("십진 정수 입력 >> ");
	scanf_s("%d", &n);

	if (n == 0)
	{
		printf("0");
		return 0;
	}
	
	while (n > 0)
	{
		c[i] = n % 2;

		n = n / 2;
		i++;
	}

	for (j = i-1; j >= 0; j--)
		printf("%d", c[j]);

	return 0;
}