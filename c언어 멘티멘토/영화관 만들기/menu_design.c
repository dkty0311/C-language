#include "show_choice_menu.h"
#define SIZE 10

void start_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("��");

	printf("\n���   ");

	for (int a = 1; a <= SIZE; a++)
		printf("%d ", a);

	printf("���\n");

}

void end_menu()
{
	for (int i = 0; i <= SIZE + 5; i++)
		printf("��");
	printf("\n");

}

int choice_menu()
{
	int a=0;
	printf("1.����\n2.���\n3.����\n");
	printf("�޴��� �����Ͻÿ� : ");
	scanf_s("%d", &a);
	return a;
}