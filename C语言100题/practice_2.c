#include <stdio.h>

int main(void)
{
	float i, r;
	printf("请输入净利润：");
	scanf("%f", &i);
	float r1, r2, r3, r4, r5;
	r1 = 100000 * 0.1;
	r2 = r1 + 100000 * 0.075;
	r3 = r2 + 200000 * 0.05;
	r4 = r3 + 200000 * 0.03;
	r5 = r4 + 400000 * 0.015;
	if (i <= 100000)
		r = i * 0.1;
	else if (i <= 200000)
		r = r1 + (i - 100000) * 0.075;
	else if (i <= 400000)
		r = r2 + (i - 200000) * 0.05;
	else if (i <= 600000)
		r = r3 + (i - 400000) * 0.03;
	else if (i <= 1000000)
		r = r4 + (i - 600000) * 0.015;
	else
		r = r5 + (i - 1000000) * 0.01;
	printf("奖金总数为：%.2f元\n", r);
	return 0;
}
