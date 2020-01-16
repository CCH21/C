#include <stdio.h>
#define N 128

void fun(int *arr, int arrLength);
int main(void)
{
	int nums[11] = {0, 0, 2, 8, 0, 3, 7, 2, 0, 9, 13};
	int len = sizeof(nums) / sizeof(nums[0]);
	fun(nums, len);
	return 0;
}

void fun(int *arr, int arrLength)
{
	int ret[N] = {0};
	int i, j;
	j = 0;
	for (i = 0; i < arrLength; i++)
	{
		if (arr[i] != 0)
		{
			ret[j] = arr[i];
			j++;
		}
	}
	for (; j < arrLength; j++)
		ret[j] = 0;
	for (i = 0; i < arrLength - 1; i++)
		printf("%d ", ret[i]);
	printf("%d", ret[i]);
}
