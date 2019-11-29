#include <stdio.h>

int main()
{
	int b[3][3] = { 0 };


	for(int i=0; i<3; i++)
		for (int a = 0; a < 3; a++)
		{
			b[i][a] = 1;
		}

	for (int i = 0; i < 3; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			printf("%d ", b[i][a]);
		}
		printf("\n");
	}
}