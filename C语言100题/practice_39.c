#include <stdio.h>

int main (void)
{
	int i;
	for (i = 2; i <= 100; i++)
	{
		int j;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			    break;
		}
		if (j == i)
			printf("%d\n", i);
	}
	return 0;
}
