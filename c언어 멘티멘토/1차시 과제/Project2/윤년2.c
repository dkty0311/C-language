#include <stdio.h>
void main()
{
	int y,m;
	printf("연도와 달 입력");
	scanf_s("%d %d", &y,&m);
	
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		switch (m)
		{
		case 1:
			printf("30");
			break;
		case 2:
			printf("29");
			break;
		case 3:
			printf("29");
			break;
		case 4:
			printf("29");
			break;
		case 5:
			printf("29");
			break;
		case 6:
			printf("29");
			break;
		case 7:
			printf("29");
			break;
		case 8:
			printf("29");
			break;
		case 9:
			printf("29");
			break;
		case 10:
			printf("29");
			break;
		case 11:
			printf("29");
			break;
		case 12:
			printf("31");
			break;
		}
	else
		switch (m)
		{
		case 1:
			printf("30");
			break;
		case 2:
			printf("30");
			break;
		case 3:
			printf("29");
			break;
		case 4:
			printf("29");
			break;
		case 5:
			printf("29");
			break;
		case 6:
			printf("29");
			break;
		case 7:
			printf("29");
			break;
		case 8:
			printf("29");
			break;
		case 9:
			printf("29");
			break;
		case 10:
			printf("29");
			break;
		case 11:
			printf("29");
			break;
		case 12:
			printf("31");
			break;
		}

}