#include <stdio.h>
int main()
{
	for(int x=1; x<100; x++)
	{
		if (x % 3 == 0 && x % 5 == 0)
		{
			printf("¦���� ");
			

		}
		else if (x % 5 == 0)
		{
			printf("���� ");
			
		}
		else if (x%3==0)
		{
			printf("¦ ");
			
		}
		else
		{
			printf("%d ", x);
			
		}
		
	}

}
