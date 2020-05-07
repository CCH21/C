/* 题目描述：
 * 回文串是指正反都相同的字符串，比如abba
 * 有一长度小于1000的字符串，删除最少的字符使得该字符串成为回文串
 * 例如：agddgca，删除1个字符（即字符c）就可以组成一个回文串
 * 题目分析：
 * 1.先将字符串倒序排列
 * 2.求两个字符串的最长公共子序列
 * 3.用字符串的长度减去最长公共子序列即得到结果
 */

#include <stdio.h>
#include <string.h>

char strA[100], strB[100];
int num[101][101] = { 0 };                       /* 记录中间结果的二维数组 */

void reverse_str(char* str);                     /* 将字符串倒序排列 */
void LCS(int lenA, int lenB);                    /* 两个字符串的最长公共子序列 */

int main(void) {
    printf("请输入字符串：");
    scanf("%s", strA);
    int lenA = strlen(strA), i, j;
    strcpy(strB, strA);
    reverse_str(strB);
    int lenB = lenA;
    LCS(lenA, lenB);
    printf("应删去%d个字符使其成为回文串\n", lenA - num[lenA][lenB]);
    return 0;
}

void reverse_str(char* str) {
    char* p = NULL, * q = NULL, tmp = 0;
    p = str;
    q = str;
    while (*(++q) != '\0');
    q--;
    while (p < q) {
        tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
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