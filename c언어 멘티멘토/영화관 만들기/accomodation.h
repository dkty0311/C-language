#pragma once
#define SIZE 10

void accomodation(int seats[SIZE][SIZE], int login_inform);
void accomodation_cancel(int seats[SIZE][SIZE], int login_inform);



struct accomodation                 //���� ��ȭ�� �¼�
{
	int seats[10][10];
};