#include <stdio.h>

int main(void)
{
	char i, j;
	printf("请输入小写首字母：");
	scanf("%c", &i);
	getchar();
	switch(i)
	{
		case 'm':
			printf("Monday\n");
			break;
		case 'w':
			printf("Wednesday\n");
			break;
		case 'f':
			printf("Friday\n");
			break;
		case 't':
			printf("请输入下一个小写字母：");
			scanf("%c", &j);
			if (j == 'u')
				printf("Tuesday\n");
			else if (j == 'h')
				printf("Thursday\n");
			else
				printf("Error!\n");
			break;
		case 's':
			printf("请输入下一个小写字母：");
			scanf("%c", &j);
			if (j == 'a')
				printf("Saturday\n");
			else if (j == 'u')
				printf("Sunday\n");
			else
				printf("Error!\n");
			break;
		default:
			printf("Error!\n");
	}
	return 0;
}
