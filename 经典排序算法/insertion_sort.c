#include <stdio.h>

#define N 100
int main(void)
{
    int x;
    int nums[N];
    printf("�������������е�����������");
    scanf("%d", &x);
    int a;
    for (a = 0; a < x; a++)
        scanf("%d", &nums[a]);

    int i, j, t;
    for (i = 1; i < x; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (nums[j] < nums[j - 1])
            {
                t = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = t;
            }
            else
                break;
        }
    }

    for (a = 0; a < x; a++)
        printf("%d ", nums[a]);

    return 0;
}