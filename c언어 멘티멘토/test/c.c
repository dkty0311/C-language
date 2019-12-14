#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)warning pragma

struct book_info

{

	char title[41];

	char auth[31];

	char publ[31];

	int stat; // ���� ���� �ĺ�. 0->�������� ���� 1->�뿩�� 2->�� ��ȣ�� å�� ����.

	int book_num; // ���� ��ȣ

	struct user_info* user;

};

struct user_info

{

	char id[21];

	char pass[21];

	int borr; // ������ å ��

	int stat; //ȸ�� ���� �ĺ�. 0->�� ���� 1->�� �ִ� ����

	struct book_info* borrow_list[5];

	struct user_info* nextuser;

};

int lib_init_book(int* init, struct book_info* book_list, int* total_book);

int lib_init_user(int* init, struct user_info* user_list, int* total_user);

int lib_init_borrow(int* init, struct book_info* book_list, struct user_info* user_list, int* total_book, int* total_user);

int login_user(char* id, char* pass, struct user_info* user_list, struct user_info* session, int* total_user, int* user_key); // 0->������ 1->������ �ƴ� 2->ID or ��� Ʋ��

int add_book(struct book_info* book_list, int* total_book);

int delete_book(struct book_info* book_list, int* total_book, struct user_info* user_list, int* total_user);

int change_book(struct book_info* book_list, int* book_num, int* total_book);

int search_book(struct book_info* book_list, int* total_book);

int arrange_book(struct book_info* book_list, int* total_book);

void print_book(struct book_info* book);

int print_user(struct user_info* user_list, int* total_user);

int add_user(struct user_info* user_list, int* total_user);

int delete_user(struct user_info* user_list, int* total_user, struct book_info* book_list, int* total_book);

int borrow_book(struct book_info* book_list, struct user_info* curr_user, int* total_book);

int return_book(struct book_info* book_list, struct user_info* curr_user);

int compare_string(char* keyword, char* source);

int input_num(int* result, int form);

int input_string(char* result, int form);

int close_lib(struct book_info* book_list, struct user_info* user_list, int* total_book, int* total_user);

int main()

