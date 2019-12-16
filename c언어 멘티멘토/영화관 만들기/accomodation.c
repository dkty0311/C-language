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
	
	

	printf("�ءءء�%s�ءءء�ȸ������ ������ �¼�\n", list[login_inform].userid);
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			if (list[login_inform].seats[r][c] ==1)
			{
				printf("��:%d ��:%d ", r+1, c+1);
			}
		}
	}
	printf("\n");
	start_menu();


	for (i = 0; i < SIZE; i++)
	{
		printf("���");
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
		printf("  ���\n");
	}
	end_menu();


	

	while (1)
	{
		int num = 0,num1=0;
		printf("������ �¼��� ���� �Է����ּ���.");
		num=scanf_s("%d", &row_seats_number);
		printf("������ �¼��� ���� �Է����ּ���");
		num1 = scanf_s("%d", &col_seats_number);

		while (getchar() != '\n');

		if (num == 1||num1==1)
		{
			break;

		}

	}

	if (row_seats_number < 0 || row_seats_number>10 || col_seats_number < 0 || col_seats_number>10)
	{
		printf("�˸��� �¼� ������ �Է����ּ���\n");
	}
	else if (seats[row_seats_number-1][col_seats_number-1] == 0)
	{
		seats[row_seats_number-1][col_seats_number-1] = 1;

		printf("����Ǿ����ϴ�.\n");
		list[login_inform].seats[row_seats_number-1][col_seats_number-1] = 1;
			
			fp = fopen("data2.bin", "wb");
			fwrite(list, sizeof(struct information), INFORM, fp);
			fclose(fp);
			
			form = fopen("data1.bin", "wb");

			fwrite(seats, sizeof(seats[SIZE][SIZE]), 100, form);
			fclose(form);
	}
	else if(seats[row_seats_number - 1][col_seats_number - 1] == 1)
	{
		printf("�̹� ����� �¼��Դϴ�.\n");
	}
		
}
