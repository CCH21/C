#include <stdio.h>

int main(void)
{
	int num, num_square;
	scanf("%d", &num);
	num_square = num * num;
	printf("%d\n", num_square);
	do
	{
		scanf("%d", &num);
		num_square = num * num;
		printf("%d\n", num_square);
	} while (num_square >= 50);
	return 0;
}
