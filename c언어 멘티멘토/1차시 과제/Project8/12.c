#include <stdio.h>
int main()
{
	int x,y,z,least;

	printf("세 개의 정수 입력");
	scanf_s("%d %d %d", &x, &y, &z);

	least = x;

	if (least > y)
	{
		least = y;
	}
	
	if (least > z)
	{
		least = z;
	}

	
	


	printf("%d", least);
}