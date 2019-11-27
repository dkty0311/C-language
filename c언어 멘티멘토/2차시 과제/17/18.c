#include <stdio.h>

int main()
{
	char a[100];
	int num;
	printf("문자열 입력>>");
	fgets(a, 100, stdin);
	printf("정수입력");
	scanf_s("%d", &num);

	for (int i = strlen(a) ; i >= num-1; i--) {
		printf("%c", a[i]);
	}
	return 0;
}
