/* 最长公共子序列递归解法
 * 思路：
 * 当数组a和b对应位置字符相同时，则直接求解下一个位置
 * 否则取两种情况中的较大数值
 */

#include <stdio.h>
#include <string.h>

char strA[100], strB[100];
int lenA, lenB;

int LCS(int i, int j);

int main(void) {
    printf("请输入两个字符串：\n");
    scanf("%s", strA);
    scanf("%s", strB);
    lenA = strlen(strA);
    lenB = strlen(strB);
    printf("最长公共子序列的长度为%d\n", LCS(0, 0));
    return 0;
}

int LCS(int i, int j) {
    if (i >= lenA || j >= lenB)
        return 0;
    if (strA[i] == strB[j])
        return 1 + LCS(i + 1, j + 1);
    else
        return LCS(i + 1, j) > LCS(i, j + 1) ? LCS(i + 1, j) : LCS(i, j + 1);
}