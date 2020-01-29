#include <stdio.h>

int main(void)
{
	unsigned int n;
	scanf("%d", &n);
	int num, t;
	for (int i = 31; i >= 0; i--)
	{
		num = n;
		num = num >> (31 - i);
		t = num & 1;
		printf("%d", t);
	}
	return 0;
}
