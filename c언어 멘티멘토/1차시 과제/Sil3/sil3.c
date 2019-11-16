#include <stdio.h>

int main()
{
	int x, y,area;

	printf("두 수 입력");
	scanf_s("%d %d", &x, &y);

	x = x + 5;
	y = y * 2;
	printf("width=%d", x);
	printf("length=%d\n",y);
	area = x * y;
	printf("%d", area);
	return 0;
}