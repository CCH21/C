#include <stdio.h>

int main(void)
{
	int num, s, i;
	for (num = 2; num <= 1000; num++)
	{
		s = 0;
		for (i = 1; i < num; i++)
			if (num % i == 0)
				s += i;
		if (s == num)
			printf("%d\n", num);
	}
	return 0;
}
