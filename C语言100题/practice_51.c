#include <stdio.h>

int main(void)
{
	int m, n;
	printf("�������������֣�");
	scanf("%d %d", &m, &n);
	if (m > n)
		printf("ǰ�ߴ�\n");
	else if (m < n)
		printf("���ߴ�\n");
	else
		printf("һ����\n");
	return 0;
}
