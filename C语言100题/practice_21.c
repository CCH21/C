#include <stdio.h>

int main(void)
{
	char c;
	int letter = 0, space = 0, digit = 0, other = 0;
	printf("������һ���ַ�����");
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
	printf("��ĸ�ĸ���Ϊ��%d\n", letter);
	printf("�ո�ĸ���Ϊ��%d\n", space);
	printf("���ֵĸ���Ϊ��%d\n", digit);
	printf("�����ַ��ĸ���Ϊ��%d\n", other);
	return 0;
}
