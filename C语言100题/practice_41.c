#include <stdio.h>
#define N 10

int main(void)
{
	int a;
	int nums[N];
	for (a = 0; a < N; a++)
		scanf("%d", &nums[a]);
	int i, j, t;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				t = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = t;
			}
		}
	}
	for (a = 0; a < N; a++)
		printf ("%d ", nums[a]);
	return 0;
}
