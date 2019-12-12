#ifndef STRUCT_H
#define STRUCT_H

struct inform
{
	char user_information[5][2][10];       // ID, PW배열 선언(최대 글자수:9이하)
	int  user_max, rep_check ;                   // user_max:현재 회원숫자, rep_check:중복체크 상수
	char userid[10], userpw[10];
};

#endif