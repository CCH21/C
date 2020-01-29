#include <stdio.h>

int main(void)
{
	int arr[13] = {1, 2, 3, 4, 1, 3, 2, 4, 5, 7, 7, 6, 6};
	int num = 0;
	for (int i = 0; i < 13; i++)
		num ^= arr[i];
	printf("%d\n", num);
	return 0;
}
