/* 题目：把1元纸币兑换成1分、2分、5分的硬币共60枚，请列出所有兑换方案 */
#include <stdio.h>
int main (void)
{
	int i = 0; 
	int one, two, five; 
	for (one = 0; one <= 60; one++)
	{
		for (two = 0; two <= 50; two++)
		{
			for (five = 0; five <= 20; five++)
			{
				if ((one * 1 + two * 2 + five * 5 == 100) && (one + two + five == 60))
				{
					i++; 
					printf ("兑换方案%2d：1分硬币%2d枚，2分硬币%2d枚，5分硬币%2d枚\n", i, one, two, five); 
				}
			}
		}
	}
	printf ("共有%d种兑换方案\n", i); 
	return 0; 
}
