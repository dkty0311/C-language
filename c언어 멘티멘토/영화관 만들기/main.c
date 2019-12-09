#include <stdio.h>
#include <string.h>
#include "register.h"
#include "accomodation.h"
#include "show_choice_meny.h"

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












