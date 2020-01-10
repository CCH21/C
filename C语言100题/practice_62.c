#include <stdio.h>

void fun(int *array, int n);
int main(void)
{
	int arr[10] = {5, 2, 3, 7, 6, 1, 9, 8, 10, 4};
	int i;
	for (i = 0; i < 10; i++)
		printf("%3d", arr[i]);
	printf("\n");
	fun(arr, 10);
	for (i = 0; i < 10; i++)
		printf("%3d", arr[i]);
	return 0;
}

void fun(int *array, int n)
{
	int i, a, b;
	int max = array[0], min = array[0];
	for (i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			a = i;
		}
		if (array[i] < min)
		{
			min = array[i];
			b = i;
		}
	}
	array[b] = array[n - 1];
	array[n - 1] = min;
	array[a] = array[0];
	array[0] = max;
}
