#include <stdio.h>
#include <string.h>
#include "register.h"


int login_or_register()
{

	int  user_max=1;// user_max:���� ȸ������, rep_check:�ߺ�üũ ���
	char userid[15] = { 0 }, userpw[15] = { 0 };

	struct information list[INFORM] = { 0 };


	

	while (1)
	{
		int option;
		int rep_number = 1;             //�ߺ� ��� �ߺ��Ǹ� �ߺ���� 1�� �ʱ�ȭ
		int rep_check = 0;


		printf("���������\n��1. ȸ������ ��\n��2. �� �� �� ��\n��3. ����     ��\n���������\n");
		scanf_s("%d", &option);
		

		FILE* fp = fopen("data2.bin", "rb");
		fread(list, sizeof(struct information), INFORM, fp);


		if (list[0].age == 0)                        //ȸ���� user_max���ϱ�
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
					if (user_max == INFORM)          // ȸ���� �ʰ��� (ȸ����=5)
					{
						printf("ȸ���� �ʹ� �����ϴ�.\n");
						break;
					}
					printf("������ ID�� �Է��ϼ��� <�ִ� 15��> :");
					scanf_s("%s", list[user_max].userid, 15);
	
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

					printf("������ PW�� �Է��ϼ��� <�ִ� 15��> :");
					scanf_s("%s", list[user_max].userpw, 15);

					printf("�̸��� �Է����ּ���");
					scanf_s("%s", list[user_max].name, 30);              /////////////////////////////////////////////////////////

					printf("���̸� �Է����ּ���");
					scanf_s("%d", &list[user_max].age);                 ///////////////////////////////////////////////////////////////////

					printf("������ �����մϴ�!!\n");

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
					int a;
					int try_check=0;
		
					fp = fopen("data2.bin", "rb");

					fread(list, sizeof(struct information), INFORM, fp);

					for (int i = 0; i < INFORM; i++)
					{
						printf("%s %s %s %d %d try%d", list[i].userid, list[i].userpw, list[i].name, list[i].age, list[i].user_max1,list[i].login_try);
						printf("\n");
					}

					printf("���̵� �Է��ϼ��� : <�ִ�15��>");
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
						printf("�α��� �õ��� 5ȸ �ʰ��Ͽ����ϴ� �ش�������� �α��� �� �� �����ϴ�.\n\n");
					}

					printf("�н����带 �Է��ϼ��� <�ִ�15��>:");
					scanf_s("%s", userpw, 15);
	
					for (rep_check = 0; rep_check < INFORM; rep_check++)
					{
						if (strcmp(list[rep_check].userid, userid) == 0 && strcmp(list[rep_check].userpw, userpw) == 0)            //�ش�迭�� ���̵�� ����̰����� �α���
						{
							printf("�����������������α��� ����!�����������������\n\n");

							printf("���̵� : %s\n�̸� : %s\n���� : %d\n\n", list[rep_check].userid, list[rep_check].name, list[rep_check].age);
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
					printf("��й�ȣ�� �ٸ��ϴ�\n\n�����ʰ�Ƚ��:%dȸ 5ȸ�ʰ��� �ش���̵� �α��� �Ұ�\n\n",list[try_check].login_try);
					printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
				}
			}
			case 3:
				exit();
			default:
				printf("�ߡߡߡߡߡߡߡߡߡ߿ùٸ� �޴��� �������ּ���ߡߡߡߡߡߡߡߡߡ�\n");
				break;
		}
	}
}