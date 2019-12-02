#include <stdio.h>
#include <string.h>
#include "struct.h"
#define SIZE 10
#define INFORM 5
int choice_menu();
void accomodation(int seats[SIZE][SIZE]);
void accomodation_cancel(int seats[SIZE][SIZE]);
void start_menu();
void end_menu();
int login_or_register();

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
	printf("1.����\n2.���\n3.����\n");
	printf("�޴��� �����Ͻÿ� : ");
	scanf_s("%d", &a);
	return a;
}


void accomodation(int seats[SIZE][SIZE])
{
	int i, c, row_seats_number, col_seats_number;

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


	printf("���ϴ� �¼��� ��� ���� �Է����ּ���.");
	scanf_s("%d %d", &row_seats_number, &col_seats_number);
	if (seats[row_seats_number - 1][col_seats_number - 1] == 0)
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 1;
		printf("����Ǿ����ϴ�.\n");
	}
	else
		printf("�̹� ����� �¼��Դϴ�.\n");
}

void accomodation_cancel(int seats[SIZE][SIZE])
{
	int i, c, row_seats_number, col_seats_number;

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


	printf("���ϴ� �¼��� ��� ���� �Է����ּ���.");
	scanf_s("%d %d", &row_seats_number, &col_seats_number);
	if (seats[row_seats_number - 1][col_seats_number - 1] == 1)
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 0;
		printf("������ ��ҵǾ����ϴ�.\n");
	}
	else
		printf("������� ���� �¼��Դϴ�.\n");
}

void start_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("��");

	printf("\n���   ");

	for (int a = 1; a <= SIZE; a++)
		printf("%d ", a);

	printf("���\n");

}

void end_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("��");
	printf("\n");

}


int login_or_register()
{
	char user_information[INFORM][2][10] = { 0 };       // ID, PW�迭 ����(�ִ� ���ڼ�:9����)
	int  user_max = 0, rep_check = 0;                   // user_max:���� ȸ������, rep_check:�ߺ�üũ ���
	char userid[10], userpw[10];


	while (1)
	{
		int option;
		int rep_number = 1;
		printf("���������\n��1. ȸ������ ��\n��2. �� �� �� ��\n��3. ����     ��\n���������\n");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			if (user_max == INFORM)          // ȸ���� �ʰ��� (ȸ����=5)
			{
				printf("ȸ���� �ʹ� �����ϴ�.\n");
				break;
			}
			printf("������ ID�� �Է��ϼ��� <�ִ� 9��> :");
			scanf_s("%s", user_information[user_max][0], 10);

			for (rep_check = 0; rep_check < user_max; rep_check++)
			{
				if (strcmp(user_information[user_max][0], user_information[rep_check][0]) == 0)
				{
					printf("�̹� ������ ID�Դϴ�.\n\n");
					rep_number = 0;
					break;
				}
			}
			
			if (rep_number == 0)
			{
				user_information[user_max][0] == 0;                  //�ߺ��� �ش�迭�� ����� id���� ����
				break;
			}

			printf("������ PW�� �Է��ϼ��� <�ִ� 9��> :");
			scanf_s("%s", user_information[user_max][1], 10);
			printf("������ �����մϴ�!!\n");
			user_max++;
			break;

		case 2:
			printf("ID�� �Է��ϼ��� :");
      		scanf_s("%s", userid, 10);

			for (rep_check = 0; rep_check <= user_max; rep_check++)
				{
					if (strcmp(userid, user_information[rep_check][0]) == 1)
					{
						printf("���� ���̵��Դϴ� �ٽ��Է����ּ���\n\n"); //�����ؾ��Һκ�
					}
				}



			printf("PW�� �Է��ϼ��� :");
			scanf_s("%s", userpw, 10);

			for (rep_check = 0; rep_check < user_max; rep_check++) 
			{
				if (strcmp(user_information[rep_check][0], userid) == 0 && strcmp(user_information[rep_check][1], userpw) == 0)            //�ش�迭�� ���̵�� ����̰����� �α���
				{
					printf("�α��� ����!\n\n");
					return 0;
				}
			}
			if (rep_check == user_max) printf("�ٽ� �α������ּ���!\n\n");
			break;

		case 3:
			exit();
		}
	}
}


