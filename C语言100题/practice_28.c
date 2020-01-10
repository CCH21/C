#include <stdio.h>

int main(void)
{
	int i, t;
	float s = 0, a = 2, b = 1;
	for (i = 1; i <= 20; i++)
	{
		s += a/b;
		t = a;
		a += b;
		b = t;
	}
	printf("%f\n", s);
	return 0;
}
