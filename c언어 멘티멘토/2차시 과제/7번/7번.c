#include <stdio.h>

int main()
{
	char c[5] = {'h','e','l','o','w' };
	char x;
	int d=0;


	printf("ют╥б >>");
	scanf_s(" %c", &x);

	for (int i = 0; i < 5; i++)
	{
		if (c[i] == x)
		{
			d = i;
		}
	}

	if (d == 0)
	{
		printf("none");
	}
	else
		printf("%d", d);
}