#include <stdio.h>
#include <string.h>
#include "register.h"
#include "accomodation.h"
#include "show_choice_menu.h"

int login_or_register()
{

	int  user_max = 0, rep_check = 0;                   // user_max:���� ȸ������, rep_check:�ߺ�üũ ���
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
			{
//�ߺ��� �ش�迭�� ����� id���� ����
				break;
			}

			printf("������ PW�� �Է��ϼ��� <�ִ� 9��> :");
			scanf_s("%s", list[user_max].userpw,10);
			printf("������ �����մϴ�!!\n");
			user_max++;
			break;

		case 2:
			while (1)
			{
				printf("ID�� �Է��ϼ��� :");
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
				break;
			}
			
			while (1)
			{

				printf("PW�� �Է��ϼ��� :");
				scanf_s("%s", userpw, 10);

				for (rep_check = 0; rep_check < user_max; rep_check++)
				{
					if (strcmp(list[rep_check].userid, userid) == 0 && strcmp(list[rep_check].userpw, userpw) == 0)            //�ش�迭�� ���̵�� ����̰����� �α���
					{
						printf("�α��� ����!\n\n");
						return 0;
					}
					else
						printf("��й�ȣ�� �ٸ��ϴ�\n");
				}
			}
	

		case 3:
			exit();
		}
	}
}