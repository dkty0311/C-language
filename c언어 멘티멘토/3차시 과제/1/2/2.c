#include <stdio.h>

int main()
{
	char a[5] = { 0 };
	char* c = NULL;



	for (int i = 0; i < 5; i++)
	{
		c = &a[i];
		printf("ют╥б>> ");
		scanf_s(" %c", c);
	}

	for (int j = 0; j < 5; j++)
	{
		c = &a[j];
		if(j==0||j==2||j==4)
			printf("%c", *c);
	}
}

