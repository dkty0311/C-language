#include <stdio.h>
#include "register.h"
#include "accomodation.h"
#include "show_choice_menu.h"



int main()
{
	int choice;

	login_or_register();
	int seats[SIZE][SIZE] = { 0 };

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












