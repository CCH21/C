#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ch;
	if ((fp = fopen("test.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	printf("请输入一个字符串，以英文'!'结束：");
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
