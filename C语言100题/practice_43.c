#include <stdio.h>

int main(void)
{
	int arr[11] = {1, 4, 5, 8, 11, 13, 14, 20, 26, 28};
	int i, j, n, t1, t2;
	int end = arr[9];
	printf("原数组为：");
	for (i = 0; i < 10; i++)
		printf("%-3d", arr[i]);
	printf("\n请输入一个整数：");
	scanf("%d", &n);
	for (i = 0; i < 10; i++)
	{
		if (n > end)
			arr[10] = n;
		else
			for (i = 0; i < 10; i++)
				if (arr[i] > n)
				{
					t1 = arr[i];
					arr[i] = n;
					for (j = i + 1; j < 11; j++)
					{
						t2 = arr[j];
						arr[j] = t1;
						t1 = t2;
					}
					break;
				}
		break;
	}
	printf("插入整数之后的数组为：");
	for (i = 0; i < 11; i++)
		printf("%-3d", arr[i]);
	printf("\n");
	return 0;
}
