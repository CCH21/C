#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ch;
	if ((fp = fopen("test.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	printf("������һ���ַ�������Ӣ��'!'������");
	while (1)
	{
		ch = getchar();
		if (ch == '!')
			break;
		if (ch > 96 && ch < 123)
			ch = ch - 32;
		fputc(ch, fp);
	}
	fclose(fp);
	return 0;
}
