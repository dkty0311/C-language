#include <stdio.h>
void main()
{
	int y;
	printf("연도 입력>>");
	scanf_s("%d", &y);
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		printf("leap year");
	else
		printf("not leap year");
}
