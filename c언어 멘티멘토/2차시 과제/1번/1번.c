#include <stdio.h>

int main()
{
	char c[5] = { 0 };


	for (int i = 0; i < 5; i++)
	{
		printf("�Է�");
		scanf_s(" %c", &c[i]);
	}

	for (int j = 0; j < 5; j++)
	{
		printf("%c", c[j]);
	}
}