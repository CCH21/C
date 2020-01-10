#include <stdio.h>

void swap(int* pa, int* pb);
int main(void)
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("½»»»ºó£ºa = %d£¬b = %d\n", a, b);
    return 0;
}

void swap(int* pa, int* pb)
{
    int t;
    t = *pa;
    *pa = *pb;
    *pb = t;
}
