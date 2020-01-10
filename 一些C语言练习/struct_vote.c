#include <stdio.h>
#include <string.h>

struct person
{
    char name[20];
    int count;
};

int main(void)
{
    struct person t;
    struct person leader[3] = {"A", 0, "B", 0, "C", 0};
    int i, j, k;
    int n = 3;
    int m;
    char name[20];
    printf("Please input count of votes:");
    scanf("%d", &m);
    printf("Please input the election's name:\n");
    for (i = 1; i <= m; i++)
    {
        printf("No.%d:", i);
        scanf("%s", name);
        for (j = 0; j < 3; j++)
            if (strcmp(name, leader[j].name) == 0)
                leader[j].count++;
    }
    for (i = 0; i < n - 1;  i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (leader[k].count < leader[j].count)
                k = j;
        if (k != i)
        {
            t = leader[i];
            leader[i] = leader[k];
            leader[k] = t;
        }
    }
    printf("The vote of leader is:\n");
    for (i = 0; i <n; i++)
        printf("%s\t%d\n", leader[i].name, leader[i].count);
    return 0;
}