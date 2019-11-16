#include <stdio.h>
void isEqual(int x, int y);
int main()
{
	int x, y;
	printf("두 수 입력");
	scanf_s("%d %d", &x, &y);
	
	(x = y) ? printf("equal\n") : printf("unequal\n");
	
	isEqual(x,y);
	
	if (x = y)
	{
		printf("equal");
	}
	else
		printf("unequal");
}

void isEqual(int x,int y)
{
	if (x = y)
	{
		printf("equal");
	}
	else
		printf("unequal");
}