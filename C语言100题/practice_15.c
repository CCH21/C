#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, a, b, c, sum;
	for (num = 100; num < 1000; num++)
	{
		a = num / 100;
		b = num % 100 / 10;
		c = num % 10;
		sum = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (num == sum)
			printf("%d\n", num);
	}
	return 0;
}
