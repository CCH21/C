#include <stdio.h>

int main(void)
{
	int num, a, b, c, d, temp;
	printf("���������ǰ����λ���֣�");
	scanf("%d", &num);
	a = num / 1000;
	b = num % 1000 / 100;
	c = num % 100 / 10;
	d = num % 10;
	a = (a + 5) % 10;
	b = (b + 5) % 10;
	c = (c + 5) % 10;
	d = (d + 5) % 10;
	temp = d;
	d = a;
	a = temp;
	temp = c;
	c = b;
	b = temp;
	printf("���ܺ������Ϊ��%d%d%d%d\n", a, b, c, d);
	return 0;
}
