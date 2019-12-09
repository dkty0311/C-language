#include <stdio.h>
int main()
{
	int score[5][4] = { 0 };
	int average[5] = { 0 };


	for (int i = 0; i < 5; i++)
	{
		printf("ÇÐ»ý %d >>", i + 1);
		scanf_s("%d %d %d %d", &score[i][0], &score[i][1], &score[i][2], &score[i][3]);
	}

	for (int a = 0; a < 5; a++)
	{
		int sum=0;
		for (int b = 0; b < 4; b++)
		{
			sum += score[a][b];
		}

		average[a] = sum / 4;
	}

	for (int c = 0; c < 5; c++)
	{
		if (average[c] >= 80)
		{
			printf("pass\n");
		}
		else
			printf("fail\n");
	}

}
