/* ��Ŀ������
 * ���Ĵ���ָ��������ͬ���ַ���������abba
 * ��һ����С��1000���ַ�����ɾ�����ٵ��ַ�ʹ�ø��ַ�����Ϊ���Ĵ�
 * ���磺agddgca��ɾ��1���ַ������ַ�c���Ϳ������һ�����Ĵ�
 * ��Ŀ������
 * 1.�Ƚ��ַ�����������
 * 2.�������ַ����������������
 * 3.���ַ����ĳ��ȼ�ȥ����������м��õ����
 */

#include <stdio.h>
#include <string.h>

char strA[100], strB[100];
int num[101][101] = { 0 };                       /* ��¼�м����Ķ�ά���� */

void reverse_str(char* str);                     /* ���ַ����������� */
void LCS(int lenA, int lenB);                    /* �����ַ���������������� */

int main(void) {
    printf("�������ַ�����");
    scanf("%s", strA);
    int lenA = strlen(strA), i, j;
    strcpy(strB, strA);
    reverse_str(strB);
    int lenB = lenA;
    LCS(lenA, lenB);
    printf("Ӧɾȥ%d���ַ�ʹ���Ϊ���Ĵ�\n", lenA - num[lenA][lenB]);
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