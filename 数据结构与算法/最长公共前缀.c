#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* LCP(char** strs, int strsSize);

int main(void) {
	char** strs;
	int i = 0, len = 0, n;
	printf("请输入字符串个数：");
	scanf("%d", &n);
	strs = (char**)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++) {
		strs[i] = (char*)malloc(sizeof(char) * 100);
		printf("请输入字符串%d：", i + 1);
		scanf("%s", strs[i]);
	}
	printf("最长公共前缀为：%s\n", LCP(strs, n));
	return 0;
}

char* LCP(char** strs, int strsSize) {
	if (strsSize == 0)
		return "";
	if (strsSize == 1)
		return strs[0];
	int i, j, len = strlen(strs[0]);
	for (i = 0; i < len; i++)
		for (j = 1; j < strsSize; j++)
			if (strs[0][i] != strs[j][i])
				strs[0][i] = '\0';
	return strs[0];
}