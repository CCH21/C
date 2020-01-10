#include <stdio.h>

int climbStairs(int n);
int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d\n", climbStairs(num));
	return 0;
}

int climbStairs(int n)
{
	if (n == 1)
		return 1;
	int a, b, c, i;
	a = 1;
	b = 2;
	for (i = 3; i < n + 1; i++)
	{
		c = a + b;
		a = b; 
		b = c;
	}
	return b;
}
