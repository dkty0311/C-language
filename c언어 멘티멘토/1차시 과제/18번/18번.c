#include <Stdio.h.>
int main()
{
	int x;
	printf("���� �Է�");
	scanf_s("%d", &x);

	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		
		}
		printf("\n");
	}
}