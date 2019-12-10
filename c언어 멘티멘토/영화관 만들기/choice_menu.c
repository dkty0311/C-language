
int choice_menu()
{
	int a;
	printf("1.예약\n2.취소\n3.종료\n");
	printf("메뉴를 선택하시오 : ");
	scanf_s("%d", &a);
	return a;
}