{

	int i, j;

	int init;

	char str1[22];

	char str2[22];

	char c[3];

	int total_book = 0;

	int total_user = 0;

	int user_key = -1;

	struct book_info book_list[100];

	struct user_info user_list[100];

	struct user_info curr_user;

	printf("������ ������ �ҷ����� �ֽ��ϴ�.. \n");

	lib_init_book(&init, book_list, &total_book);

	if (init == 0)

	{

		printf("���� ������ �ʱ�ȭ���� �ʾҽ��ϴ�. \n");

		return 0;

	}

	init = 0;

	lib_init_user(&init, user_list, &total_user);

	if (init == 0)

	{

		printf("����� ������ �ʱ�ȭ���� �ʾҽ��ϴ�. \n");

		return 0;

	}

	lib_init_borrow(&init, book_list, user_list, &total_book, &total_user);

	if (init == 0)

	{

		printf("���� ���� ��Ȳ�� �ҷ��� �� �������ϴ�. ��� �����Ͻðڽ��ϱ�? y/n :");

		input_string(c, 1);

		if (strcmp(c, "n") == 0)

		{

			printf("�������� ����Ǿ����ϴ�. \n");

			return 0;

		}

	}

	printf("�������� ���۵˴ϴ�. \n");

	for (;;)

	{

		printf("����� ������ Ȯ���� �ֽʽÿ�. \n");

		printf("ID : ");

		input_string(str1, 20);

		printf("PASSWORD : ");

		input_string(str2, 20);

		login_user(str1, str2, user_list, &curr_user, &total_user, &user_key);

		if (user_key == 0)

		{

			printf("�����ڷ� �α��εǾ����ϴ�. \n");

			for (;;)

			{

				printf("  �����Ϸ��� �۾��� �����Ͻʽÿ�. \n");

				printf("  1. ���� �߰� \n  2. ���� ����\n  3. ���� ���� ����\n  4. ���� �˻�\n  5. ���� ��ȸ\n  6. ȸ�� �߰�\n  7. ȸ�� ����\n  8. ȸ�� ���� ��ȸ\n  9. ���� ����\n  10. ���� �ݳ�\n  11. ������ ����\n  12. ������ ����  : ");

				input_num(&i, 2);

				if (i == 1)

				{

					if (total_book > 100)

					{

						printf("�� �弭 ���� ��� ������ ���� �Ѿ���ϴ�. \n");

					}

					else

					{

						add_book(book_list, &total_book);

						total_book++;

					}

				}

				else if (i == 2)

				{

					if (total_book < 1)

					{

						printf("å�� �� �ǵ� �����ϴ�. \n");

					}

					else

					{

						delete_book(book_list, &total_book, user_list, &total_user);

						total_book = total_book - 1;

					}

				}

				else if (i == 3)

				{

					printf("�����Ϸ��� ������ �Ϸù�ȣ�� �Է��Ͻʽÿ�. : ");

					input_num(&j, 8);

					change_book(book_list, &j, &total_book);



				}

				else if (i == 4)

				{

					search_book(book_list, &total_book);

				}

				else if (i == 5)

				{

					printf("���� ����� ����մϴ�. �Ϸù�ȣ ������ ��µ˴ϴ�. \n");

					arrange_book(book_list, &total_book);

				}

				else if (i == 6) //ȸ�� �߰�

				{

					if (total_user > 99)

					{

						printf("�� �̻� ȸ���� �߰��� �� �����ϴ�.");

					}

					else

					{

						add_user(user_list, &total_user);

					}

				}

				else if (i == 7) //ȸ�� ����

				{

					delete_user(user_list, &total_user, book_list, &total_book);

				}

				else if (i == 8)//ȸ�� ���� ��Ȳ ��ȸ

				{

					print_user(user_list, &total_user);

				}

				else if (i == 9)//���� ����

				{

					borrow_book(book_list, &curr_user, &total_book);

				}

				else if (i == 10)//���� �ݳ�

				{

					return_book(book_list, &curr_user);

				}

				else if (i == 11)

				{

					printf("������ ��尡 ����˴ϴ�. \n");

					break;

				}

				else if (i == 12)

				{

					printf("�������� ����˴ϴ�. ������ �����ϴ� ���� ��� ��ٸ��ʽÿ�. \n");

					close_lib(book_list, user_list, &total_book, &total_user);

					printf("�������� ����Ǿ����ϴ�. \n");

					return 0;

				}

				else

				{

					printf("�߸��� ����Դϴ�. \n");

				}

			}

		}//������ ���� ����. �Ϲ� ����� ���� ����

		else if (user_key != 0 && user_key > 0)

		{

			printf("�Ϲ� ����ڷ� �α��εǾ����ϴ�. \n");

			for (;;)

			{

				printf("  �����Ϸ��� �۾��� �����Ͻʽÿ�. \n");

				printf("  1. ���� �˻�\n  2. ���� ����\n  3. ���� �ݳ�\n  4. ���� ��Ȳ ��ȸ\n  5. ���� : ");

				input_num(&i, 1);

				if (i == 1)

				{

					search_book(book_list, &total_book);

				}

				else if (i == 2)

				{

					borrow_book(book_list, &curr_user, &total_book);

				}

				else if (i == 3)

				{

					return_book(book_list, &curr_user);

				}

				else if (i == 4)

				{

					if (curr_user.borr < 1)

					{

						printf("���� �������� ������ �����ϴ�. \n");

					}

					else

					{

						printf("�������� ���� ����� ������ �����ϴ�. \n");

						for (j = 0; j < curr_user.borr; j++)

						{

							printf("title : %s \n", curr_user.borrow_list[j]->title);

						}

					}

				}

				else if (i == 5)

				{

					printf("�α׾ƿ� �մϴ�. \n");

					user_list[user_key] = curr_user;

					break;

				}

				else

				{

					printf("�߸��� ����Դϴ�. \n");

				}

			}

		}

		else if (user_key == -1)

		{

			printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�. \n");

		}

		else if (user_key == -2)

		{

			printf("�Է��� ID �� �������� �ʽ��ϴ�. \n");

		}

		else

		{

			printf("����� ������ ��ġ���� �ʽ��ϴ�. \n");

		}

		printf("�������� ��� �̿��Ͻðڽ��ϱ�? y/n : ");

		input_string(c, 1);

		if (strcmp(c, "n") == 0)

		{

			printf("�������� �����մϴ�. ������ �����ϴ� ���� ��� ��ٷ� �ֽʽÿ�. \n");

			close_lib(book_list, user_list, &total_book, &total_user);

			return 0;

		}

	}

	return 0;

}

int lib_init_book(int* init, struct book_info* book_list, int* total_book)

