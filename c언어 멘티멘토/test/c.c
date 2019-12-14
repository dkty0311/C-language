#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)warning pragma

struct book_info

{

	char title[41];

	char auth[31];

	char publ[31];

	int stat; // 도서 상태 식별. 0->도서관내 소장 1->대여중 2->이 번호는 책이 없음.

	int book_num; // 도서 번호

	struct user_info* user;

};

struct user_info

{

	char id[21];

	char pass[21];

	int borr; // 빌려간 책 수

	int stat; //회원 슬롯 식별. 0->빈 슬롯 1->차 있는 슬롯

	struct book_info* borrow_list[5];

	struct user_info* nextuser;

};

int lib_init_book(int* init, struct book_info* book_list, int* total_book);

int lib_init_user(int* init, struct user_info* user_list, int* total_user);

int lib_init_borrow(int* init, struct book_info* book_list, struct user_info* user_list, int* total_book, int* total_user);

int login_user(char* id, char* pass, struct user_info* user_list, struct user_info* session, int* total_user, int* user_key); // 0->관리자 1->관리자 아님 2->ID or 비번 틀림

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

	printf("도서관 정보를 불러오고 있습니다.. \n");

	lib_init_book(&init, book_list, &total_book);

	if (init == 0)

	{

		printf("도서 정보가 초기화되지 않았습니다. \n");

		return 0;

	}

	init = 0;

	lib_init_user(&init, user_list, &total_user);

	if (init == 0)

	{

		printf("사용자 정보가 초기화되지 않았습니다. \n");

		return 0;

	}

	lib_init_borrow(&init, book_list, user_list, &total_book, &total_user);

	if (init == 0)

	{

		printf("도서 대출 현황을 불러올 수 없었습니다. 계속 진행하시겠습니까? y/n :");

		input_string(c, 1);

		if (strcmp(c, "n") == 0)

		{

			printf("도서관이 종료되었습니다. \n");

			return 0;

		}

	}

	printf("도서관이 시작됩니다. \n");

	for (;;)

	{

		printf("사용자 정보를 확인해 주십시오. \n");

		printf("ID : ");

		input_string(str1, 20);

		printf("PASSWORD : ");

		input_string(str2, 20);

		login_user(str1, str2, user_list, &curr_user, &total_user, &user_key);

		if (user_key == 0)

		{

			printf("관리자로 로그인되었습니다. \n");

			for (;;)

			{

				printf("  수행하려는 작업을 선택하십시오. \n");

				printf("  1. 도서 추가 \n  2. 도서 삭제\n  3. 도서 정보 변경\n  4. 도서 검색\n  5. 도서 조회\n  6. 회원 추가\n  7. 회원 삭제\n  8. 회원 정보 조회\n  9. 도서 대출\n  10. 도서 반납\n  11. 관리자 종료\n  12. 도서관 종료  : ");

				input_num(&i, 2);

				if (i == 1)

				{

					if (total_book > 100)

					{

						printf("총 장서 수가 허용 가능한 수를 넘어섰습니다. \n");

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

						printf("책이 한 권도 없습니다. \n");

					}

					else

					{

						delete_book(book_list, &total_book, user_list, &total_user);

						total_book = total_book - 1;

					}

				}

				else if (i == 3)

				{

					printf("변경하려는 도서의 일련번호를 입력하십시오. : ");

					input_num(&j, 8);

					change_book(book_list, &j, &total_book);



				}

				else if (i == 4)

				{

					search_book(book_list, &total_book);

				}

				else if (i == 5)

				{

					printf("도서 목록을 출력합니다. 일련번호 순으로 출력됩니다. \n");

					arrange_book(book_list, &total_book);

				}

				else if (i == 6) //회원 추가

				{

					if (total_user > 99)

					{

						printf("더 이상 회원을 추가할 수 없습니다.");

					}

					else

					{

						add_user(user_list, &total_user);

					}

				}

				else if (i == 7) //회원 삭제

				{

					delete_user(user_list, &total_user, book_list, &total_book);

				}

				else if (i == 8)//회원 대출 현황 조회

				{

					print_user(user_list, &total_user);

				}

				else if (i == 9)//도서 대출

				{

					borrow_book(book_list, &curr_user, &total_book);

				}

				else if (i == 10)//도서 반납

				{

					return_book(book_list, &curr_user);

				}

				else if (i == 11)

				{

					printf("관리자 모드가 종료됩니다. \n");

					break;

				}

				else if (i == 12)

				{

					printf("도서관이 종료됩니다. 정보를 저장하는 동안 잠시 기다리십시오. \n");

					close_lib(book_list, user_list, &total_book, &total_user);

					printf("도서관이 종료되었습니다. \n");

					return 0;

				}

				else

				{

					printf("잘못된 명령입니다. \n");

				}

			}

		}//관리자 편집 끝남. 일반 사용자 편집 차례

		else if (user_key != 0 && user_key > 0)

		{

			printf("일반 사용자로 로그인되었습니다. \n");

			for (;;)

			{

				printf("  수행하려는 작업을 선택하십시오. \n");

				printf("  1. 도서 검색\n  2. 도서 대출\n  3. 도서 반납\n  4. 대출 현황 조회\n  5. 종료 : ");

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

						printf("현재 대출중인 도서는 없습니다. \n");

					}

					else

					{

						printf("대출중인 도서 목록은 다음과 같습니다. \n");

						for (j = 0; j < curr_user.borr; j++)

						{

							printf("title : %s \n", curr_user.borrow_list[j]->title);

						}

					}

				}

				else if (i == 5)

				{

					printf("로그아웃 합니다. \n");

					user_list[user_key] = curr_user;

					break;

				}

				else

				{

					printf("잘못된 명령입니다. \n");

				}

			}

		}

		else if (user_key == -1)

		{

			printf("비밀번호가 일치하지 않습니다. \n");

		}

		else if (user_key == -2)

		{

			printf("입력한 ID 가 존재하지 않습니다. \n");

		}

		else

		{

			printf("사용자 정보가 일치하지 않습니다. \n");

		}

		printf("도서관을 계속 이용하시겠습니까? y/n : ");

		input_string(c, 1);

		if (strcmp(c, "n") == 0)

		{

			printf("도서관을 종료합니다. 정보를 저장하는 동안 잠시 기다려 주십시오. \n");

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

	printf("책의 정보를 입력해 주십시오. \n");

	for (;;)

	{

		printf("제목 : ");

		input_string(str1, 40);

		for (i = 0; i < *total_book; i++)

		{

			if (strcmp(str1, book_list[i].title) == 0)

			{

				printf("일치하는 도서명이 있습니다. 추가할 수 없습니다. \n");

				return 0;

			}

		}

		strcpy(book_list[book_locat].title, str1);

		break;

	}

	for (;;)

	{

		printf("저자 : ");

		input_string(str2, 30);

		strcpy(book_list[book_locat].auth, str2);

		break;

	}

	for (;;)

	{

		printf("출판사 : ");

		input_string(str3, 30);

		strcpy(book_list[book_locat].publ, str3);

		break;

	}

	count = 0;

	for (;;)

	{

		printf("일련번호를 입력하십시오. 단, 0 은 입력할 수 없습니다. : ");

		input_num(&j, 8);

		for (i = 0; i < *total_book; i++)

		{

			if (j == book_list[i].book_num || j == 0)

			{

				printf("사용할 수 없는 번호입니다. \n");

				printf("계속 입력하시겠습니까? y/n :");

				input_string(c, 1);

				if (strcmp(c, "n") == 0)

				{

					printf("정보 입력을 중단했습니다. \n");

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

	printf("  삭제 방법을 선택해 주십시오.\n  1) 일련번호\n  2) 제목 : ");

	input_num(&j, 1);

	if (j == 1)

	{

		printf("삭제하려는 책의 일련번호를 입력하십시오. : ");

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

				printf("책이 삭제되었습니다. \n");

				break;

			}

			else if (k == book_list[i].book_num && book_list[i].stat == 1)

			{

				printf("대출중인 책은 지울 수 없습니다. \n");

				return 0;

			}

		}

		if (i == *total_book)

		{

			printf("일치하는 번호의 책이 없습니다. \n");

			return 0;

		}

	}

	else if (j == 2)

	{

		printf("삭제하려는 책의 제목을 입력하십시오. : ");

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

				printf("책이 삭제되었습니다. \n");

				break;

			}

			else if (strcmp(str, book_list[i].title) == 0 && book_list[i].stat == 1)

			{

				printf("대출중인 책은 지울 수 없습니다. \n");

				return 0;

			}

		}

		if (i == *total_book)

		{

			printf("일치하는 제목의 책이 없습니다. \n");

			return 0;

		}

	}

	else

	{

		printf("잘못된 입력입니다. \n");

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

		printf("일치하는 일련번호의 책이 없습니다. \n");

		return 0;

	}

	printf("변경하려는 책의 정보를 입력합니다. \n");

	for (;;)

	{

		printf("제목 : ");

		input_string(str, 40);

		strcpy(book_list[change].title, str);

		break;

	}

	for (;;)

	{

		printf("저자 : ");

		input_string(str, 30);

		strcpy(book_list[change].auth, str);

		break;

	}

	for (;;)

	{

		printf("출판사 : ");

		input_string(str, 30);

		strcpy(book_list[change].publ, str);

		break;

	}

	for (;;)

	{

		printf("일련번호 : ");

		input_num(&num, 8);

		for (i = 0; i < *total_book; i++)

		{

			if (num == book_list[i].book_num && i != change)

			{

				printf("동일한 일련번호의 책이 있습니다. \n");

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

	printf("다음 중 무엇으로 검색하겠습니까? \n 1. 제목\n 2. 저자\n 3. 출판사\n 4. 일련번호 : ");

	input_num(&i, 1);

	if (i == 1)

	{

		printf("검색 키워드를 입력하십시오 : ");

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

		printf("검색 키워드를 입력하십시오 : ");

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

		printf("검색 키워드를 입력하십시오 : ");

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

		printf("몇 번 책을 검색하겠습니까? : ");

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

		printf("잘못된 명령입니다. \n");

		return 0;

	}

	if (result > 0)

	{

		printf("검색이 완료되었습니다. \n");

		return 0;

	}

	else

	{

		printf("일치하는 검색어가 없습니다. \n");

		return 0;

	}

}

void print_book(struct book_info* book)

{

	int i;

	char c;

	int j = 0;

	printf("제목 : %s \n", book->title);

	printf("저자 : %s \n", book->auth);

	printf("출판사 : %s \n", book->publ);

	printf("일련번호 : %d \n", book->book_num);

	if (book->stat == 1)

	{

		printf("   대출 여부 : 대출중 / 대출한 사용자 : %s \n ", book->user->id);

	}

	else

	{

		printf("   대출 여부 : 도서관내 소장 \n");

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

	printf("추가하려는 사용자의 정보를 입력하십시오. ID 와 비밀번호는 20자 아래로만 입력됩니다. \n");

	printf("아이디 : ");

	input_string(str1, 20);

	printf("비밀번호 : ");

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

			printf("정보입력이 완료되었습니다. \n");

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

		printf("정보입력이 완료되었습니다. \n");

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

	printf("삭제하려는 사용자의 정보를 입력하십시오. \n");

	printf("아이디 : ");

	input_string(str1, 20);

	printf("비밀번호 : ");

	input_string(str2, 20);

	for (i = 0; i < *total_user; i++)

	{

		if (strcmp(user_list[i].id, str1) == 0)

		{

			if (strcmp(user_list[i].pass, str2) == 0)

			{

				if (user_list[i].borr > 0)

				{

					printf("대출 도서가 있는 사용자는 삭제할 수 없습니다.  \n");

					return 0;

				}

				user_list[i].stat = 0;

				printf("사용자 정보가 삭제되었습니다. \n");

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

				printf("비밀번호가 일치하지 않습니다. \n");

				return 0;

			}

		}

	}

	if (result == 0)

	{

		printf("일치하는 사용자 정보가 없습니다. \n");

	}

	return 0;

}

int print_user(struct user_info* user_list, int* total_user)

{

	int i, j;

	char str1[42];

	printf("조회하려는 회원의 ID 를 입력하십시오. : ");

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

					printf("해당 회원의 대출 현황은 아래와 같습니다. \n");

					for (j = 0; j < user_list[i].borr; j++)

					{

						printf("대출도서 %d : %s \n", j + 1, user_list[i].borrow_list[j]->title);

					}

					return 0;

					break;

				}

				else

				{

					printf("해당 회원이 대출중인 도서는 없습니다. \n");

					return 0;

				}

			}

		}

	}

	if (i == *total_user)

	{

		printf("ID 가 일치하는 사용자가 존재하지 않습니다. \n");

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

		printf("대여 가능한 책 수를 초과했으므로 더 이상은 빌릴 수 없습니다. \n");

		return 0;

	}

	else

	{

		printf("무엇을 통해 빌리겠습니까? \n 1. 제목 \n 2. 일련번호 : ");

		input_num(&i, 1);

		if (i == 1)

		{

			printf("빌리려는 책의 제목을 입력하십시오. : ");

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

						printf("대출 도서명 : %s \n", book_list[j].title);

						printf("대출 사용자 : %s \n", curr_user->id);

						return 0;

					}

					else if (book_list[j].stat == 1)

					{

						printf("이미 대여중인 책이라 빌릴 수 없습니다. \n");

						return 0;

					}

					else

					{

						printf("해당 도서는 존재하지 않는 상태입니다. \n");

						return 0;

					}

				}

			}

			if (j == *total_book)

			{

				printf("일치하는 도서명이 없습니다. \n");

				return 0;

			}

		}

		else if (i == 2)

		{

			printf("빌리려는 책의 번호를 입력하십시오 : ");

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

						printf("대출 도서명 : %s \n", book_list[j].title);

						printf("대출 사용자 : %s \n", curr_user->id);

						return 0;

					}

					else if (book_list[i].stat == 1)

					{

						printf("이미 대여중인 책이라 빌릴 수 없습니다. \n");

						return 0;

					}

					else

					{

						printf("해당 도서는 존재하지 않는 상태입니다. \n");

						return 0;

					}

				}

			}

			if (j == *total_book)

			{

				printf("일치하는 도서명이 없습니다. \n");

				return 0;

			}

		}

		else

		{

			printf("잘못된 명령입니다. \n");

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

		printf("반납할 수 있는 책이 없습니다. \n");

		return 0;

	}

	else

	{

		printf("무엇으로 반납하겠습니까? \n1. 제목 \n2. 일련번호 : ");

		input_num(&i, 1);

		if (i == 1)

		{

			printf("반납하려는 책의 제목을 입력하십시오 : ");

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

					printf("책이 반납되었습니다. \n");

					return 0;

				}

			}

			if (return_temp == curr_user->borr)

			{

				printf("사용자가 대출한 책이 아닙니다. \n");

				return 0;

			}

		}

		else if (i == 2)

		{

			printf("반납하려는 책의 번호를 입력하십시오 : ");

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

					printf("책이 반납되었습니다. \n");

					return 0;

				}

			}

			if (return_temp == curr_user->borr)

			{

				printf("사용자가 대출한 책이 아닙니다. \n");

				return 0;

			}

		}

		else

		{

			printf("잘못된 입력입니다. \n");

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

		printf("입력 범위가 너무 큽니다. 함수 설정을 확인하십시오. \n");

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

			printf("입력 범위를 초과했습니다. \n");

			while (getchar() != '\n')

			{
			}

			printf("다시 입력하십시오 : ");

			continue;

		}

		for (i = 0; i < input_size; i++)

		{

			if (str[i] < 48 || str[i]>57)

			{

				if (str[i] != '\n')

				{

					printf("숫자만 입력할 수 있습니다. \n");

					printf("다시 입력하십시오 : ");

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

				printf("입력 가능한 범위를 넘어섰습니다. %d 글자 이상 입력하지 마십시오. \n", form);

				result[0] = '\0';

				while (getchar() != '\n')

				{
				}

				printf("다시 입력하십시오 : ");

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

