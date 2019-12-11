#include "accomodation.h"
#include <stdio.h>


void accomodation_cancel(int seats[SIZE][SIZE])
{
	int i, c, row_seats_number, col_seats_number;


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
	if (seats[row_seats_number - 1][col_seats_number - 1] == 1)   //행과 열이 예약되어 있으면 취소
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 0;
		printf("예약이 취소되었습니다.\n");
	}
	else                                                 //아니면 취소할 좌석이 없으면 출력
		printf("예약되지 않은 좌석입니다.\n");
}