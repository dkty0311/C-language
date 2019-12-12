#include <stdio.h>

int main()
{
	char a[6] = { 'H','E','L','L','O','W' };
	char* p = NULL;
	char c;
	char find=0;

	p = &a;

	printf("ют╥б >>");
	scanf_s(" %c", &c);

	for (int i = 0; i < 6; i++)
	{
		if (c == *(p + i))
		{
			find = i + 1;
		}
	}

	if (find == 0)
		printf("none");
	else
		printf("%d",find);



}