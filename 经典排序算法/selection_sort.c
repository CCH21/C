#include <stdio.h>

#define N 100
int main (void)
{
    int x;
    int nums[N];
    printf ("�������������е�����������");
    scanf ("%d", &x);
    int a;
    for (a = 0; a < x; a++)
        scanf ("%d", &nums[a]);

    int i, j, t;
    for (i = 0; i < x; i++)
    {
        int min = i;
        for (j = i + 1; j < x; j++)
        {
            if (nums[j] < nums[min])
                min = j;
        }
        t = nums[i];
        nums[i] = nums [min];
        nums[min] = t;
    }

    for (a = 0; a < x; a++)
        printf ("%d ", nums[a]);

    return 0;
}