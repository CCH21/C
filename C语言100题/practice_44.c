#include <stdio.h>

int main(void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i = 9;
	while (i >= 0)
	{
		printf("%3d", arr[i]);
		i--;
	}
	return 0;
}
