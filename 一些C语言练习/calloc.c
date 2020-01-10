#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(char[26])            /* 定义的值为26个字符的字符数组所占内存长度 */
int main(void)
{
    int i;                              /* 循环变量i */
    char *ch1 = (char *)calloc(26, sizeof(char));
    /* 使用calloc动态分配一个长度为26字符的字符数组 */
    char *ch2 = (char *)malloc(LEN);
    /* 使用malloc动态分配一个长度为26字符的字符数组 */
    for (i = 0; i < 26; i++)            /* 为两个字符数组赋值 */
    {
        ch1[i] = 65 + i;                /* ch1是大写字符数组 */
        ch2[i] = 97 + i;                /* ch2是小写字符数组 */
    }
    printf("26个大写字母：\n");
    for (i = 0; i < 26; i++)            /* 打印大写字母 */
    {
        printf("%c", ch1[i]);
        if (i == 12 || i == 25)         /* 控制格式，输出换行 */
            printf("\n");
    }
    printf("26个小写字母：\n");           /* 打印小写字母 */
    for (i = 0; i < 26; i++)
    {
        printf("%c", ch2[i]);
        if (i == 12 || i == 25)         /* 控制格式，输出换行 */
            printf("\n");
    }
    return 0;
}