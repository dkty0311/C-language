#include <stdio.h>
int main()
{
	int x, y;
	double sum = 0;
	char a;

	while (1)
	{
		printf("밑변 입력");
		scanf_s("%d", &x);

		printf("높이 입력");
		scanf_s("%d", &y);

		sum = ((double)x * (double)y) / 2;
		printf("삼각형의 넓이:%lf\n", sum);

		printf("continue?");
		scanf_s(" %c", &a);

		if (a == 'y')
		{
			continue;
		}
		else if (a == 'n')
		{
			break;
		}

	}
}