#include <stdio.h>

main() 
{
	int a, b, big, small, mok, remain, gcm, lcm;
	scanf_s("%d %d", &a, &b);
	if (a > b)                  //�Է¹��� �� ���� ���Ͽ� ū ���� ���� ���� ����
	{
		big = a;
		small = b;
	}
	else 
	{
		big = b;
		small = a;
	}
	while (1) 
	{
		mok = big / small;
		remain = big - mok * small;
		if (remain == 0) 
		{ 
			gcm = small;
			lcm = a * b / gcm;
			printf("�ִ����� = %d / �ּ� ����� = %d", gcm, lcm);
			break; //����ϰ� ����
		}
		else 
		{
			big = small;
			small = remain;
		}
	}
}
