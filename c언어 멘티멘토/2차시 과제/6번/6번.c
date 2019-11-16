#include <stdio.h>

int main()
{
	double a[6] = { 0 };
	double average,sum=0;

	for (int i = 0; i < 6; i++)
	{
		printf("ют╥б>>");
		scanf_s("%lf", &a[i]);
	}

	for (int b = 0; b < 6; b++)
	{
		sum += a[b];
	}

	average = sum / 6;

	printf("%lf", average);
}


