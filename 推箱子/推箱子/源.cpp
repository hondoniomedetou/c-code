#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<conio.h>
int main()
{
	initgraph(WIDE*SIZE,LEN*SIZE);	// 创建绘图窗口
	int flag = 1;
	initial();
	while (flag)
	{
		game1();//关卡一：输入字符 人动 箱子动
		game2();
		//game3();
		RECT r = { 0, 0, SIZE*WIDE, SIZE*LEN };
		drawtext(_T("是否回到第一关（Y/N）"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		int m = _getch();
		if (m == 'N')
			flag = 0;
	}
	closegraph();
	return 0;
}