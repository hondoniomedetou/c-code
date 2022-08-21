#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#define WIDE 10
#define LEN 10
#define SIZE 50
#define GAME1 1
#define GAME2 5
#define GAME3 8

void initial();

enum deriction
{
	left = 'a',
	right = 'd',
	up = 'w',
	down = 's'
};
void game1();

void game2();

//void game3();