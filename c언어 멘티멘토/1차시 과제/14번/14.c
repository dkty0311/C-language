#include <stdio.h>
int main()
{
	int x, y;
	double sum = 0;
	char a;

	while (1)
	{
		printf("�غ� �Է�");
		scanf_s("%d", &x);

		printf("���� �Է�");
		scanf_s("%d", &y);

		sum = ((double)x * (double)y) / 2;
		printf("�ﰢ���� ����:%lf\n", sum);

		printf("continue?");
		scanf_s(" %c", &a);

		if (a == 'y')
		{
			continue;
		}
		else if (a == 'n')
		{
			break;
		}

	}
}