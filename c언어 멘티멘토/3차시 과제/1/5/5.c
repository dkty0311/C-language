#include <stdio.h>

int main()
{


	int a[5] = { 0 };
	int* p = NULL;
	int least, most;

	p = &a;

	for (int i = 0; i < 5; i++)
	{
		printf("�Է� >>");
		scanf_s("%d", p + i);
	}

	least = *p;

	for (int i = 0; i < 5; i++)
	{
		if (least > * (p + i))
		{
			least = *(p + i);
		}
	}

	most = *p;

	for (int i = 0; i < 5; i++)
	{
		if (most < * (p + i))
		{
			most = *(p + i);
		}
	}

	printf("�ִ� %d �ּڰ� %d", most, least);
}