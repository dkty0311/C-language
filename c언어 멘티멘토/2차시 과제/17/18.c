#include <stdio.h>

int main()
{
	char a[100];
	int num;
	printf("���ڿ� �Է�>>");
	fgets(a, 100, stdin);
	printf("�����Է�");
	scanf_s("%d", &num);

	for (int i = strlen(a) ; i >= num-1; i--) {
		printf("%c", a[i]);
	}
	return 0;
}