{

	char c;

	int i = 0;

	FILE* book_stream = fopen("book_list.txt", "r");

	if (book_stream == NULL)

	{

		*init = 0;

		return 0;

	}

	else

	{

		*init = 1;

	}

	while ((c = fgetc(book_stream)) != EOF)

	{

		if (c == '/')

		{

			fgetc(book_stream);

			fgets(book_list[i].title, 41, book_stream);

			book_list[i].title[strlen(book_list[i].title) - 1] = '\0';

			fgets(book_list[i].auth, 31, book_stream);

			book_list[i].auth[strlen(book_list[i].auth) - 1] = '\0';

			fgets(book_list[i].publ, 31, book_stream);

			book_list[i].publ[strlen(book_list[i].publ) - 1] = '\0';

			fscanf(book_stream, "%d", &book_list[i].stat);

			fscanf(book_stream, "%d", &book_list[i].book_num);

			i++;

		}

	}

	*total_book = i;

	fclose(book_stream);

	return 0;

}

int lib_init_user(int* init, struct user_info* user_list, int* total_user)

{

	char c;

	int i = 0;

	FILE* user_stream = fopen("user_list.txt", "r");

	if (user_stream == NULL)

	{

		*init = 0;

		return 0;

	}

	else

	{

		*init = 1;

	}

	while ((c = fgetc(user_stream)) != EOF)

	{

		if (c == '/')

		{

			fgetc(user_stream);

			fgets(user_list[i].id, 21, user_stream);

			user_list[i].id[strlen(user_list[i].id) - 1] = '\0';

			fgets(user_list[i].pass, 21, user_stream);

			user_list[i].pass[strlen(user_list[i].pass) - 1] = '\0';

			fscanf(user_stream, "%d", &user_list[i].borr);

			user_list[i].stat = 1;

			i++;

		}

	}

	*total_user = i;

	fclose(user_stream);

	for (i = 0; i < *total_user - 1; i++)

	{

		user_list[i].nextuser = &user_list[i + 1];

	}

	i++;

	user_list[i].nextuser = &user_list[0];

	return 0;

}

int lib_init_borrow(int* init, struct book_info* book_list, struct user_info* user_list, int* total_book, int* total_user)

{

	int i, j, k, l;

	char c;

	char str1[22];

	FILE* borrow_stream;

	borrow_stream = fopen("borrow_list.txt", "r");

	if (borrow_stream == NULL)

	{

		*init = 0;

		return 0;

	}

	else

	{

		*init = 1;

	}

	while ((c = fgetc(borrow_stream)) != EOF)

	{

		if (c == '/')

		{

			fgets(str1, 21, borrow_stream);

			str1[strlen(str1) - 1] = '\0';

			for (i = 0; i < *total_user; i++)

			{

				if (strcmp(user_list[i].id, str1) == 0)

				{

					for (j = 0; j < user_list[i].borr; j++)

					{

						fscanf(borrow_stream, "%d", &k);

						for (l = 0; l < *total_book; l++)

						{

							if (k == book_list[l].book_num)

							{

								user_list[i].borrow_list[j] = &book_list[l];

							}

						}

					}

				}

			}

		}

	}

	fclose(borrow_stream);

	for (i = 0; i < *total_user; i++)

	{

		if (user_list[i].borr > 0)

		{

			for (k = 0; k < user_list[i].borr; k++)

			{

				for (j = 0; j < *total_book; j++)

				{

					if (book_list[j].book_num == user_list[i].borrow_list[k]->book_num)

					{

						book_list[j].user = &user_list[i];

					}

				}

			}

		}

	}

	return 0;

}

int login_user(char* id, char* pass, struct user_info* user_list, struct user_info* session, int* total_user, int* user_key)

{

	int i;

	int count = 1;

	if (strcmp(id, "admin") == 0)

	{

		if (strcmp(pass, "password") == 0)

		{

			*session = user_list[0];

			*user_key = 0;

			return 0;

		}

		else

		{

			*user_key = 2;

			return 0;

		}

	}

	else

	{

		for (i = 1; i < *total_user; i++)

		{

			if (strcmp(id, user_list[i].id) == 0)

			{

				if (strcmp(pass, user_list[i].pass) == 0)

				{

					*session = user_list[i];

					*user_key = i;

					return 0;

				}

				else

				{

					*user_key = -1;

					return 0;

				}

			}

		}

		if (i == *total_user)

		{

			*user_key = -2;

			return 0;

		}

	}

}

int add_book(struct book_info* book_list, int* total_book)

