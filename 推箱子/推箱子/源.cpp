#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<conio.h>
int main()
{
	initgraph(WIDE*SIZE,LEN*SIZE);	// ������ͼ����
	int flag = 1;
	initial();
	while (flag)
	{
		game1();//�ؿ�һ�������ַ� �˶� ���Ӷ�
		game2();
		//game3();
		RECT r = { 0, 0, SIZE*WIDE, SIZE*LEN };
		drawtext(_T("�Ƿ�ص���һ�أ�Y/N��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		int m = _getch();
		if (m == 'N')
			flag = 0;
	}
	closegraph();
	return 0;
}