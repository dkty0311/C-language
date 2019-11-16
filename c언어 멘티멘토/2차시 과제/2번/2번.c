#include <stdio.h>

int main()
{
	char c[5] = { 0 };


	for (int i = 0; i < 5; i++)
	{
		printf("ют╥б");
		scanf_s(" %c",&c[i]);
	}

	for (int j = 0; j < 5; j++)
	{
		if (j == 0 || j == 2 || j == 4)
		{
			printf("%c", c[j]);
		}
	}
}