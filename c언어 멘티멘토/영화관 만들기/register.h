#pragma once
#define INFORM 5
#define SIZE 10
int login_or_register();


struct information
{
	char userid[15];								//구조체 선언
	char userpw[15];
	int age;
	char name[30];
	int user_max1;
	char seats[10][10];
	int login_try;
};



