#include <stdio.h>

void fun(int n);
int main(void)
{
	int num;
	printf("������һ��������");
	scanf("%d", &num);
	fun(num);
	return 0;
}

void fun(int n)
{
	if (n == 1)
		printf("��3���ݴη�\n");
	while (n > 3 && n % 3 == 0)
		n /= 3;
	if (n == 3)
		printf("��3���ݴη�\n", n);
	else
		printf("����3���ݴη�\n", n);
}
