#include <stdio.h>
#include <string.h>

int main(void)
{
	int str1Len, str2Len, i, j, k;
	int count = 0;
	char str1[100], str2[100];
	printf("ÇëÊäÈëÄ¸×Ö·û´®£º");
	gets(str1);
	printf("ÇëÊäÈë×Ó×Ö·û´®£º");
	gets(str2);
	str1Len = strlen(str1);
	str2Len = strlen(str2);
	for (i = 0; i <= str1Len - str2Len; i++)
	{
		for (j = 0, k = i; j < str2Len && str2[j] == str1[k]; j++, k++);
			if (j == str2Len)
				count++;
	}
	printf("%d\n", count);
	return 0;
}
