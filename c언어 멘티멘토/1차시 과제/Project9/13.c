#include <stdio.h>
int main()
{
	int i=0, score, sum = 0;
	double avg = 0;

		do
		{
			printf("���� �Է� (0~100�̿��� �� �Է�����>>");
			scanf_s("%d", &score);
			sum += score;
			i++;
		} while (score<100||score<0);
		
	avg = sum / i;
	printf("�հ�: %d/���: %lf",sum,avg);

	return 0;
}