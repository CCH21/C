#include <stdio.h>

void string_concatenation(char str1[], char str2[]);
int main(void)
{
    char string1[40], string2[40];
    scanf("%s", string1);
    scanf("%s", string2);
    string_concatenation(string1, string2);
    printf("%s", string1);
    return 0;
}

void string_concatenation(char str1[], char str2[])
{
    int i, j;
    for (i = 0; str1[i] != '\0'; i++);
    for (j = 0; str2[j] != '\0'; i++, j++)
        str1[i] = str2[j];
    str1[i] = '\0';
}
