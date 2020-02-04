#include <stdio.h>
#define N 100

int findStr(char *str1, char *str2);
int main(void)
{
	int flag;
	char str1[N], str2[N];
	scanf("%s", str1);
	scanf("%s", str2);
	flag = findStr(str1, str2);
	if (flag != -1)
		printf("%d\n", flag);
	else
		printf("Not found\n");
	return 0;
}

int findStr(char *str1, char *str2)
{
	int i, j, flag = -1;
	for (i = 0, j = 0; str1[i]; i++)
	{
		while (str1[i] == str2[j] && str1[i] && str2[j])
		{
			i++;
			j++;
			if (!str2[j])
			{
				flag = i - j;
				return flag;
			}
		}
		j = 0;
	}
	return flag;
}
