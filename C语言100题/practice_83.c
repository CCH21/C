#include <stdio.h>

int main(void)
{
	FILE *fp;
	char ch;
	if ((fp = fopen("practice_83.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return -1;
	}
	while ((ch = getchar()) != '#')
	{
		fputc(ch, fp);
		putchar(ch);
	}
	fclose(fp);
	return 0;
}
