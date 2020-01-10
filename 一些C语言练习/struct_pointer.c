#include <stdio.h>
typedef struct person
{
    int num;
    char name[21];
    int s[3];
    float aver;
}PERSON;

void Input(PERSON *p)
{
    scanf("%d%s%d%d%d", &p->num, &p->name, &p->s[0], &p->s[1], &p->s[2]);
    p -> aver = (p->s[0] + p->s[1] + p->s[2]) / 3.0;
}

int main(void)
{
    PERSON st;
    printf("Please input information\n");
    Input(&st);
    printf("\nThe information is:\n");
    printf("%d\t%s\t%d %d %d %5.2f\n", st.num, st.name, st.s[0], st.s[1], st.s[2], st.aver);
    return 0;
}