{

	int i = 0;

	int j;

	int book_locat;

	int count = 0;

	char str1[42];

	char str2[32];

	char str3[32];

	char c[3];

	book_locat = *total_book;

	printf("å�� ������ �Է��� �ֽʽÿ�. \n");

	for (;;)

	{

		printf("���� : ");

		input_string(str1, 40);

		for (i = 0; i < *total_book; i++)

		{

			if (strcmp(str1, book_list[i].title) == 0)

			{

				printf("��ġ�ϴ� �������� �ֽ��ϴ�. �߰��� �� �����ϴ�. \n");

				return 0;

			}

		}

		strcpy(book_list[book_locat].title, str1);

		break;

	}

	for (;;)

	{

		printf("���� : ");

		input_string(str2, 30);

		strcpy(book_list[book_locat].auth, str2);

		break;

	}

	for (;;)

	{

		printf("���ǻ� : ");

		input_string(str3, 30);

		strcpy(book_list[book_locat].publ, str3);

		break;

	}

	count = 0;

	for (;;)

	{

		printf("�Ϸù�ȣ�� �Է��Ͻʽÿ�. ��, 0 �� �Է��� �� �����ϴ�. : ");

		input_num(&j, 8);

		for (i = 0; i < *total_book; i++)

		{

			if (j == book_list[i].book_num || j == 0)

			{

				printf("����� �� ���� ��ȣ�Դϴ�. \n");

				printf("��� �Է��Ͻðڽ��ϱ�? y/n :");

				input_string(c, 1);

				if (strcmp(c, "n") == 0)

				{

					printf("���� �Է��� �ߴ��߽��ϴ�. \n");

					return 0;

				}

			}

		}

		book_list[book_locat].book_num = j;

		break;

	}

	book_list[book_locat].stat = 0;

	return 0;

}

int delete_book(struct book_info* book_list, int* total_book, struct user_info* user_list, int* total_user)

{

	int i, j, k, l;

	int result = 1;

	int book_locat;

	char str[42];

	printf("  ���� ����� ������ �ֽʽÿ�.\n  1) �Ϸù�ȣ\n  2) ���� : ");

	input_num(&j, 1);

	if (j == 1)

	{

		printf("�����Ϸ��� å�� �Ϸù�ȣ�� �Է��Ͻʽÿ�. : ");

		input_num(&k, 8);

		for (i = 0; i < *total_book; i++)

		{

			if (k == book_list[i].book_num && book_list[i].stat == 0)

			{

				book_locat = i;

				book_list[i].stat = 2;

				*book_list[i].title = NULL;

				*book_list[i].auth = NULL;

				*book_list[i].publ = NULL;

				book_list[i].book_num = 0;

				result = 0;

				printf("å�� �����Ǿ����ϴ�. \n");

				break;

			}

			else if (k == book_list[i].book_num && book_list[i].stat == 1)

			{

				printf("�������� å�� ���� �� �����ϴ�. \n");

				return 0;

			}

		}

		if (i == *total_book)

		{

			printf("��ġ�ϴ� ��ȣ�� å�� �����ϴ�. \n");

			return 0;

		}

	}

	else if (j == 2)

	{

		printf("�����Ϸ��� å�� ������ �Է��Ͻʽÿ�. : ");

		input_string(str, 40);

		for (i = 0; i < *total_book; i++)

		{

			if (strcmp(str, book_list[i].title) == 0 && book_list[i].stat == 0)

			{

				book_locat = i;

				book_list[i].stat = 2;

				*book_list[i].title = NULL;

				*book_list[i].auth = NULL;

				*book_list[i].publ = NULL;

				book_list[i].book_num = 0;

				result = 0;

				printf("å�� �����Ǿ����ϴ�. \n");

				break;

			}

			else if (strcmp(str, book_list[i].title) == 0 && book_list[i].stat == 1)

			{

				printf("�������� å�� ���� �� �����ϴ�. \n");

				return 0;

			}

		}

		if (i == *total_book)

		{

			printf("��ġ�ϴ� ������ å�� �����ϴ�. \n");

			return 0;

		}

	}

	else

	{

		printf("�߸��� �Է��Դϴ�. \n");

	}

	for (i = book_locat; i < *total_book; i++)

	{

		for (j = 0; j < *total_user; j++)

		{

			if (user_list[j].borr > 0)

			{

				for (k = 0; k < user_list[j].borr; k++)

				{

					if (&book_list[i] == user_list[j].borrow_list[k])

					{

						user_list[j].borrow_list[k]--;

					}

				}



			}

		}

	}

	for (i = 0; i < *total_book; i++)

	{

		if (book_list[i].stat == 2)

		{

			for (j = i; j < *total_book; j++)

			{

				book_list[j] = book_list[j + 1];

			}

		}

	}

	return 0;

}

int change_book(struct book_info* book_list, int* book_num, int* total_book)

