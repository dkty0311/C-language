#include <stdio.h>
int main()
{
	int x, y,temp;
	printf("�� �� �Է�>> ");
	scanf_s("%d %d", &x, &y);

	temp = x;
	x = y;
	y = temp;

	printf("%d %d", x, y);
}