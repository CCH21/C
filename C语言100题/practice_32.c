#include <stdio.h>

void fun(int n);
int main(void)
{
	printf("������5���ַ���");
	fun(5);
	printf("\n");
	return 0;
}

void fun(int n)
{
	char next;
	if (n <= 1)
	{
		next = getchar();
		putchar(next);
	}
	else
	{
		next = getchar();
		fun(n-1);
		putchar(next);
	}
}
