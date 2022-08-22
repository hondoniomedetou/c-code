#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<windows.h>
void fun(int N)
{
	char*p1 = (char*)malloc(sizeof(char));
	p1[0] = '0';
	char*p2 = (char*)malloc(sizeof(char));
	if (N == 0)
	{		
		printf("%c", p1[0]);
		return;
	}
	p2[0] = '1';
	char tmp;
	int n = 1;
	for (int j = 0; j < N-1; j++)
	{
		int ch = 0;
		int i;
		for (i = 0; i <n; i++)
		{
			if (p1[i] + p2[i] + ch - '0'>'9')
			{
				tmp = p2[i];
				p2[i] = p1[i] + p2[i] + ch - '0' - 10;
				p1[i] = tmp;
				ch = 1;
			}
			else
			{
				tmp = p2[i];
				p2[i] = p1[i] + p2[i] + ch - '0';
				p1[i] = tmp;
				ch = 0;
			}
		}
		if (i==n)
		{
			if (ch==1)
			{
				n++;
				char*p3 = (char*)realloc(p2, n);
				char*p4 = (char*)realloc(p1, n);
				if (p3 == NULL||p4==NULL)
				{
					perror("Wrong:");
					return;
				}
				p1 = p4;
				p2 = p3;
				p2[n - 1] = '1';
				p1[n - 1] = '0';
			}
		}
	}
	for (int i = n-1; i >= 0; i--)
		printf("%c", p2[i]);
}
int main()
{
	int N;
	scanf("%d", &N);
	fun(N);
	system("pause");
	return 0;
}