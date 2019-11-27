#include <stdio.h>
#include <string.h>

int main()
{
	char st[1001];
	int len, i;

	scanf_s("%s", st,100);

	len = strlen(st);

	for (i = 0; i < len; i++) 
	{
		if (st[i] >= 'a' && st[i] <= 'z')
		{
			st[i] -= 32;
		}
		else
			st[i] = 0;
	}
	for (i = 0; i < len; i++) {
		printf("%c", st[i]);
	}
	return 0;

}