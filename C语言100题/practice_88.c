#include <stdio.h>
#include <string.h>
#define N 100

int main(void)
{
	char str1[N], str2[N];
	scanf("%s", str1);
	scanf("%s", str2);
	const int x = strlen(str1), y = strlen(str2);
	int dp[x][y];
	int i, j, maxLen = 0;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			dp[i][j] = 0;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > maxLen)
						maxLen = dp[i][j];
				}
			}
			else
				dp[i][j] == 0;
		}	
	printf("%d\n", maxLen);
	return 0;
}
