#include <stdio.h>
#include <string.h>
#include "register.h"
#include "accomodation.h"

int choice_menu();
void start_menu();
void end_menu();

int main()
{
	int choice;
	int seats[SIZE][SIZE] = { 0 };

	login_or_register();


	while (1)
	{
		choice = choice_menu();
		int choice_menu();

		if (choice == 1)
		{
			accomodation(seats);
		}
		else if (choice == 2)
		{
			accomodation_cancel(seats);
		}
		else if (choice == 3)
			break;
	}
}


int choice_menu()
{
	int a;
	printf("1.예약\n2.취소\n3.종료\n");
	printf("메뉴를 선택하시오 : ");
	scanf_s("%d", &a);
	return a;
}





void start_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("■");

	printf("\n■■   ");

	for (int a = 1; a <= SIZE; a++)
		printf("%d ", a);

	printf("■■\n");

}

void end_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("■");
	printf("\n");

}




