#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void swap(char *str1, char *str2);
int main(void)
{
    char str1[20], str2[20], str3[20];
    printf("������3���ַ�����\n");
    fgets(str1, (sizeof str1 / sizeof str1[0]), stdin);
    fgets(str2, (sizeof str2 / sizeof str2[0]), stdin);
    fgets(str3, (sizeof str3 / sizeof str3[0]), stdin);
    if (strcmp(str1, str2) > 0)
		swap(str1, str2);
    if (strcmp(str2, str3) > 0)
		swap(str2, str3);
    if (strcmp(str1, str2) > 0)
		swap(str1, str2);
    printf("�����Ľ��Ϊ��\n");
    printf("%s%s%s\n", str1, str2, str3);
    return 0;
}
void swap(char *str1,char *str2)
{
    char temp[20];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
