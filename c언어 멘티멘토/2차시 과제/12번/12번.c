#include <stdio.h>
int main()
{
	int a[2][4] = { 0 };
	int b[2][4] = { 0 };
	int d[2][4] = { 0 };

	printf("first array\n");

	for (int i = 0; i < 2; i++)
	{
		scanf_s("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	}

	printf("second array\n");

	for (int i = 0; i < 2; i++)
	{
		scanf_s("%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
	}

	for (int i = 0; i < 2; i++)
		for (int c = 0; c < 4; c++)
		{
			d[i][c] = a[i][c] * b[i][c];
		}

	for (int i = 0; i < 2; i++)
		printf("\n\nresult\n%d %d %d %d\n",d[i][0],d[i][1],d[i][2],d[i][3]);
}