#include <stdio.h>

int main(void)
{
	int day = 9, x1 = 0, x2 = 1;
	while (day > 0)
	{
		x1 = (x2 + 1) * 2;
		x2 = x1;
		day--;
	}
	printf("%d\n", x1);
	return 0;
}
