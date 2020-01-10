#include <stdio.h>
 
void swap(int *s1, int *s2);
int main(void)
{
    int a, b, c;
    int *p1, *p2, *p3;
    printf("请输入3个数：");
    scanf("%d %d %d", &a, &b, &c);
    p1 = &a;
    p2 = &b;
    p3 = &c;
    if (a > b)
        swap(p1, p2);
    if (a > c)
        swap(p1, p3);
    if (b > c)
        swap(p2, p3);
    printf("从小到大的顺序为：%d %d %d\n", a, b, c);
    return 0;
}
void swap(int *s1, int *s2)
{
    int t = *s1;
	*s1 = *s2;
	*s2 = t;
}
