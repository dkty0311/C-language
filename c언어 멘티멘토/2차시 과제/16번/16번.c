#include <stdio.h>

int main()
{
	int num[4][2] = { 0 };
	int sum=0;

	for (int i = 0; i < 4; i++)
	{
		scanf_s("%d %d", &num[i][0], &num[i][1]);
	}


		for (int i = 0; i < 4; i++)
		{
			for (int a = 0; a < 2; a++)
			{
				sum += num[i][a];
			}

			printf("%d ", sum / 2);
			sum = 0;
		}

		sum = 0;
		printf("\n");

		for (int i = 0; i < 2; i++)
		{
			for (int a = 0; a < 4; a++)
			{
				sum += num[i][a];
			}
			printf("%d ", sum / 4);
			sum = 0;
		}

		printf("\n");

		for (int i = 0; i < 2; i++)
		{
			for (int a = 0; a < 4; a++)
			{
				sum += num[i][a];
			}
		}

		printf("%d ", sum / 8);

}