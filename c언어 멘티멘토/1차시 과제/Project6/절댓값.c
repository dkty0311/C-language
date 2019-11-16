#include <stdio.h>

int main()
{
	int x, y,sum;

	printf("두 수 입력");
	scanf_s("%d %d", &x, &y);

	sum = x - y;
	
	if (sum < 0)
	{
		sum = -sum;
		printf("%d", sum);
	}
	else
		printf("%d", sum);
}