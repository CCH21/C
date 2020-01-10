#include <stdio.h>

int main(void)
{
	int score;
	printf("请输入分数：");
	scanf("%d", &score);
	if (score > 100 || score < 0)
		printf("你输入的分数无效！");
	else
	{
		if (score >= 90)
			printf("你的成绩为A\n");
		else if (score >= 60)
			printf("你的成绩为B\n");
		else
			printf("你的成绩为C\n"); 
	}
	return 0;
}
