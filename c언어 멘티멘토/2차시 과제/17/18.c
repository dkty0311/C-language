#include <stdio.h>

int main()
{
	char a[100] = { 0 };
	int num;

	printf("���ڿ� �Է� >> ");
	scanf_s(" %c", &a[100]);

	printf("���� �Է� >> ");
	scanf_s("%d", &num);

	for (int i = 100; i<0;  i--)
	{
		if (a[i][i] == 0)
		{
			continue;
		}
		else
			printf("%c", a[0][i]);

	}


}