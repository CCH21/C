#include <stdio.h>

int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	int i;
	while (i < 4)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("%d\n", arr[i]);
	return 0;
}
