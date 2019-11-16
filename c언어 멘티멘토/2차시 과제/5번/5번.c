#include <stdio.h>

int main()
{
	int a[5] = { 0 };
	int least,max;

	for (int i = 0; i < 5; i++)
	{
		printf("ÀÔ·Â >> ");
		scanf_s("%d", &a[i]);
	}

	least = a[0];

	for (int b = 0; b < 5; b++)
	{
		if (a[b] < least)
			least = a[b];
	}

	max = a[0];

	for (int b = 0; b < 5; b++)
	{
		if (a[b] > max)
			max = a[b];
	}

	printf("ÃÖ¼Ú°ª=%d ÃÖ´ñ°ª%d",least,max);
}