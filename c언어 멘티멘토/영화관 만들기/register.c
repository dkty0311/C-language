#include "register.h"


#define INFORM 5

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