#include <stdio.h>

int main(void)
{
	char c;
	int letter = 0, space = 0, digit = 0, other = 0;
	printf("请输入一个字符串：");
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			letter++;
		else if (c == ' ')
			space++;
		else if (c >= '0' && c <= '9')
			digit++;
		else
			other++;
	}
	printf("字母的个数为：%d\n", letter);
	printf("空格的个数为：%d\n", space);
	printf("数字的个数为：%d\n", digit);
	printf("其他字符的个数为：%d\n", other);
	return 0;
}
