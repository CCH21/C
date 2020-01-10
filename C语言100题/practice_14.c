#include <stdio.h>

int main (void)
{
	int i;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		int j;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			    break;
		}
		if (j == i)
		{
			printf("%d\n", i);
			count++;
		}
	}
	printf("¸öÊýÎª%d\n", count);
	return 0;
}
