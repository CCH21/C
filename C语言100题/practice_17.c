#include <stdio.h>

int main(void)
{
	int score;
	printf("�����������");
	scanf("%d", &score);
	if (score > 100 || score < 0)
		printf("������ķ�����Ч��");
	else
	{
		if (score >= 90)
			printf("��ĳɼ�ΪA\n");
		else if (score >= 60)
			printf("��ĳɼ�ΪB\n");
		else
			printf("��ĳɼ�ΪC\n"); 
	}
	return 0;
}
