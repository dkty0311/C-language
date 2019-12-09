#include <stdio.h>

int main()
{
	char a[3][50] = { 0 };

	for (int i = 0; i < 3; i++)
	{

		printf("문장 입력");
		fgets(a[i],50, stdin);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s",a[i]);
	}

	
}