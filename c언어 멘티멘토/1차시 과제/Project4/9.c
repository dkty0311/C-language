#include <stdio.h>
int main()
{
	int x,sum=0;
	printf("������ �Է��Ͻÿ�");
	scanf_s("%d", &x);

	for (int i = 1; i <= x; i++)
	{
		sum += i;
	}
	printf("%d", sum);
}