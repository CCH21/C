#include <stdio.h>

int main(void)
{
	float h = 100, s = 100;
    h /= 2;
    for(int i = 2; i <= 10; i++)
    {
        s = s + 2 * h;
        h /= 2;
    }
    printf("��10�����ʱ������%f��\n", s);
    printf("��10�η�����%f��\n", h);
    return 0;
}
