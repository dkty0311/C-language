#include "accomodation.h"
#include "register.h"
#include <stdio.h>


void accomodation(int seats[SIZE][SIZE],int login_inform)
{
	int i, c, row_seats_number, col_seats_number;

	struct information list[5] = { 0 };

	FILE* fp = fopen("data2.bin", "rb");
	FILE* form = fopen("data1.bin", "rb");

	fread(seats, sizeof(seats[SIZE][SIZE]), 100, form);
	fread(list, sizeof(struct information), INFORM, fp);
	
	

	printf("※※※※%s※※※※회원님이 예약한 좌석\n", list[login_inform].userid);
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			if (list[login_inform].seats[r][c] ==1)
			{
				printf("행:%d 열:%d ", r+1, c+1);
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


	printf("예약할 좌석의 행과 열을 입력해주세요.");
	scanf_s("%d %d", &row_seats_number, &col_seats_number);

	if (seats[row_seats_number-1][col_seats_number-1] == 0)
	{
		seats[row_seats_number-1][col_seats_number-1] = 1;

		printf("예약되었습니다.\n");
		
		list[login_inform].seats[row_seats_number-1][col_seats_number-1] = 1;
			
			fp = fopen("data2.bin", "wb");
			fwrite(list, sizeof(struct information), INFORM, fp);
			fclose(fp);
			
			form = fopen("data1.bin", "wb");

			fwrite(seats, sizeof(seats[SIZE][SIZE]), 100, form);
			fclose(form);

	}
	else
		printf("이미 예약된 좌석입니다.\n");
}
