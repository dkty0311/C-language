#include "register.h"


#define INFORM 5

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