{

	int i;

	int change;

	int count;

	int num = 0;

	char str[42];

	char c[3];

	for (i = 0; i < *total_book; i++)

	{

		if (book_list[i].book_num == *book_num)

		{

			change = i;

			break;

		}

	}

	if (i == *total_book)

	{

		printf("��ġ�ϴ� �Ϸù�ȣ�� å�� �����ϴ�. \n");

		return 0;

	}

	printf("�����Ϸ��� å�� ������ �Է��մϴ�. \n");

	for (;;)

	{

		printf("���� : ");

		input_string(str, 40);

		strcpy(book_list[change].title, str);

		break;

	}

	for (;;)

	{

		printf("���� : ");

		input_string(str, 30);

		strcpy(book_list[change].auth, str);

		break;

	}

	for (;;)

	{

		printf("���ǻ� : ");

		input_string(str, 30);

		strcpy(book_list[change].publ, str);

		break;

	}

	for (;;)

	{

		printf("�Ϸù�ȣ : ");

		input_num(&num, 8);

		for (i = 0; i < *total_book; i++)

		{

			if (num == book_list[i].book_num && i != change)

			{

				printf("������ �Ϸù�ȣ�� å�� �ֽ��ϴ�. \n");

				break;

			}

		}

		if (i == *total_book)

		{

			book_list[change].book_num = num;

		}

		break;

	}

	return 0;

}

int search_book(struct book_info* book_list, int* total_book)

{

	int i, j;

	int result = 0;

	char str[42];

	char c[3];

	printf("���� �� �������� �˻��ϰڽ��ϱ�? \n 1. ����\n 2. ����\n 3. ���ǻ�\n 4. �Ϸù�ȣ : ");

	input_num(&i, 1);

	if (i == 1)

	{

		printf("�˻� Ű���带 �Է��Ͻʽÿ� : ");

		input_string(str, 40);

		for (i = 0; i < *total_book; i++)

		{

			if (compare_string(str, book_list[i].title) == 0)

			{

				print_book(&book_list[i]);

				result++;

			}

		}

	}

	else if (i == 2)

	{

		printf("�˻� Ű���带 �Է��Ͻʽÿ� : ");

		input_string(str, 30);

		for (i = 0; i < *total_book; i++)

		{

			if (compare_string(str, book_list[i].auth) == 0)

			{

				print_book(&book_list[i]);

				result++;

			}

		}

	}

	else if (i == 3)

	{

		printf("�˻� Ű���带 �Է��Ͻʽÿ� : ");

		input_string(str, 30);

		for (i = 0; i < *total_book; i++)

		{

			if (compare_string(str, book_list[i].auth) == 0)

			{

				print_book(&book_list[i]);

				result++;

			}

		}

	}

	else if (i == 4)

	{

		printf("�� �� å�� �˻��ϰڽ��ϱ�? : ");

		input_num(&j, 8);

		for (i = 0; i < *total_book; i++)

		{

			if (j == book_list[i].book_num)

			{

				print_book(&book_list[i]);

				result++;

			}

		}

	}

	else

	{

		printf("�߸��� ����Դϴ�. \n");

		return 0;

	}

	if (result > 0)

	{

		printf("�˻��� �Ϸ�Ǿ����ϴ�. \n");

		return 0;

	}

	else

	{

		printf("��ġ�ϴ� �˻�� �����ϴ�. \n");

		return 0;

	}

}

void print_book(struct book_info* book)

{

	int i;

	char c;

	int j = 0;

	printf("���� : %s \n", book->title);

	printf("���� : %s \n", book->auth);

	printf("���ǻ� : %s \n", book->publ);

	printf("�Ϸù�ȣ : %d \n", book->book_num);

	if (book->stat == 1)

	{

		printf("   ���� ���� : ������ / ������ ����� : %s \n ", book->user->id);

	}

	else

	{

		printf("   ���� ���� : �������� ���� \n");

	}



}

int arrange_book(struct book_info* book_list, int* total_book)

{

	int i, j;

	int* arr;

	arr = (int*)malloc(sizeof(int) * *total_book);

	for (i = 0; i < *total_book; i++)

	{

		arr[i] = 0;

	}

	for (i = 0; i < *total_book; i++)

	{

		for (j = 0; j < *total_book; j++)

		{

			if (book_list[i].book_num - book_list[j].book_num > 0)

			{

				arr[i]++;

			}

		}

	}

	for (i = 0; i < *total_book; i++)

	{

		for (j = 0; j < *total_book; j++)

		{

			if (i == arr[j])

			{

				print_book(&book_list[j]);

			}

		}

	}

	free(arr);

	return 0;

}

int add_user(struct user_info* user_list, int* total_user)

