#include <stdio.h>
#include <string.h>
#include "register.h"

#define _CRT_SECURE_NO_WARNINGS


int login_or_register()
{


	int  user_max = 0, rep_check = 0;                   // user_max:���� ȸ������, rep_check:�ߺ�üũ ���
	char userid[10], userpw[10];


	struct information
	{
		char userid[15];								//����ü ����
		char userpw[15];
		int age;
		char name[30];
		int user_max1;

	};

	struct information list[INFORM] = { 0 };


	

	while (1)
	{
		int option;
		int rep_number = 1;             //�ߺ� ��� �ߺ��Ǹ� �ߺ���� 1�� �ʱ�ȭ
		printf("���������\n��1. ȸ������ ��\n��2. �� �� �� ��\n��3. ����     ��\n���������\n");
		scanf_s("%d", &option);
		FILE* fp = fopen("data2.txt", "r");

		switch (option)
		{
		case 1:

			fread(&list[user_max], sizeof(struct information), INFORM, fp);

			if (list[INFORM-1].user_max1 != NULL)          // ȸ���� �ʰ��� (ȸ����=5)
			{
				printf("ȸ���� �ʹ� �����ϴ�.\n");
				break;
			}
			printf("������ ID�� �Է��ϼ��� <�ִ� 9��> :");
			scanf_s("%s", list[user_max].userid,10);

			for (rep_check = 0; rep_check < user_max; rep_check++)
			{
				if (strcmp(list[user_max].userid, list[rep_check].userid) == 0)
				{
					printf("�̹� ������ ID�Դϴ�.\n\n");
					rep_number = 0;
					break;
				}
			}

			if (rep_number == 0)
				break;
			
			printf("������ PW�� �Է��ϼ��� <�ִ� 9��> :");
			scanf_s("%s", list[user_max].userpw,10);
			
			printf("�̸��� �Է����ּ���");
			scanf_s("%s", list[user_max].name, 30);              /////////////////////////////////////////////////////////

			printf("���̸� �Է����ּ���");
			scanf_s("%d", &list[user_max].age);///////////////////////////////////////////////////////////////////

			printf("������ �����մϴ�!!\n");

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
				
				printf("���̵� �Է��ϼ��� :");
				scanf_s("%s", userid, 10);

				for (rep_check = 0; rep_check <= user_max; rep_check++)
				{

					if (strcmp(userid, list[rep_check].userid) == 1)
					{
						printf("���� ���̵��Դϴ�\n");
						continue;
					}
					else
						break;
				}
			

				printf("�н����带 �Է��ϼ��� :");
				scanf_s("%s", userpw, 10);

				for (rep_check = 0; rep_check < user_max; rep_check++)
				{
					if (strcmp(list[rep_check].userid, userid) == 0 && strcmp(list[rep_check].userpw, userpw) == 0)            //�ش�迭�� ���̵�� ����̰����� �α���
					{
						printf("�α��� ����!\n\n");
						printf("���̵� : %s\n�̸� : %s\n���� : %d \n\n", list[rep_check].userid, list[rep_check].name, list[rep_check].age);
						fclose(fp);
						return 0;
					}
					else
					{
						printf("��й�ȣ�� �ٸ��ϴ�\n");
					}
				}
			}
	

		case 3:
			exit();
		}
	}
}