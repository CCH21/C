#include <stdio.h>

int fun(int n);
int main(void)
{
	printf("%d\n", fun(20));
	return 0;
}

int fun(int n)
{
	if (n == 0)
		return 1;
	else
		return fun(n-1) * 2;
}
