#define _CRT_SECURE_NO_WARNINGS 1
#define MAX(x,y) (x>y)?x:y
#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* fun(char*s, char*t)
{
	int len_s = strlen(s), len_t = strlen(t);
	int len = MAX(len_s, len_t);
	char*s1 = malloc(sizeof(char)*(len+2));
	char*t1 = malloc(sizeof(char)*(len+2));
	if (s1 == NULL || t1 == NULL)
		return NULL;
	else
	{
		t1[len + 1] = '\0';
		s1[len + 1] = '\0';
		for (int i = 0; i < len + 1; i++)
		{
			s1[i] = '0';
			t1[i] = '0';
		}
		int nums = len, numt = len;
		for (int i = len_s-1; i >= 0; i--, nums--)
		{
			*(s1 + nums) = *(s + i);
		}
		for (int i = len_t-1; i >= 0; i--, numt--)
		{
			*(t1 + numt) = *(t + i);
		}
		int ch = 0;
		for (int j = len; j >= 0; j--)
		{
			if (t1[j] + s1[j] + ch - '0' > '9')
			{
				t1[j] = t1[j] + s1[j] + ch - '0' - 10;
				ch = 1;
			}
			else
			{
				t1[j] = t1[j] + s1[j] + ch - '0';
				ch = 0;
			}
		}
		if (t1[0] == '0')
			return t1 + 1;
		else return t1;
	}
}
int main()
{
	char*s ="1";
	char*t = "99";
	printf("%s",fun(s, t));
	return 0;
}