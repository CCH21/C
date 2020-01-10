#include <stdio.h>

int main(void)
{
	// 假设该数为 x
	// 则 x + 100 = n^2, x + 100 + 168 = m^2
	// m^2 - n^2 = (m - n)(m + n) = 168
	// 令 m + n = i, m - n = j, 则 i * j = 168
	// m = (i + j)/2, n = (i - j)/2
	// 推导可得 i 和 j 均是大于等于 2 的偶数
	// i * j = 168, j >= 2, 则 1 < i < 168/2 + 1
	int x, i, j, m, n;
	for (i = 1; i < 85; i++)
		if (168 % i == 0)
		{
			j = 168 / i;
			if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
			{
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n * n - 100;
				printf("%d\n", x);
			}
		}
	return 0;
}
