#include <stdio.h>
#define N 128

int stringLength(char *str);
int main(void)
{
	char string[N] = {0};
	printf("请输入一个字符串：");
	gets(string);
	printf("字符串的长度为%d\n", stringLength(string));
	return 0;
}

int stringLength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
