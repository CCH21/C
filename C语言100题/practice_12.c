#include <stdio.h>

void fun(int n);
int main(void)
{
	int num;
	printf("请输入一个整数：");
	scanf("%d", &num);
	fun(num);
	return 0;
}

void fun(int n)
{
	if (n == 1)
		printf("是3的幂次方\n");
	while (n > 3 && n % 3 == 0)
		n /= 3;
	if (n == 3)
		printf("是3的幂次方\n", n);
	else
		printf("不是3的幂次方\n", n);
}
