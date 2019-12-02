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
	printf("1.예약\n2.취소\n3.종료\n");
	printf("메뉴를 선택하시오 : ");
	scanf_s("%d", &a);
	return a;
}


void accomodation(int seats[SIZE][SIZE])
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
	if (seats[row_seats_number - 1][col_seats_number - 1] == 0)
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 1;
		printf("예약되었습니다.\n");
	}
	else
		printf("이미 예약된 좌석입니다.\n");
}

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
	if (seats[row_seats_number - 1][col_seats_number - 1] == 1)
	{
		seats[row_seats_number - 1][col_seats_number - 1] = 0;
		printf("예약이 취소되었습니다.\n");
	}
	else
		printf("예약되지 않은 좌석입니다.\n");
}

void start_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("■");

	printf("\n■■   ");

	for (int a = 1; a <= SIZE; a++)
		printf("%d ", a);

	printf("■■\n");

}

void end_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("■");
	printf("\n");

}


int login_or_register()
{
	char user_information[INFORM][2][10] = { 0 };       // ID, PW배열 선언(최대 글자수:9이하)
	int  user_max = 0, rep_check = 0;                   // user_max:현재 회원숫자, rep_check:중복체크 상수
	char userid[10], userpw[10];


	while (1)
	{
		int option;
		int rep_number = 1;
		printf("■■■■■■■■\n■1. 회원가입 ■\n■2. 로 그 인 ■\n■3. 종료     ■\n■■■■■■■■\n");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			if (user_max == INFORM)          // 회원수 초과시 (회원수=5)
			{
				printf("회원이 너무 많습니다.\n");
				break;
			}
			printf("생성할 ID를 입력하세요 <최대 9자> :");
			scanf_s("%s", user_information[user_max][0], 10);

			for (rep_check = 0; rep_check < user_max; rep_check++)
			{
				if (strcmp(user_information[user_max][0], user_information[rep_check][0]) == 0)
				{
					printf("이미 생성된 ID입니다.\n\n");
					rep_number = 0;
					break;
				}
			}
			
			if (rep_number == 0)
			{
				user_information[user_max][0] == 0;                  //중복시 해당배열에 저장된 id정보 삭제
				break;
			}

			printf("생성할 PW를 입력하세요 <최대 9자> :");
			scanf_s("%s", user_information[user_max][1], 10);
			printf("가입을 축하합니다!!\n");
			user_max++;
			break;

		case 2:
			printf("ID를 입력하세요 :");
      		scanf_s("%s", userid, 10);

			for (rep_check = 0; rep_check <= user_max; rep_check++)
				{
					if (strcmp(userid, user_information[rep_check][0]) == 1)
					{
						printf("없는 아이디입니다 다시입력해주세요\n\n"); //수정해야할부분
					}
				}



			printf("PW를 입력하세요 :");
			scanf_s("%s", userpw, 10);

			for (rep_check = 0; rep_check < user_max; rep_check++) 
			{
				if (strcmp(user_information[rep_check][0], userid) == 0 && strcmp(user_information[rep_check][1], userpw) == 0)            //해당배열의 아이디와 비번이같으면 로그인
				{
					printf("로그인 성공!\n\n");
					return 0;
				}
			}
			if (rep_check == user_max) printf("다시 로그인해주세요!\n\n");
			break;

		case 3:
			exit();
		}
	}
}


