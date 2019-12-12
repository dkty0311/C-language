#include <stdio.h>
#include <string.h>
#include "register.h"

#define _CRT_SECURE_NO_WARNINGS


int login_or_register()
{


	int  user_max = 0, rep_check = 0;                   // user_max:현재 회원숫자, rep_check:중복체크 상수
	char userid[10], userpw[10];


	struct information
	{
		char userid[15];								//구조체 선언
		char userpw[15];
		int age;
		char name[30];
		int user_max1;

	};

	struct information list[INFORM] = { 0 };


	

	while (1)
	{
		int option;
		int rep_number = 1;             //중복 상수 중복되면 중복상수 1로 초기화
		printf("■■■■■■■■\n■1. 회원가입 ■\n■2. 로 그 인 ■\n■3. 종료     ■\n■■■■■■■■\n");
		scanf_s("%d", &option);
		FILE* fp = fopen("data2.txt", "r");

		switch (option)
		{
		case 1:

			fread(&list[user_max], sizeof(struct information), INFORM, fp);

			if (list[INFORM-1].user_max1 != NULL)          // 회원수 초과시 (회원수=5)
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
				break;
			
			printf("생성할 PW를 입력하세요 <최대 9자> :");
			scanf_s("%s", list[user_max].userpw,10);
			
			printf("이름을 입력해주세요");
			scanf_s("%s", list[user_max].name, 30);              /////////////////////////////////////////////////////////

			printf("나이를 입력해주세요");
			scanf_s("%d", &list[user_max].age);///////////////////////////////////////////////////////////////////

			printf("가입을 축하합니다!!\n");

			list[user_max].user_max1 = user_max;
			user_max++;

			FILE* fp = fopen("data2.txt", "a");
		
			fwrite(&list[user_max - 1], sizeof(struct information), 1, fp);
			fclose(fp);

			break;


		case 2:
			while (1)
			{

				FILE* fp = fopen("data2.txt", "r");

				fread(&list[user_max-1], sizeof(struct information), INFORM, fp);
				
				printf("아이디를 입력하세요 :");
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
			

				printf("패스워드를 입력하세요 :");
				scanf_s("%s", userpw, 10);

				for (rep_check = 0; rep_check < user_max; rep_check++)
				{
					if (strcmp(list[rep_check].userid, userid) == 0 && strcmp(list[rep_check].userpw, userpw) == 0)            //해당배열의 아이디와 비번이같으면 로그인
					{
						printf("로그인 성공!\n\n");
						printf("아이디 : %s\n이름 : %s\n나이 : %d \n\n", list[rep_check].userid, list[rep_check].name, list[rep_check].age);
						fclose(fp);
						return 0;
					}
					else
					{
						printf("비밀번호가 다릅니다\n");
					}
				}
			}
	

		case 3:
			exit();
		}
	}
}