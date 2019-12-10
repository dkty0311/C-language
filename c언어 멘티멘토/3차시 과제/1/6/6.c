#include <stdio.h>

int main()
{
	double* p = NULL;
	double a[6] = { 0 };
	double sum = 0;

	p = &a;

	for (int i = 0; i < 6; i++)
	{
		printf("ÀÔ·Â >>");
		scanf_s("%lf",p+i);
	}

	for (int i = 0; i < 6; i++)
	{
		sum += *(p + i);
	}

	printf("Æò±Õ %lf", sum/6);
}