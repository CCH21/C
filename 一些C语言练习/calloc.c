#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(char[26])            /* �����ֵΪ26���ַ����ַ�������ռ�ڴ泤�� */
int main(void)
{
    int i;                              /* ѭ������i */
    char *ch1 = (char *)calloc(26, sizeof(char));
    /* ʹ��calloc��̬����һ������Ϊ26�ַ����ַ����� */
    char *ch2 = (char *)malloc(LEN);
    /* ʹ��malloc��̬����һ������Ϊ26�ַ����ַ����� */
    for (i = 0; i < 26; i++)            /* Ϊ�����ַ����鸳ֵ */
    {
        ch1[i] = 65 + i;                /* ch1�Ǵ�д�ַ����� */
        ch2[i] = 97 + i;                /* ch2��Сд�ַ����� */
    }
    printf("26����д��ĸ��\n");
    for (i = 0; i < 26; i++)            /* ��ӡ��д��ĸ */
    {
        printf("%c", ch1[i]);
        if (i == 12 || i == 25)         /* ���Ƹ�ʽ��������� */
            printf("\n");
    }
    printf("26��Сд��ĸ��\n");           /* ��ӡСд��ĸ */
    for (i = 0; i < 26; i++)
    {
        printf("%c", ch2[i]);
        if (i == 12 || i == 25)         /* ���Ƹ�ʽ��������� */
            printf("\n");
    }
    return 0;
}