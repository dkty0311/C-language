#include "accomodation.h"
#include "register.h"
#include <stdio.h>

extern int rep_check;


void accomodation(int seats[SIZE][SIZE])
{
	int i, c, row_seats_number, col_seats_number;

	struct information list[INFORM] = { 0 };


	FILE* fp = fopen("data2.bin", "rb");

	start_menu();


	for (i = 0; i < SIZE; i++)
	{
		printf("■■");
		if (i >= 9)
			printf("%d", i + 1);
		else
			printf(" %d", i + 1);

		for (c = 0; c < SIZE; c++)
		{
			if (c >= 10)
				printf("  %d", seats[i][c]);
			else
				printf(" %d", seats[i][c]);

		}
		printf("  ■■\n");
	}
	end_menu();


	printf("원하는 좌석의 행과 열을 입력해주세요.");
	scanf_s("%d %d", &row_seats_number, &col_seats_number);

	if (seats[row_seats_number - 1][col_seats_number - 1] == 0)
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 1;

		printf("예약되었습니다.\n");
		fp = fopen("data2.bin", "wb");
		if (row_seats_number == 0)
		{
			list[].seats
		}
		else
		{
			 list[rep_check].seats = (char)((row_seats_number * 10) + (col_seats_number));
		}

	}
	else
		printf("이미 예약된 좌석입니다.\n");
}
