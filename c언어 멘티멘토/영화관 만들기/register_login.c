#include <stdio.h>
#include <string.h>
#include "register.h"


int login_or_register()
{

	int  user_max=1;// user_max:현재 회원숫자, rep_check:중복체크 상수
	char userid[15] = { 0 }, userpw[15] = { 0 };

	struct information list[INFORM] = { 0 };


	

	while (1)
	{
		int option;
		int rep_number = 1;             //중복 상수 중복되면 중복상수 1로 초기화
		int rep_check = 0;


		printf("■■■■■■■■\n■1. 회원가입 ■\n■2. 로 그 인 ■\n■3. 종료     ■\n■■■■■■■■\n");
		scanf_s("%d", &option);
		

		FILE* fp = fopen("data2.bin", "rb");
		fread(list, sizeof(struct information), INFORM, fp);


		if (list[0].age == 0)                        //회원수 user_max구하기
		{
			user_max = 0;
		}
		else
		{
			for (int i = 0; i < INFORM; i++)
			{
				if (list[i].user_max1 >= user_max)
					user_max = list[i].user_max1 + 1;
			}
		}

		switch (option)
		{
			case 1:
			{
				if (option == 1)
				{
					if (user_max == INFORM)          // 회원수 초과시 (회원수=5)
					{
						printf("회원이 너무 많습니다.\n");
						break;
					}
					printf("생성할 ID를 입력하세요 <최대 15자> :");
					scanf_s("%s", list[user_max].userid, 15);
	
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

					printf("생성할 PW를 입력하세요 <최대 15자> :");
					scanf_s("%s", list[user_max].userpw, 15);

					printf("이름을 입력해주세요");
					scanf_s("%s", list[user_max].name, 30);              /////////////////////////////////////////////////////////

					printf("나이를 입력해주세요");
					scanf_s("%d", &list[user_max].age);                 ///////////////////////////////////////////////////////////////////

					printf("가입을 축하합니다!!\n");

					list[user_max].user_max1 = user_max;

					fp = fopen("data2.bin", "wb");

					fwrite(list, sizeof(struct information), INFORM, fp);
					fclose(fp);

					break;
				}
			}
			case 2:
			{
				while (1)
				{
					int try_check=-1;
		
					fp = fopen("data2.bin", "rb");

					fread(list, sizeof(struct information), INFORM, fp);

					printf("아이디를 입력하세요 : <최대15자>");
					scanf_s("%s", userid, 15);

					for (rep_check = 0; rep_check <= user_max; rep_check++)
					{
						if (strcmp(list[rep_check].userid, userid) == 0)
						{
							try_check = rep_check;
							break;
						}
					}

					if (list[try_check].login_try == 5)
					{
						printf("로그인 시도를 5회 초과하였습니다 해당계정으로 로그인 할 수 없습니다.\n\n");
						break;
					}
					else if (try_check == -1)
					{
						printf("없는 아이디 입니다.\n\n");
						break;
					}
					else if (list[try_check].login_try < 5)
					{
							printf("패스워드를 입력하세요 <최대15자>:");
							scanf_s("%s", userpw, 15);
	
							for (rep_check = 0; rep_check < INFORM; rep_check++)
							{
								if (strcmp(list[rep_check].userid, userid) == 0 && strcmp(list[rep_check].userpw, userpw) == 0)            //해당배열의 아이디와 비번이같으면 로그인
								{
									printf("■■■■■■■■■■■■■■■■로그인 성공!■■■■■■■■■■■■■■■■\n\n");

									printf("아이디 : %s\n이름 : %s\n나이 : %d\n\n", list[rep_check].userid, list[rep_check].name, list[rep_check].age);
									list[rep_check].login_try = 0;
									fp = fopen("data2.bin", "wb");
									fwrite(list, sizeof(struct information), INFORM, fp);
									fclose(fp);
									return rep_check;
								}
							}
							fp = fopen("data2.bin", "wb");
							list[try_check].login_try += 1;
							fwrite(list, sizeof(struct information), INFORM, fp);
							fclose(fp);
							printf("비밀번호가 다릅니다\n\n현재초과횟수:%d회 5회초과시 해당아이디 로그인 불가\n\n", list[try_check].login_try);
							printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
							break;
					}
				}
				break;
			}
			case 3:
				exit();
			default:
				printf("◆◆◆◆◆◆◆◆◆◆올바른 메뉴를 선택해주세요◆◆◆◆◆◆◆◆◆◆\n");
				break;
		}
	}
}