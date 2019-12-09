#include <stdio.h>

int main()
{
	char a[100] = { 0 };
	int count = 0;

	printf("문자열 입력");
	fgets(a,100 , stdin);

	for (int i = 0; i<100; i++)
	{
		if (a[i] == ' ')
			count++;
		else
			continue;
	}

	printf("%d", count);
}