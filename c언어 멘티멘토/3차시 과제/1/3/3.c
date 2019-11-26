#include <stdio.h>

int main()
{
	int a[100] = { 0 };
	int* c = NULL;



	for (int i = 0; i < 100; i++)
	{
		c = &a[i];
		printf("ют╥б>> ");
		scanf_s("%d", c);
	}

	for (int j = 0; j < 100; j++)
	{
		c = &a[j];
		if (*c == 0)
		{
			for (int b = 100; b < 0; b++)
			{
				c = &a[b];
				printf("%d ", *c);
			}
			
		}

	}
}