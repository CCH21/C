#include <stdio.h>

void moveZeroes(int *arr, int arrSize);
int main(void)
{
	int nums[10] = {0, 0, 2, 1, 3, 0, 8, 4, 0, 6};
	moveZeroes(nums, 10);
	int i;
	for (i = 0; i < 9; i++)
		printf("%d ", nums[i]);
	printf("%d\n", nums[i]);
	return 0;
}

void moveZeroes(int *arr, int arrSize)
{
	int zeroNum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == 0)
			zeroNum++;
		else if (zeroNum != 0)
		{
			arr[i - zeroNum] = arr[i];
			arr[i] = 0;
		}
	}
}
