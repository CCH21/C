/* ����������еݹ�ⷨ
 * ˼·��
 * ������a��b��Ӧλ���ַ���ͬʱ����ֱ�������һ��λ��
 * ����ȡ��������еĽϴ���ֵ
 */

#include <stdio.h>
#include <string.h>

char strA[100], strB[100];
int lenA, lenB;

int LCS(int i, int j);

int main(void) {
    printf("�����������ַ�����\n");
    scanf("%s", strA);
    scanf("%s", strB);
    lenA = strlen(strA);
    lenB = strlen(strB);
    printf("����������еĳ���Ϊ%d\n", LCS(0, 0));
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