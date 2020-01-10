#include <stdio.h>

int main (void)
{
	int i, num;
	int count = 0;
	scanf("%d", &num);
	for (i = 2; i <= num; i++)
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
