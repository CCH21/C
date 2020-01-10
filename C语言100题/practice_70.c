#include <stdio.h>

double fun(int n);
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%lf\n", fun(n));
	return 0;
}

double fun(int n)
{
	double s = 0;
	double i;
	if (n % 2 == 0)
		for (i = 2; i <= n; i += 2)
			s += 1 / i;
	else
		for (i = 1; i <= n; i += 2)
			s += 1 / i;
	return s;
}
