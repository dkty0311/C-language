#include <stdio.h>
#include "register.h"
#include "accomodation.h"
#include "show_choice_menu.h"


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












