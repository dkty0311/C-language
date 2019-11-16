#include <stdio.h>

main() 
{
	int a, b, big, small, mok, remain, gcm, lcm;
	scanf_s("%d %d", &a, &b);
	if (a > b)                  //입력받은 두 수를 비교하여 큰 수와 작은 수를 지정
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
			printf("최대공약수 = %d / 최소 공배수 = %d", gcm, lcm);
			break; //출력하고 종료
		}
		else 
		{
			big = small;
			small = remain;
		}
	}
}
