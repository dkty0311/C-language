#include <stdio.h>

long factorial(int n)
{
	printf("%d!=%d*%d!\n", n,n,n-1);
	if (n <= 1) 
	{ 
		return 1; 
	}	
	else 
	{ 

		return n * factorial(n - 1); 
	}	
}


void main() {
	int n;
	printf("정수 입력: ");
	scanf_s("%d", &n);	
	printf("%d!은 %d입니다.", n, factorial(n));
}

