#ifndef STRUCT_H
#define STRUCT_H

struct inform
{
	char user_information[5][2][10];       // ID, PW�迭 ����(�ִ� ���ڼ�:9����)
	int  user_max, rep_check ;                   // user_max:���� ȸ������, rep_check:�ߺ�üũ ���
	char userid[10], userpw[10];
};

#endif