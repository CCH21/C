#include <stdio.h>

int main(void)
{
	int n;
	for (int i = 0; i < 7; i++)
	{
		printf("请输入一个1-50之间的数字：");
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
