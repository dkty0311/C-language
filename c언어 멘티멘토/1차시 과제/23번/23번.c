#include <stdio.h>
int main()
{
	for(int x=1; x<100; x++)
	{
		if (x % 3 == 0 && x % 5 == 0)
		{
			printf("Â¦¸¸¼¼ ");
			

		}
		else if (x % 5 == 0)
		{
			printf("¸¸¼¼ ");
			
		}
		else if (x%3==0)
		{
			printf("Â¦ ");
			
		}
		else
		{
			printf("%d ", x);
			
		}
		
	}

}
