#include <stdio.h>

int main(void)
{
	// 先使 a 右移 4 位
	// 设置一个低 4 位全为 1，其余全为 0 的数，即 ~(~0 << 4)
	// 将上面两者进行 & 运算 
    unsigned a, b, c, d;
    printf("请输入整数：\n");
    scanf("%o", &a);
    b = a >> 4;
    c = ~(~0 << 4);
    d = b & c;
    printf("%o\n%o\n", a, d);
    return 0;
}
