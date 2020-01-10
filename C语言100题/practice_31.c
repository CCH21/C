#include <stdio.h>

int fact(int n);
int main(void)
{
	printf("%d", fact(5));
	return 0;
}

int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
