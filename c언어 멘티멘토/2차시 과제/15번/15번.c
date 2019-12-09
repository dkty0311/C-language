#include <stdio.h>

int main()
{
	int a[5][5] = { {1,1,1,1,1},{0} };


	for(int i=1; i<5; i++)
		for (int b = 0; b < 5; b++)
		{
			if (b == 0)
			{
				a[i][0] = 1;
			 }
			else
			{
				a[i][b] = a[i - 1][b] + a[i][b - 1];
			}

		}

	for (int i = 0; i < 5; i++)
	{
		for (int b = 0; b < 5; b++)
		{
			printf("%d ", a[i][b]);
		}
		printf("\n");
	}
}