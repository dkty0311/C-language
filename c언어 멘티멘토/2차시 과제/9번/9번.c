#include <stdio.h>
int main()
{
	int a[100] = { 0 };
	int sum = 0, average;

	for (int i = 0; i < 100; i++)
	{
		printf("�Է� >> ");
		scanf_s("%d", &a[i]);

		

			if(a[i] < 0)
			{
				average = sum / i;
				printf("�հ�: %d / ���: %lf", sum, (double)(average));
			}
			else
				sum += a[i];
	}
}