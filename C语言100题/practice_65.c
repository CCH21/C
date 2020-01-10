#include <stdio.h>

int len(char *str);
int main(void)
{
	char a[100] = {0};
	printf("请输入字符串：");
	gets(a);
	int length = len(a);
	printf("字符串的长度为：%d\n", length);
	return 0;
}

int len(char *str)
{
	int length = 0;
	for (; *str != '\0'; str++)
		length++;
	return length;
}
