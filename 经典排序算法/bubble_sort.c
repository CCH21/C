#include <stdio.h>
#define N 100
int main(void)
{
    int x;
    int nums[N];
    printf("请输入你想排列的整数个数：");
    scanf("%d", &x);
    int a;
    for (a = 0; a < x; a++)
        scanf("%d", &nums[a]);

    int i, j, t;
    for (i = 0; i < x - 1; i++)
    {
        for (j = 0; j < x - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
            }
        }
    }

    for (a = 0; a < x; a++)
        printf("%d ", nums[a]);

    return 0;
}