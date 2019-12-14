#include <stdio.h>
#include "register.h"
#include "accomodation.h"
#include "show_choice_menu.h"



int main()
{
	int choice;
	int rep_check_l;

	rep_check_l = login_or_register();

	int seats[SIZE][SIZE] = { 0 };

	while (1)
	{
		choice = choice_menu();

		if (choice == 1)
		{
			accomodation(seats,rep_check_l);
		}
		else if (choice == 2)
		{
			accomodation_cancel(seats, rep_check_l);
		}
		else if (choice == 3)
			break;
	}
}












