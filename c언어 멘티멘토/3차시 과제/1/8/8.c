#include <stdio.h>

int main()
{
	char a[3] = { 0 };
	char b[50] = { 0 };
	char* p = &a;
	char** q = &p;



	for (int i = 0; i < 3; i++)
	{
		printf("문장입력");
		fgets((p + i), 50, stdin);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s",p+i);
	}

}