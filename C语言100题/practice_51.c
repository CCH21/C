#include <stdio.h>

int main(void)
{
	int m, n;
	printf("请输入两个数字：");
	scanf("%d %d", &m, &n);
	if (m > n)
		printf("前者大\n");
	else if (m < n)
		printf("后者大\n");
	else
		printf("一样大\n");
	return 0;
}
