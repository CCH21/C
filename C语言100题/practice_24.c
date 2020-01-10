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
    printf("第10次落地时共经过%f米\n", s);
    printf("第10次反弹高%f米\n", h);
    return 0;
}
