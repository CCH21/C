#include <stdio.h>
#define N 128

int stringLength(char *str);
int main(void)
{
	char string[N] = {0};
	printf("������һ���ַ�����");
	gets(string);
	printf("�ַ����ĳ���Ϊ%d\n", stringLength(string));
	return 0;
}

int stringLength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
