#include <stdio.h>
int main()
{
	int i=0, score, sum = 0;
	double avg = 0;

		do
		{
			printf("점수 입력 (0~100이외의 수 입력종료>>");
			scanf_s("%d", &score);
			sum += score;
			i++;
		} while (score<100||score<0);
		
	avg = sum / i;
	printf("합계: %d/평균: %lf",sum,avg);

	return 0;
}