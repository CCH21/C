#include <stdio.h>
#define N 100

void quick_sort(int* a, int n);

int main(void) {
    int a[N] = {0}; 
    int n, i;
    printf("请输入待排序的数组长度：");
    scanf("%d", &n);
    printf("请输入%d个数字：\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    quick_sort(a, n); 
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}

void quick_sort(int* a, int n) {
    int i, j, p, tmp;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1; ; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    quick_sort(a, i); 
    quick_sort(a + i, n - i); 
}