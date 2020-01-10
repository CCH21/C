#include <stdio.h>

int hammingWeight(int n);
int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d\n", hammingWeight(num));
	return 0;
}

int hammingWeight(int n)
{
	int count = 0;
	while (n != 0)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}
