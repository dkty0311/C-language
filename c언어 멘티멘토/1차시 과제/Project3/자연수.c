#include <stdio.h>
int main()
{
	int a, b,x,y,z,r;

		printf("�� ���� �Է��Ͻÿ�");
		scanf_s("%d %d", &a, &b);
		
		while (a<=b)
		{
			printf("%d ",a);
			a++;
		}
		printf("\n");

		printf("�� ���� �Է��Ͻÿ�");
		scanf_s("%d %d", &x, &y);
		do {
			printf("%d ",x);
			x++;
		} while (x <= y);

		printf("�� ���� �Է��Ͻÿ�");
		scanf_s("%d %d", &z, &r);
		printf("\n");

		for (z; z <= r; z++)
		{
			printf("%d ", z);
		}

}