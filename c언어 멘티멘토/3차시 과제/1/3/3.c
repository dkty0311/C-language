#include <stdio.h>

int main()
{
	int* numPtr=NULL;      
	int num1[100] = { 0 };
	static int i = 0;

	for (i=0; i < 100; i++)
	{
		numPtr = &num1[i];
		printf("ют╥б>> ");
		scanf_s("%d", numPtr + i);

		if (*(numPtr + i) == 0)
		{
			for (int x = 0; x < i; x++)
				printf("%d", *(numPtr+x));
				break;
		}
	}
}