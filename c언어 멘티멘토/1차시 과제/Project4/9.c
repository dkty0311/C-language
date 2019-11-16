#include <stdio.h>
int main()
{
	int x,sum=0;
	printf("정수를 입력하시오");
	scanf_s("%d", &x);

	for (int i = 1; i <= x; i++)
	{
		sum += i;
	}
	printf("%d", sum);
}