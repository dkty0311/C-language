#include <stdio.h>

int main()
{
	int score[3][3] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		printf("ÇÐ»ý %d>> ", i + 1);
		for (int a = 0; a < 3; a++)
		{
			scanf_s("%d", &score[i][a]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int a = 0; a < 3; a++)
		{
			sum += score[i][a];
			
		}
		printf("ÇÐ»ý %dÀÇ ÃÑÁ¡: %d / ÇÐ»ý %dÀÇ Æò±Õ: %lf\n", i + 1, sum, i + 1, (double)sum/3);
	}

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int a = 0; a < 3; a++)
		{
			sum += score[a][i];

		}
		printf("°ú¸ñ %dÀÇ ÃÑÁ¡: %d / °ú¸ñ %dÀÇ Æò±Õ: %lf\n", i + 1, sum, i + 1, (double)sum / 3);
	}


}