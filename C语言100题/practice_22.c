#include <stdio.h>

int main(void)
{
	int a, n, t;
	int s = 0;
	scanf("%d %d", &a, &n);
	t = a;
	while (n > 0)
	{
		printf("%d", t);
		s += t;
		a *= 10;
		t += a;
		n--;
		if (n != 0)
			printf("+");
	}
	printf("=%d", s);
	return 0;
}
