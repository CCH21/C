#include <stdio.h>

int len(char *str);
int main(void)
{
	char a[100] = {0};
	printf("�������ַ�����");
	gets(a);
	int length = len(a);
	printf("�ַ����ĳ���Ϊ��%d\n", length);
	return 0;
}

int len(char *str)
{
	int length = 0;
	for (; *str != '\0'; str++)
		length++;
	return length;
}
