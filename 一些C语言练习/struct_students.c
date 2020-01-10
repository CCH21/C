#include <stdio.h>

struct date
{
    int year;
    int month;
    int day;
};

struct student
{
    char num[9];
    char name[21];
    char sex[6];
    int age;
    struct date birthday;
    int score[3];
    float aver;
};

int main(void)
{
    struct student stu;
    int i;
    int sum;
    sum = 0;
    printf("Please input the information:\n");
    printf("Please input num:");
    scanf("%s", &stu.num);
    printf("Please input name:");
    scanf("%s", &stu.name);
    printf("Please input sex:");
    scanf("%s", &stu.sex);
    printf("Please input age:");
    scanf("%d", &stu.age);
    printf("Please input birthday:");
    scanf("%d%d%d", &stu.birthday.year, &stu.birthday.month, &stu.birthday.day);
    printf("Please input scores:");
    for (i = 0; i < 3; i++)         /* 循环输入该学生的三门成绩 */
        scanf("%d", &stu.score[i]);
    for (i = 0; i < 3; i++)         /* 计算该学生的三门成绩的总和 */
        sum += stu.score[i];
    stu.aver = sum / 3.0;           /* 计算该学生的三门成绩的平均值 */
    printf("\nThe information is:");
    printf("\nThe num is %s", stu.num);
    printf("\nThe name is %s", stu.name);
    printf("\nThe sex is %s", stu.sex);
    printf("\nThe age is %d", stu.age);
    printf("\nThe birthday is %02d-%02d-%02d", stu.birthday.year, stu.birthday.month, stu.birthday.day);
    printf("\nThe score is ");
    for (i = 0; i < 3; i++)
        printf("%d ", stu.score[i]);
    printf("\nThe aver is %.2f\n", stu.aver);
    return 0;
}