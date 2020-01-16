#include <stdio.h>

int main(void)
{
	printf("请输入一个长度为10的数组：\n");
	int arr1[10], arr2[10];
	int i, j, k;
	j = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &arr1[i]);
	printf("请输入移动量：");
	scanf("%d", &k);
	for (i = 10 - k; i < 10; i++)
	{
		arr2[j] = arr1[i];
		j++;
	}
	for (i = 0; i < 10 - k; i++)
	{
		arr2[j] = arr1[i];
		j++;
	}
	for (j = 0; j < 10; j++)
		printf("%d ", arr2[j]);
	return 0;
}
