#include <stdio.h>
#define N 10

int main(void)
{
	int n, i;
	scanf("%d", &n);
	int arr1[N] = {0}, arr2[N] = {0};
	for (i = 0; i <= n; i++)
		arr1[i] = i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr2[i]);
	for (i = 0; i < n; i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("%d\n", arr1[i]);
			break;
		}
		if (i == n)
			printf("%d\n", arr1[i + 1]);
	}
	return 0;
}
