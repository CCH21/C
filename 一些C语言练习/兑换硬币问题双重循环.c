#include <stdio.h>
int main(void)
{
	int i = 0;
	int one, two, five;
	for (five = 0; five < 20; five++)
	{
		for (two = 0; two < 50; two++)
		{
			one = 60 - two - five;
			if (one + two * 2 + five * 5 == 100)
			{
				i++;
				printf ("兑换方案%2d：1分硬币%2d枚，2分硬币%2d枚，5分硬币%2d枚\n", i, one, two, five);
			}
		}
	}
	printf ("共有%d种兑换方案\n", i); 
	return 0; 
}
