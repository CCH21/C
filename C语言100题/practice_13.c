#include <stdio.h>

int fibo(int n);
int main(void)
{
	int month, n;
	printf("�������·�����");
	scanf("%d", &month);
	n = 2 * fibo(month);
	printf("��������Ϊ%d\n", n);
	return 0;
}

int fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}