{

	int i, total_user_temp;

	char str1[22];

	char str2[22];

	total_user_temp = *total_user;

	printf("�߰��Ϸ��� ������� ������ �Է��Ͻʽÿ�. ID �� ��й�ȣ�� 20�� �Ʒ��θ� �Էµ˴ϴ�. \n");

	printf("���̵� : ");

	input_string(str1, 20);

	printf("��й�ȣ : ");

	input_string(str2, 20);

	for (i = 0; i < *total_user; i++)

	{

		if (user_list[i].stat == 0)

		{

			strcpy(user_list[i].id, str1);

			strcpy(user_list[i].pass, str2);

			user_list[i].stat = 1;

			user_list[i].borr = 0;

			total_user_temp++;

			printf("�����Է��� �Ϸ�Ǿ����ϴ�. \n");

			break;

		}

	}

	if (total_user_temp == *total_user)

	{

		strcpy(user_list[i].id, str1);

		strcpy(user_list[i].pass, str2);

		user_list[i].stat = 1;

		user_list[i].borr = 0;

		total_user_temp++;

		printf("�����Է��� �Ϸ�Ǿ����ϴ�. \n");

	}

	*total_user = total_user_temp;

	return 0;

}

int delete_user(struct user_info* user_list, int* total_user, struct book_info* book_list, int* total_book)

{

	int i;

	int j, k;

	int result = 0;

	char str1[22];

	char str2[22];

	printf("�����Ϸ��� ������� ������ �Է��Ͻʽÿ�. \n");

	printf("���̵� : ");

	input_string(str1, 20);

	printf("��й�ȣ : ");

	input_string(str2, 20);

	for (i = 0; i < *total_user; i++)

	{

		if (strcmp(user_list[i].id, str1) == 0)

		{

			if (strcmp(user_list[i].pass, str2) == 0)

			{

				if (user_list[i].borr > 0)

				{

					printf("���� ������ �ִ� ����ڴ� ������ �� �����ϴ�.  \n");

					return 0;

				}

				user_list[i].stat = 0;

				printf("����� ������ �����Ǿ����ϴ�. \n");

				for (i = 0; i < *total_user; i++)

				{

					if (user_list[i].stat == 0)

					{

						for (j = i; j < *total_user; j++)

						{

							for (k = 0; k < *total_book; k++)

							{

								if (book_list[k].user == &user_list[j])

								{

									book_list[k].user--;

								}

							}

							user_list[j] = user_list[j + 1];

						}

					}

				}

				*total_user -= 1;

				result = 1;

				return 0;

			}

			else

			{

				printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�. \n");

				return 0;

			}

		}

	}

	if (result == 0)

	{

		printf("��ġ�ϴ� ����� ������ �����ϴ�. \n");

	}

	return 0;

}

int print_user(struct user_info* user_list, int* total_user)

{

	int i, j;

	char str1[42];

	printf("��ȸ�Ϸ��� ȸ���� ID �� �Է��Ͻʽÿ�. : ");

	fgets(str1, 21, stdin);

	str1[strlen(str1) - 1] = '\0';

	for (i = 0; i < *total_user; i++)

	{

		if (user_list[i].stat == 1)

		{

			if (strcmp(str1, user_list[i].id) == 0)

			{

				if (user_list[i].borr > 0)

				{

					printf("�ش� ȸ���� ���� ��Ȳ�� �Ʒ��� �����ϴ�. \n");

					for (j = 0; j < user_list[i].borr; j++)

					{

						printf("���⵵�� %d : %s \n", j + 1, user_list[i].borrow_list[j]->title);

					}

					return 0;

					break;

				}

				else

				{

					printf("�ش� ȸ���� �������� ������ �����ϴ�. \n");

					return 0;

				}

			}

		}

	}

	if (i == *total_user)

	{

		printf("ID �� ��ġ�ϴ� ����ڰ� �������� �ʽ��ϴ�. \n");

		return 0;

	}

}

int borrow_book(struct book_info* book_list, struct user_info* curr_user, int* total_book)

