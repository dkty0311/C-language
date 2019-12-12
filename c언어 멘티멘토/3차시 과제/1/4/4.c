#include <stdio.h>

int main()
{
	int* arr = NULL;
	int ar[5] = { 0 };

	arr = &ar;

	for (int a = 0; a < 5; a++)
	{
		arr = &ar+a;
		printf("ют╥б >> ");
		scanf_s("%d", arr + a);
	}

	int least;

	least = arr;
	for (int a = 0; a < 5; a++)
	{
		arr = &ar+a;
		if (least > * (arr + a))
		{
			least = *(arr + a);
		}
	}
	printf("%d", least);
}