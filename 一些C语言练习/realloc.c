#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    short *s;
    double *f = (double *)malloc(sizeof(double));
    printf("ָ��fָ���ڴ�ռ����ʼ��ַ��%d\n", f);
    printf("ָ��fָ���ڴ�ռ�Ĵ�С��%d�ֽ�\n", sizeof(*f));
    s = (short *)realloc(f, sizeof(short));
    printf("ָ��sָ���ڴ�ռ����ʼ��ַ��%d\n", s);
    printf("ָ��sָ���ڴ�ռ�Ĵ�С��%d�ֽ�\n", sizeof(*s));
}