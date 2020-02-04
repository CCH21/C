#include <stdio.h>

int main(void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int m, i, j;
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		int t = arr[9];
		for (j = 8; j >= 0; j--)
			arr[j + 1] = arr[j];
		arr[0] = t;
	}
	for (j = 0; j < 9; j++)
		printf("%d ", arr[j]);
	printf("%d\n", arr[j]);
	return 0;
}
