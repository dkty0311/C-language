#include <stdio.h>
#include<stdlib.h>
int main()
{
	int x, y,c;

	printf("행과 열 입력");
	scanf_s("%d %d",&x,&y);

	for (int i=0; i<x; i++)
	{
		for (int a=0; a < y; a++)
		{
			c = rand() % 5;
			printf("%d ", c);
		}
		printf("\n");
	}
	
}