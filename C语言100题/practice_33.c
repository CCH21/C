#include <stdio.h>

int age(int n);
int main(void)
{
	printf("%d", age(5));
	return 0;
}

int age(int n)
{
	if (n == 1)
		return 10;
	else
		return age(n-1) + 2;
}
