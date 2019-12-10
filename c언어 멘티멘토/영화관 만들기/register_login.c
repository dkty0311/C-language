#include <stdio.h>
#include <string.h>
#include "register.h"
#include "accomodation.h"
#include "show_choice_menu.h"

int login_or_register()
{

	int  user_max = 0, rep_check = 0;                   // user_max:현재 회원숫자, rep_check:중복체크 상수
	char userid[10], userpw[10];

	struct information
	{
		char userid[15];
		char userpw[15];
		int age;
		char name[30];

	};

	struct information list[INFORM];

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
			scanf_s("%s", list[user_max].userid,10);

			for (rep_check = 0; rep_check < user_max; rep_check++)
			{
				if (strcmp(list[user_max].userid, list[rep_check].userid) == 0)
				{
					printf("이미 생성된 ID입니다.\n\n");
					rep_number = 0;
					break;
				}
			}

			if (rep_number == 0)
			{
//중복시 해당배열에 저장된 id정보 삭제
				break;
			}

			printf("생성할 PW를 입력하세요 <최대 9자> :");
			scanf_s("%s", list[user_max].userpw,10);
			printf("가입을 축하합니다!!\n");
			user_max++;
			break;

		case 2:
			while (1)
			{
				printf("ID를 입력하세요 :");
				scanf_s("%s", userid, 10);

				for (rep_check = 0; rep_check <= user_max; rep_check++)
				{

					if (strcmp(userid, list[rep_check].userid) == 1)
					{
						printf("없는 아이디입니다\n");
						continue;
					}
					else
						break;
				}
				break;
			}
			
			while (1)
			{

				printf("PW를 입력하세요 :");
				scanf_s("%s", userpw, 10);

				for (rep_check = 0; rep_check < user_max; rep_check++)
				{
					if (strcmp(list[rep_check].userid, userid) == 0 && strcmp(list[rep_check].userpw, userpw) == 0)            //해당배열의 아이디와 비번이같으면 로그인
					{
						printf("로그인 성공!\n\n");
						return 0;
					}
					else
						printf("비밀번호가 다릅니다\n");
				}
			}
	

		case 3:
			exit();
		}
	}
}