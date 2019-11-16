#include <stdio.h>
int main()
{
	int a, b,x,y,z,r;

		printf("두 수를 입력하시오");
		scanf_s("%d %d", &a, &b);
		
		while (a<=b)
		{
			printf("%d ",a);
			a++;
		}
		printf("\n");

		printf("두 수를 입력하시오");
		scanf_s("%d %d", &x, &y);
		do {
			printf("%d ",x);
			x++;
		} while (x <= y);

		printf("두 수를 입력하시오");
		scanf_s("%d %d", &z, &r);
		printf("\n");

		for (z; z <= r; z++)
		{
			printf("%d ", z);
		}

}