{

	int i, j, k;

	char str1[42];

	char c[3];

	if (curr_user->borr > 4)

	{

		printf("�뿩 ������ å ���� �ʰ������Ƿ� �� �̻��� ���� �� �����ϴ�. \n");

		return 0;

	}

	else

	{

		printf("������ ���� �����ڽ��ϱ�? \n 1. ���� \n 2. �Ϸù�ȣ : ");

		input_num(&i, 1);

		if (i == 1)

		{

			printf("�������� å�� ������ �Է��Ͻʽÿ�. : ");

			input_string(str1, 40);

			for (j = 0; j < *total_book; j++)

			{

				if (strcmp(str1, book_list[j].title) == 0)

				{

					if (book_list[j].stat == 0)

					{

						book_list[j].stat = 1;

						curr_user->borr = +1;

						curr_user->borrow_list[curr_user->borr - 1] = &book_list[j];

						book_list[j].user = curr_user;

						printf("���� ������ : %s \n", book_list[j].title);

						printf("���� ����� : %s \n", curr_user->id);

						return 0;

					}

					else if (book_list[j].stat == 1)

					{

						printf("�̹� �뿩���� å�̶� ���� �� �����ϴ�. \n");

						return 0;

					}

					else

					{

						printf("�ش� ������ �������� �ʴ� �����Դϴ�. \n");

						return 0;

					}

				}

			}

			if (j == *total_book)

			{

				printf("��ġ�ϴ� �������� �����ϴ�. \n");

				return 0;

			}

		}

		else if (i == 2)

		{

			printf("�������� å�� ��ȣ�� �Է��Ͻʽÿ� : ");

			input_num(&k, 8);

			for (j = 0; j < *total_book; j++)

			{

				if (k == book_list[j].book_num)

				{

					if (book_list[j].stat == 0)

					{

						book_list[j].stat = 1;

						curr_user->borr++;

						curr_user->borrow_list[curr_user->borr - 1] = &book_list[j];

						printf("���� ������ : %s \n", book_list[j].title);

						printf("���� ����� : %s \n", curr_user->id);

						return 0;

					}

					else if (book_list[i].stat == 1)

					{

						printf("�̹� �뿩���� å�̶� ���� �� �����ϴ�. \n");

						return 0;

					}

					else

					{

						printf("�ش� ������ �������� �ʴ� �����Դϴ�. \n");

						return 0;

					}

				}

			}

			if (j == *total_book)

			{

				printf("��ġ�ϴ� �������� �����ϴ�. \n");

				return 0;

			}

		}

		else

		{

			printf("�߸��� ����Դϴ�. \n");

			return 0;

		}

	}

	return 0;

}

int return_book(struct book_info* book_list, struct user_info* curr_user)

{

	int i, j, k, l;

	int return_temp;

	char str1[42];

	char c[3];

	return_temp = curr_user->borr;

	if (curr_user->borr < 1)

	{

		printf("�ݳ��� �� �ִ� å�� �����ϴ�. \n");

		return 0;

	}

	else

	{

		printf("�������� �ݳ��ϰڽ��ϱ�? \n1. ���� \n2. �Ϸù�ȣ : ");

		input_num(&i, 1);

		if (i == 1)

		{

			printf("�ݳ��Ϸ��� å�� ������ �Է��Ͻʽÿ� : ");

			input_string(str1, 40);

			for (j = 0; j < curr_user->borr; j++)

			{

				if (strcmp(curr_user->borrow_list[j]->title, str1) == 0)

				{

					curr_user->borrow_list[j]->stat = 0;

					for (k = j; k < curr_user->borr; k++)

					{

						curr_user->borrow_list[k] = curr_user->borrow_list[k + 1];

					}

					curr_user->borr -= 1;

					printf("å�� �ݳ��Ǿ����ϴ�. \n");

					return 0;

				}

			}

			if (return_temp == curr_user->borr)

			{

				printf("����ڰ� ������ å�� �ƴմϴ�. \n");

				return 0;

			}

		}

		else if (i == 2)

		{

			printf("�ݳ��Ϸ��� å�� ��ȣ�� �Է��Ͻʽÿ� : ");

			input_num(&l, 8);

			for (j = 0; j < curr_user->borr; j++)

			{

				if (l == curr_user->borrow_list[j]->book_num)

				{

					curr_user->borrow_list[j]->stat = 0;

					for (k = j; k < curr_user->borr - 1; k++)

					{

						curr_user->borrow_list[k] = curr_user->borrow_list[k + 1];

					}

					curr_user->borr -= 1;

					printf("å�� �ݳ��Ǿ����ϴ�. \n");

					return 0;

				}

			}

			if (return_temp == curr_user->borr)

			{

				printf("����ڰ� ������ å�� �ƴմϴ�. \n");

				return 0;

			}

		}

		else

		{

			printf("�߸��� �Է��Դϴ�. \n");

			return 0;

		}

	}

}

int compare_string(char* keyword, char* source)

