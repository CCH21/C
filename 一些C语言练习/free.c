#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *pInt;
    pInt = (int *)malloc(sizeof(pInt));
    *pInt = 100;
    printf("%d\n", *pInt);
    free(pInt);
    printf("%d\n", *pInt);
    return 0;
}