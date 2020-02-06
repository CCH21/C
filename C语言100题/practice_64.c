#include<stdio.h>
#define N 30

int main(void)
{
    int i, j = 0, k = 0, n;
    int a[N] = {0};
    printf("请输入有几个人玩游戏:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = 1;                           // 1代表留下，0代表出局
    for (i = 1; i < 4; i = i % 3 + 1)       // 控制i的值在[0，3]
    {
        if (3 == i && a[j] != 0)
        {
            a[j] = 0;						// j+1号出局 
            k++;
            if (n - 1 == k)
            	break;
            j = (j + 1) % n;
            continue;
        }
        if (a[j] == 0)
        {
            j = (j + 1) % n;
            i--;
            continue; 
        }
        j = (j + 1) % n;
    }        
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
        printf("%d\n", i + 1);
    }
}
