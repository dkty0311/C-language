#include <stdio.h>
#include "accomodation.h"
#include "register.h"

void accomodation_cancel(int seats[SIZE][SIZE], int login_inform)
{
	int i, c, row_seats_number, col_seats_number;

	struct information list[5] = { 0 };


	FILE* fp = fopen("data2.bin", "rb");                                               //공통 예약/비예약 좌석 읽어오기
	FILE* form = fopen("data1.bin", "rb");
	fread(seats, sizeof(seats[SIZE][SIZE]), 100, form);
	fread(list, sizeof(struct information), INFORM, fp);

	printf("※※※※%s※※※※회원님이 예약한 좌석\n",list[login_inform].userid);
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			if (list[login_inform].seats[r][c] == 1)
			{
				printf("%d %d ", r + 1, c +1);


			}
		}
	}
	printf("\n");

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



	while (1)
	{
		int num = 0, num1 = 0;
		printf("취소할 좌석의 행을 입력해주세요");
		num = scanf_s("%d", &row_seats_number);
		printf("취소할 좌석의 열을입력해주세요");
		num1 = scanf_s("%d", &col_seats_number);

		while (getchar() != '\n');

		if (num == 1||num1==1)
		{
			break;

		}

	}

	if (row_seats_number < 0 || row_seats_number>10 || col_seats_number < 0 || col_seats_number>10)
	{
		printf("알맞은 좌석 정보를 입력해주세요\n");
	}
	else if (list[login_inform].seats[row_seats_number - 1][col_seats_number - 1] == 1 && seats[row_seats_number - 1][col_seats_number - 1] == 1)   //행과 열이 예약되어 있으면 취소
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 0;
		list[login_inform].seats[row_seats_number - 1][col_seats_number - 1] = 0;
		printf("예약이 취소되었습니다.\n");
		fp = fopen("data2.bin", "wb");
		fwrite(list, sizeof(struct information), INFORM, fp);
		fclose(fp);

		form = fopen("data1.bin", "wb");
		fwrite(seats, sizeof(seats[SIZE][SIZE]), 100, form);
		fclose(form);

	}
	else if (seats[row_seats_number - 1][col_seats_number - 1] == 0)                                                //아니면 취소할 좌석이 없으면 출력
		printf("예약된 좌석이 아닙니다.\n");
	else
		printf("회원님이 예약한 좌석이 아닙니다.\n");

}