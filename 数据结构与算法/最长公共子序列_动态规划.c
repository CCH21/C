/* 最长公共子序列动态规划解法
 * 设有一记录中间结果的二维数组num
 * 最长公共子序列的长度为num[i][j]
 * 则有：
 * num[i][j] =
 *     0                            , i = 0或j = 0;
 *     1 + num[i-1][j-1]            , i,j > 0, a[i] = b[j];
 *     max{num[i][j-1], num[i-1][j]}, i,j > 0, a[i] != b[j].
 */

#include <stdio.h>
#include <string.h>

char strA[100], strB[100];
int num[101][101] = { 0 };                       /* 记录中间结果的二维数组 */

void LCS(int lenA, int lenB);

int main(void) {
    printf("请输入两个字符串：\n");
    scanf("%s", strA);
    scanf("%s", strB);
    int lenA = strlen(strA), lenB = strlen(strB);
    LCS(lenA, lenB);
    printf("最长公共子序列的长度为%d\n", num[lenA][lenB]);
    return 0;
}

void LCS(int lenA, int lenB) {
    int i, j;
    for (i = 1; i <= lenA; i++)
        for (j = 1; j <= lenB; j++)
            if (strA[i - 1] == strB[j - 1])
                num[i][j] = num[i - 1][j - 1] + 1;
            else
                num[i][j] = num[i][j - 1] > num[i - 1][j] ? num[i][j - 1] : num[i - 1][j];
}