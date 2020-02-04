#include <stdio.h>
#include <string.h>

int fun(char *s);
int main(void)
{
	char s[100];
	scanf("%s", s);
	printf("%d\n", fun(s));
	return 0;
}

int fun(char *s)
{
	int table[26] = {0};
	int i;
	int len = strlen(s);
	for (i = 0; i < len; i++)
		table[s[i] - 'a']++;
	for (i = 0; i < len; i++)
		if (table[s[i] - 'a'] == 1)
			return i;
	return -1;
}
