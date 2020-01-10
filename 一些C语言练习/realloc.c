#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    short *s;
    double *f = (double *)malloc(sizeof(double));
    printf("指针f指向内存空间的起始地址：%d\n", f);
    printf("指针f指向内存空间的大小：%d字节\n", sizeof(*f));
    s = (short *)realloc(f, sizeof(short));
    printf("指针s指向内存空间的起始地址：%d\n", s);
    printf("指针s指向内存空间的大小：%d字节\n", sizeof(*s));
}