/* ����������ж�̬�滮�ⷨ
 * ����һ��¼�м����Ķ�ά����num
 * ����������еĳ���Ϊnum[i][j]
 * ���У�
 * num[i][j] =
 *     0                            , i = 0��j = 0;
 *     1 + num[i-1][j-1]            , i,j > 0, a[i] = b[j];
 *     max{num[i][j-1], num[i-1][j]}, i,j > 0, a[i] != b[j].
 */

#include <stdio.h>
#include <string.h>

char strA[100], strB[100];
int num[101][101] = { 0 };                       /* ��¼�м����Ķ�ά���� */

void LCS(int lenA, int lenB);

int main(void) {
    printf("�����������ַ�����\n");
    scanf("%s", strA);
    scanf("%s", strB);
    int lenA = strlen(strA), lenB = strlen(strB);
    LCS(lenA, lenB);
    printf("����������еĳ���Ϊ%d\n", num[lenA][lenB]);
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