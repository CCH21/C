#include <stdio.h>

int main(void)
{
	int n, a, b, c, d, e;
	scanf("%d", &n);
	a = n / 10000;
	b = n % 10000 / 1000;
	c = n % 1000 / 100;
	d = n % 100 / 10;
	e = n % 10;
	if (a == e && b == d)
		printf("%d�ǻ�����\n", n);
	else
		printf("%d���ǻ�����\n", n);
	return 0;
}