{

	int i = 0, j = 0;

	while (*keyword)

	{

		if (*keyword == *source)

		{

			keyword++;

			source++;

			i++;

			if (*keyword == '\0')

			{

				keyword = keyword - i;

				source = source - i;

				i = 0;

				return 0;

			}

		}

		else

		{

			keyword = keyword - i;

			source++;

			i = 0;

			if (*source == '\0')

			{

				return 1;

			}

		}

	}

}

int input_num(int* result, int form)

{

	int i;

	int j = 1;

	int sign = 1;

	int input_size;

	char* str;

	if (form > 9)

	{

		printf("�Է� ������ �ʹ� Ů�ϴ�. �Լ� ������ Ȯ���Ͻʽÿ�. \n");

		return 0;

	}

	*result = 0;

	str = (char*)malloc(sizeof(char) * form + 2);

	for (;;)

	{

		sign = 1;

		fgets(str, form + 2, stdin);

		for (i = 0; i < form + 1; i++)

		{

			if (str[i] == '\n')

			{

				input_size = i;

				break;

			}

		}

		if (i == form + 1)

		{

			printf("�Է� ������ �ʰ��߽��ϴ�. \n");

			while (getchar() != '\n')

			{
			}

			printf("�ٽ� �Է��Ͻʽÿ� : ");

			continue;

		}

		for (i = 0; i < input_size; i++)

		{

			if (str[i] < 48 || str[i]>57)

			{

				if (str[i] != '\n')

				{

					printf("���ڸ� �Է��� �� �ֽ��ϴ�. \n");

					printf("�ٽ� �Է��Ͻʽÿ� : ");

					sign = 0;

					break;

				}

			}

		}

		if (sign == 0)

		{

			continue;

		}

		for (i = 0; i < input_size; i++)

		{

			*result = *result + (str[input_size - i - 1] - 48) * j;

			j = j * 10;

		}

		break;

	}

	free(str);

	return 0;

}

int input_string(char* result, int form)

{

	int i;

	int input = 0;

	for (;;)

	{

		fgets(result, form + 2, stdin);

		for (i = 0; i < form + 2; i++)

		{

			if (result[i] == '\n')

			{

				result[strlen(result) - 1] = '\0';

				input = 1;

				break;

			}

			else if (result[i] != '\n' && i == form + 1)

			{

				printf("�Է� ������ ������ �Ѿ���ϴ�. %d ���� �̻� �Է����� ���ʽÿ�. \n", form);

				result[0] = '\0';

				while (getchar() != '\n')

				{
				}

				printf("�ٽ� �Է��Ͻʽÿ� : ");

				break;

			}

		}

		if (input == 1)

		{

			return 0;

		}

	}

}

int close_lib(struct book_info* book_list, struct user_info* user_list, int* total_book, int* total_user)

{

	FILE* save_book;

	FILE* save_user;

	FILE* save_borrow;

	int i, j;

	save_book = fopen("book_list.txt", "w");

	for (i = 0; i < *total_book; i++)

	{

		fputs("/\n", save_book);

		fputs(book_list[i].title, save_book);

		fputs("\n", save_book);

		fputs(book_list[i].auth, save_book);

		fputs("\n", save_book);

		fputs(book_list[i].publ, save_book);

		fputs("\n", save_book);

		fprintf(save_book, "%d", book_list[i].stat);

		fputs("\n", save_book);

		fprintf(save_book, "%d", book_list[i].book_num);

		fputs("\n", save_book);

	}

	fclose(save_book);

	i = 0;

	save_user = fopen("user_list.txt", "w");

	for (i = 0; i < *total_user; i++)

	{

		fputs("/\n", save_user);

		fputs(user_list[i].id, save_user);

		fputs("\n", save_user);

		fputs(user_list[i].pass, save_user);

		fputs("\n", save_user);

		fprintf(save_user, "%d", user_list[i].borr);

		fputs("\n", save_user);

	}

	fclose(save_user);

	i = 0;

	save_borrow = fopen("borrow_list.txt", "w");

	for (;;)

	{

		if (user_list[i].stat == 1)

		{

			if (user_list[i].borr > 0)

			{

				fputs("/", save_borrow);

				fputs(user_list[i].id, save_borrow);

				fputs("\n", save_borrow);

				for (j = 0; j < user_list[i].borr; j++)

				{

					fprintf(save_borrow, "%d", user_list[i].borrow_list[j]->book_num);

					fputs("\n", save_borrow);

				}

			}

			else

			{

				fputs("/", save_borrow);

				fputs(user_list[i].id, save_borrow);

				fputs("\n0\n", save_borrow);

			}

			i++;

			if (i > * total_user - 1)

			{

				break;

			}

		}

	}

	fclose(save_borrow);

	return 0;

}

