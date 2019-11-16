#include <stdio.h>

int main()
{
	double yard, cm;

	printf("yard? ");
	scanf_s("%lf", &yard);

	cm = 91.44 * yard;

	printf("%.001lf yard = %.001lf", yard, cm);
}