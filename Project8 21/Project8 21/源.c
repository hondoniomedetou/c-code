#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MIN(x,y) (x<y)?x:y
struct one
{
	int x1, x2;
	int y1, y2;
}n[2];
int fun(struct one* n)
{
	for (int i = 0; i < 2; i++)
	{
		if ((n + i)->x1 != MIN((n + i)->x1, (n + i)->x2))
		{
			int tmp = (n + i)->x1;
			(n + i)->x1 = (n + i)->x2;
			(n + i)->x2 = tmp;
		}
	}
	if (n[0].x1>n[1].x2 || n[0].x2<n[1].x1 || n[0].y1>n[1].y2 || n[0].y2 < n[1].y1)//两长方形互不包含不相交
		return 0;
	else if (n[0].x1>n[1].x1&&n[0].x2<n[1].x2&&n[0].y1>n[1].y1&&n[0].y2 < n[1].y2)
		return 0;
	else if (n[0].x1<n[1].x1&&n[0].x2>n[1].x2&&n[0].y1<n[1].y1&&n[0].y2 > n[1].y2)//包含
	    return 0;
	else return 1;
}
int main()
{
	for (int i = 0; i < 2; i++)
	{
		printf("x1\ty1\tx2\ty2\n");
		scanf("%d%d%d%d", &(n + i)->x1, &(n + i)->y1, &(n + i)->x2,&(n + i)->y2);
		printf("(%d,%d)\t\t(%d,%d)\n", (n + i)->x1, (n + i)->y1, (n + i)->x2, (n + i)->y2);
	}
	printf("%d\n",fun(n));
	return 0;
}