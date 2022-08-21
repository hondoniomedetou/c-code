#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<conio.h>
#define WIDE 10
#define LEN 10
#define SIZE 50
#define GAME1 1
#define GAME2 5
#define GAME3 8
enum deriction
{
	left = 'a',
	right = 'd',
	up = 'w',
	down = 's'
};
typedef struct board
{
	short board1[WIDE][LEN];//背景
	short**pa;
	short count;
	short game;
}S;
#define LEFT(X) X-1
#define RIGHT(X) X+1
#define UP(X) X-LEN
#define DOWN(X) X+LEN
IMAGE arr[5];
void initial()
{
	loadimage(&arr[0], _T("D:\\我的资料库\\Pictures\\1.jpg"),50,50);//墙
	loadimage(&arr[1], _T("D:\\我的资料库\\Pictures\\2.jpg"), 50, 50);//人
	loadimage(&arr[2], _T("D:\\我的资料库\\Pictures\\3.jpg"), 50, 50);//箱子1
	loadimage(&arr[3], _T("D:\\我的资料库\\Pictures\\4.jpg"), 50, 50);//目的地
	loadimage(&arr[4], _T("D:\\我的资料库\\Pictures\\7.jpg"), 50, 50);//箱子2
}
short* tell(S*ps,short*pp1, short*pp,short*pp0)
{
	for (int i = 0; i < ps->game; i++)
	{
		if (ps->pa[i] == pp)
		{
			if (*pp1 == 5)
			{
				return pp0;
			}
			else if (*pp1 == 3)
			{
				*pp1 = *pp;
				*pp = *pp0;
				*pp0 = 0;
				return pp;
			}
			else if (*pp1 == 0)
			{
				*pp1 = *pp;
				*pp = *pp0;
				*pp0 = 0;
				ps->count--;
				return pp;
			}
			else
			{
				return pp0;
			}
			break;
		}
	}
	if (*pp1  == 5)
	{
		return pp0;
	}
	else if (*pp1 == 3)
	{
		*pp1 = *pp;
		*pp = *pp0;
		*pp0 = 0;
		ps->count++;
		return pp;
	}
	else if (*pp1 == 0)
	{
		*pp1 = *pp;
		*pp = *pp0;
		*pp0 = 0;
		return pp;
	}
	else 
	{
		return pp0;
	}
}

short* tell_l(S*ps, short*pp, short*pp0)
{
	if (*pp == 0||*pp==3)
	{
		*pp = *pp0;
		*pp0 = 0;
		return pp;
	}
	else if (*pp == 1)
		return pp0;
	else
	{
		short*pp1 = LEFT(pp);
		return tell(ps, pp1,pp, pp0);
	}
}

short* tell_r(S*ps, short*pp, short*pp0)
{
	if (*pp == 0 || *pp == 3)
	{
		*pp = *pp0;
		*pp0 = 0;
		return pp;
	}
	else if (*pp == 1)
		return pp0;
	else
	{
		short*pp1 = RIGHT(pp);
		return tell(ps, pp1, pp, pp0);
	}
}
short* tell_u(S*ps, short*pp, short*pp0)
{
	if (*pp == 0 || *pp == 3)
	{
		*pp = *pp0;
		*pp0 = 0;
		return pp;
	}
	else if (*pp == 1)
		return pp0;
	else
	{
		short*pp1 = UP(pp);
		return tell(ps, pp1, pp, pp0);
	}
}
short* tell_d(S*ps, short*pp, short*pp0)
{
	if (*pp == 0 || *pp == 3)
	{
		*pp = *pp0;
		*pp0 = 0;
		return pp;
	}
	else if (*pp == 1)
		return pp0;
	else
	{
		short*pp1 = DOWN(pp);
		return tell(ps, pp1, pp, pp0);
	}
}
short* people_move(S*ps, short*pp)
{
	int c = _getch();
	short*pp1;
	switch (c)
	{
	case left:
	{
				 pp1 = LEFT(pp);
				 pp = tell_l(ps,pp1, pp);
				 return pp;
				 break;
	}
	case right:
	{
				  pp1 = RIGHT(pp);
				  pp = tell_r(ps,pp1, pp);
				  return pp;
				  break;
	}
	case up:
	{
			   pp1 = UP(pp);
			   pp = tell_u(ps,pp1, pp);
			   return pp;
			   break;
	}
	case down:
	{
				 pp1 = DOWN(pp);
				 pp = tell_d(ps,pp1, pp);
				 return pp;
				 break;
	}
	default:
	{
			   return pp;
			   break;
	}
	}
}

void show(S*ps)
{
	clearrectangle(0, 0, SIZE*LEN, SIZE*WIDE);
	for (int x = 0; x < WIDE; x++)
	{
		for (int y = 0; y < LEN; y++)
		{
			switch (ps->board1[x][y])
			{
			case 1:
			{
					  putimage(SIZE*y, SIZE*x, &arr[0]);//wall
					  break;
			}
			case 3:
			{
					  putimage(SIZE*y, SIZE*x, &arr[3]);//des
					  break;
			}
			case 5:
			{
					  putimage(SIZE*y, SIZE*x, &arr[2]);//box
					  break;
			}
			case 9:
			{
					  putimage(SIZE*y, SIZE*x, &arr[1]);//human
					  break;
			}
			}
		}
	}
}

void game1()
{
	short*pbox[GAME1];
	S s = 
	{ 
		{
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1,//1 墙体
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,//3 des
			1, 0, 0, 0, 0, 3, 0, 0, 0, 1,//5 box
			1, 0, 0, 0, 0, 5, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		},
		pbox,
	    0 ,
		GAME1
	};
	int i = 0;
		for (int x = 0; x < WIDE; x++)
		{
			for (int y = 0; y < LEN; y++)
			{
				if (s.board1[x][y] == 3)
				{
					pbox[i] = &s.board1[x][y];
					i++;
				}
			}
			if (i == GAME1)
				break;
		}
	s.board1[4][5] = 9;//确定人的位置
	short* pp = &s.board1[4][5];
	S*ps = &s;
	show(ps);
	while (s.count < GAME1)
	{
		pp = people_move(ps, pp);
		int j = 0;
		while (j <i&&*(pbox[j]) == 0)
		{
			*pbox[j] = 3;
			j++;
		}
		show(ps);
		Sleep(200);
	}
}

void game2()
{
	short*pbox[GAME2];
	S s =
	{
		{
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1,//1 墙体
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,//3 des
			1, 0, 0, 0, 0, 3, 0, 0, 0, 1,//5 box
			1, 0, 0, 0, 0, 5, 5, 0, 0, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 3, 1, 0, 0, 0, 0, 0, 0, 1,
			1, 5, 0, 0, 0, 5, 0, 3, 0, 1,
			1, 0, 0, 0, 5, 3, 3, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		},
		pbox,
		0,
		GAME2
	};
	int i = 0;
	for (int x = 0; x < WIDE; x++)
	{
		for (int y = 0; y < LEN; y++)
		{
			if (s.board1[x][y] == 3)
			{
				pbox[i] = &s.board1[x][y];
				i++;
			}
		}
		if (i == GAME2)
			break;
	}
	s.board1[4][5] = 9;//确定人的位置
	short* pp = &s.board1[4][5];
	S*ps = &s;
	show(ps);
	while (s.count < GAME2)
	{
		pp = people_move(ps, pp);
		int j = 0;
		while (j <i)
		{
			if (*pbox[j]==0)
			*pbox[j] = 3;
			j++;
		}
		*pp = 9;
		show(ps);
		Sleep(200);
	}
}