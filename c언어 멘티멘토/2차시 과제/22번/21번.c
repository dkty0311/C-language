#include <stdio.h>

int main()
{
	char a[100] = { 0 };
	char temp;
	int count;


	printf("문자열 입력 >> ");
	fgets(a, 100, stdin);

	for (int b = 0; b < 100; b++)
	{
		if (a[b] == '\0')
		{
			break;
		}
		else
			count++;
	}

	for (int i = 0; i<=count; i++)
	{
		a[i] = temp;
		

	}
}