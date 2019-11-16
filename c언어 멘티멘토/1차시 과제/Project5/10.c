#include <stdio.h>
int main()
{
	int x;

	do
	{
		printf("각 나라의 수도: \n 1 korea:seoul\n2 USA: Washington\n3 Japan: Tokyo\n4 China: Beijing\n");
		scanf_s("%d", &x);

		if (x == 1)
		{
			printf("seoul\n");
			continue;
		}
		else if (x == 2)
		{
			printf("washington\n");
			continue;
		}
		else if(x==3)
		{
			printf("Tokyo\n");
			continue;
		}
		else if (x == 4)
		{
			printf("beiging\n");
			continue;
		}
		else
		{
			printf("none");
			break;
		}
	} while (1);
}