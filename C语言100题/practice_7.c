#include <stdio.h>

int main(void)
{
	int ori[5] = {1, 2, 3, 4, 5};
	int cpy[5];
	int i;
	printf("ԭ����Ϊ��");
	for (i = 0; i < 5; i++)
	{
		printf("%-2d", ori[i]);
		cpy[i] = ori[i];
	}
	printf("\n���ƺ������Ϊ��");
	for (i = 0; i < 5; i++)
		printf("%-2d", cpy[i]);
	printf("\n");
	return 0;
}
