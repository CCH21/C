#include <stdio.h>

int main(void)
{
	// ��ʹ a ���� 4 λ
	// ����һ���� 4 λȫΪ 1������ȫΪ 0 �������� ~(~0 << 4)
	// ���������߽��� & ���� 
    unsigned a, b, c, d;
    printf("������������\n");
    scanf("%o", &a);
    b = a >> 4;
    c = ~(~0 << 4);
    d = b & c;
    printf("%o\n%o\n", a, d);
    return 0;
}
