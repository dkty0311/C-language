#include <stdio.h>

int main()
{
	int a[100] = { 0 };
	for (int i = 0; i<100; i++)
	{
		printf("ют╥б");
		scanf_s("%d", &a[i]);

		if (a[i] == 0)
		{
			for (int b = i; b < 0; b++)
				printf("%d ", a[b]);
		}
		
	}
}